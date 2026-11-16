#include <iostream>
#include <cmath>
#include <limits>
#include <memory>
#include <vector>
#include <random>

using std::shared_ptr;
using std::make_shared;

// --- Constants & Utility Functions ---
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) { return degrees * pi / 180.0; }
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}
inline double random_double(double min, double max) { return min + (max - min) * random_double(); }
inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

// --- Vector Math (vec3) ---
class vec3 {
public:
    double e[3];
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    vec3& operator+=(const vec3 &v) { e[0]+=v.e[0]; e[1]+=v.e[1]; e[2]+=v.e[2]; return *this; }
    vec3& operator*=(const double t) { e[0]*=t; e[1]*=t; e[2]*=t; return *this; }
    vec3& operator/=(const double t) { return *this *= 1/t; }
    double length_squared() const { return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
    double length() const { return std::sqrt(length_squared()); }
    bool near_zero() const { const auto s = 1e-8; return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s) && (std::fabs(e[2]) < s); }
    static vec3 random() { return vec3(random_double(), random_double(), random_double()); }
    static vec3 random(double min, double max) { return vec3(random_double(min,max), random_double(min,max), random_double(min,max)); }
};

using point3 = vec3;
using color = vec3;

inline vec3 operator+(const vec3 &u, const vec3 &v) { return vec3(u.e[0]+v.e[0], u.e[1]+v.e[1], u.e[2]+v.e[2]); }
inline vec3 operator-(const vec3 &u, const vec3 &v) { return vec3(u.e[0]-v.e[0], u.e[1]-v.e[1], u.e[2]-v.e[2]); }
inline vec3 operator*(const vec3 &u, const vec3 &v) { return vec3(u.e[0]*v.e[0], u.e[1]*v.e[1], u.e[2]*v.e[2]); }
inline vec3 operator*(double t, const vec3 &v) { return vec3(t*v.e[0], t*v.e[1], t*v.e[2]); }
inline vec3 operator*(const vec3 &v, double t) { return t * v; }
inline vec3 operator/(vec3 v, double t) { return (1/t) * v; }
inline double dot(const vec3 &u, const vec3 &v) { return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2]; }
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1]*v.e[2] - u.e[2]*v.e[1], u.e[2]*v.e[0] - u.e[0]*v.e[2], u.e[0]*v.e[1] - u.e[1]*v.e[0]);
}
inline vec3 unit_vector(vec3 v) { return v / v.length(); }

vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1,1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}
vec3 random_unit_vector() { return unit_vector(random_in_unit_sphere()); }
vec3 random_in_unit_disk() {
    while (true) {
        auto p = vec3(random_double(-1,1), random_double(-1,1), 0);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}
vec3 reflect(const vec3& v, const vec3& n) { return v - 2*dot(v,n)*n; }
vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
    auto cos_theta = std::fmin(dot(-uv, n), 1.0);
    vec3 r_out_perp = etai_over_etat * (uv + cos_theta*n);
    vec3 r_out_parallel = -std::sqrt(std::fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

// --- Ray ---
class ray {
public:
    point3 orig;
    vec3 dir;
    ray() {}
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}
    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }
    point3 at(double t) const { return orig + t*dir; }
};

// --- Geometry & Materials ---
class material;

struct hit_record {
    point3 p;
    vec3 normal;
    shared_ptr<material> mat_ptr;
    double t;
    bool front_face;
    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

class sphere : public hittable {
public:
    point3 center;
    double radius;
    shared_ptr<material> mat_ptr;
    sphere(point3 cen, double r, shared_ptr<material> m) : center(cen), radius(r), mat_ptr(m) {};
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) return false;
    auto sqrtd = std::sqrt(discriminant);
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root) return false;
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;
    return true;
}

class hittable_list : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;
    hittable_list() {}
    void add(shared_ptr<hittable> object) { objects.push_back(object); }
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;
    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

// --- Materials ---
class material {
public:
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

class lambertian : public material {
public:
    color albedo;
    lambertian(const color& a) : albedo(a) {}
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
        auto scatter_direction = rec.normal + random_unit_vector();
        if (scatter_direction.near_zero()) scatter_direction = rec.normal;
        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }
};

class metal : public material {
public:
    color albedo;
    double fuzz;
    metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }
};

class dielectric : public material {
public:
    double ir;
    dielectric(double index_of_refraction) : ir(index_of_refraction) {}
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0/ir) : ir;
        vec3 unit_direction = unit_vector(r_in.direction());
        double cos_theta = std::fmin(dot(-unit_direction, rec.normal), 1.0);
        double sin_theta = std::sqrt(1.0 - cos_theta*cos_theta);
        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        vec3 direction;
        if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double()) {
            direction = reflect(unit_direction, rec.normal);
        } else {
            direction = refract(unit_direction, rec.normal, refraction_ratio);
        }
        scattered = ray(rec.p, direction);
        return true;
    }
private:
    static double reflectance(double cosine, double ref_idx) {
        auto r0 = (1-ref_idx) / (1+ref_idx);
        r0 = r0*r0;
        return r0 + (1-r0)*std::pow((1 - cosine), 5);
    }
};

// --- Camera ---
class camera {
public:
    camera(point3 lookfrom, point3 lookat, vec3 vup, double vfov, double aspect_ratio, double aperture, double focus_dist) {
        auto theta = degrees_to_radians(vfov);
        auto h = std::tan(theta/2);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;

        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(vup, w));
        v = cross(w, u);

        origin = lookfrom;
        horizontal = focus_dist * viewport_width * u;
        vertical = focus_dist * viewport_height * v;
        lower_left_corner = origin - horizontal/2 - vertical/2 - focus_dist*w;
        lens_radius = aperture / 2;
    }
    ray get_ray(double s, double t) const {
        vec3 rd = lens_radius * random_in_unit_disk();
        vec3 offset = u * rd.x() + v * rd.y();
        return ray(origin + offset, lower_left_corner + s*horizontal + t*vertical - origin - offset);
    }
private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 u, v, w;
    double lens_radius;
};

// --- Rendering Logic ---
color ray_color(const ray& r, const hittable& world, int depth) {
    hit_record rec;
    if (depth <= 0) return color(0,0,0);
    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return color(0,0,0);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

hittable_list random_scene() {
    hittable_list world;
    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());
            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;
                if (choose_mat < 0.8) {
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));
    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));
    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    return world;
}

// --- Main ---
int main() {
    // Image properties
    const auto aspect_ratio = 3.0 / 2.0;
    const int image_width = 1200;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100; // Increase for higher quality, reduce for faster render
    const int max_depth = 50;

    // World
    auto world = random_scene();

    // Camera
    point3 lookfrom(13,2,3);
    point3 lookat(0,0,0);
    vec3 vup(0,1,0);
    auto dist_to_focus = 10.0;
    auto aperture = 0.1;
    camera cam(lookfrom, lookat, vup, 20, aspect_ratio, aperture, dist_to_focus);

    // Render (Outputs to PPM format)
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width-1);
                auto v = (j + random_double()) / (image_height-1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }
            
            // Write color (with gamma correction)
            auto r = pixel_color.x();
            auto g = pixel_color.y();
            auto b = pixel_color.z();
            
            auto scale = 1.0 / samples_per_pixel;
            r = std::sqrt(scale * r);
            g = std::sqrt(scale * g);
            b = std::sqrt(scale * b);
            
            std::cout << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
                      << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
                      << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
        }
    }
    std::cerr << "\nDone.\n";
    return 0;
}