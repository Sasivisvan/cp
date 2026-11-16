#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

#define IMG_HEIGHT 1000
#define IMG_WIDTH 1000

void save_img(vector<vector<vector<int>>> img) {
    // Create and open a text file
    ofstream myfile("sasi.ppm");

    // Write to the file
    myfile << "P3\n";
    myfile << img.size() << " " << img[0].size() << "\n";
    myfile << "255\n";

    for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[0].size(); j++) {
            myfile << img[i][j][0] << " " << img[i][j][1] << " " << img[i][j][2] << "\n";
        }
    }

    // Close the file
    myfile.close();
}

class vector3d {
  public:
    float x, y, z;

    //

    // Constructor logic written inline
    vector3d(vector<float> vals) { x = vals[0], y = vals[1], z = vals[2]; }

    vector3d() : vector3d({0.0, 0.0, 0.0}) {}

    static vector3d add(vector3d v1, vector3d v2) {
        vector3d v3({0.0, 0.0, 0.0});
        // Add Values
        v3.x = v1.x + v2.x;
        v3.y = v1.y + v2.y;
        v3.z = v1.z + v2.z;

        return v3;
    }
    static vector3d subtract(vector3d v1, vector3d v2) {
        vector3d v3({0.0, 0.0, 0.0});
        // Add Values
        v3.x = v1.x - v2.x;
        v3.y = v1.y - v2.y;
        v3.z = v1.z - v2.z;

        return v3;
    }

    vector3d scalar_multiply(float l) {
        vector3d v3({0.0, 0.0, 0.0});
        // Add Values
        v3.x = x * l;
        v3.y = y * l;
        v3.z = z * l;
        return v3;
    }

    float len() { return sqrtf(x * x + y * y + z * z); }

    vector3d unit_vector3d() {
        float l = len();
        return vector3d({x / l, y / l, z / l});
    }

    static float dot_product(vector3d v1, vector3d v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

    void print() { cout << "values: (" << x << ", " << y << ", " << z << ")\n"; }
};

class ray3d {
  public:
    vector3d origin;
    vector3d direction;

    ray3d() : ray3d(vector3d(), vector3d()) {};

    ray3d(vector3d ori, vector3d dir) {
        origin = ori;
        direction = dir;
    }

    vector3d at(float t) { return vector3d({vector3d::add(origin, direction.scalar_multiply(t))}); }
};

class camera {
  public:
    vector3d origin;
    float vp_height = 2.0;
    float vp_width = 2.0;
    float focal_length = 1.0;

    std::vector<std::vector<ray3d>> rays_grid{IMG_HEIGHT, std::vector<ray3d>(IMG_WIDTH)};

    void generate_rays() {
        for (int i = 0; i < IMG_HEIGHT; i++) {
            for (int j = 0; j < IMG_WIDTH; j++) {
                vector3d t1 = vector3d::subtract(origin, vector3d({vp_width / 2.0f, 0, 0}));
                vector3d t2 = vector3d::subtract(t1, vector3d({0, vp_height / 2, 0}));
                vector3d lower_left_corner = vector3d::subtract(t2, vector3d({0, 0, focal_length}));

                float u = j / ((IMG_HEIGHT - 1) * 1.0f);
                float v = i / ((IMG_WIDTH - 1) * 1.0f);

                vector3d pixel_point({lower_left_corner.x + u * vp_width, lower_left_corner.y + v * vp_height, lower_left_corner.z});
                // Confution here i, j or j, i -> if i, j then the sky(blue) is
                // to the right. if j, i-> sky(blue) is to the top/up
                rays_grid[i][j] = ray3d(origin, pixel_point);
            }
        }
    }
};

class sphere {
  public:
    vector3d center;
    float radius;

    sphere(vector3d cen, float r) {
        radius = r;
        center = cen;
    }

    vector3d offset(ray3d ray) { return vector3d::subtract(ray.origin, center); }

    float hit_distance(ray3d ray) {
        float a = vector3d::dot_product(ray.direction, ray.direction);
        float b = 2.0 * vector3d::dot_product(ray.direction, offset(ray));
        float c = vector3d::dot_product(offset(ray), offset(ray)) - radius * radius;
        float delta = b * b - 4 * a * c;
        float t1 = (-b + sqrt(delta)) / (2.0f * a);
        float t2 = (-b - sqrt(delta)) / (2.0f * a);
        return min(t1, t2);
    }
};

vector<int> world_condition(ray3d ray, sphere sphere1) {
    float y = ray.direction.unit_vector3d().y;

    float t = 0.5 * (y + 1.0);

    vector3d color = vector3d::add(vector3d({0, 0, 255}).scalar_multiply(1.0 - t), vector3d({255, 255, 255}).scalar_multiply(t));
    float dist = sphere1.hit_distance(ray);
    if (dist > 0) {
        vector3d P = ray.at(dist);
        vector3d normal = vector3d::subtract(P, sphere1.center).unit_vector3d();
        color = vector3d({(normal.x + 1.0f) * 0.5f * 255.0f, (normal.y + 1.0f) * 0.5f * 255.0f, (normal.z + 1.0f) * 0.5f * 255.0f});
    }

    return {(int)color.x, (int)color.y, (int)color.z};
}

int main() {

    // vector3d v1({0, 1, 2});
    // vector3d v2({0, 1, 2});
    // vector3d v4 = vector3d::add(v1, v2);
    // v4.print();
    float grow = 0.0;
    float diff = 0.5;
    while (true) {
        camera c;

        c.generate_rays();

        sphere sphere1(vector3d({0, 0, -15}), grow);
        grow = grow + diff;
        // sphere sphere2(vector3d({0, 0, -5}), 0.5);
        // sphere sphere3(vector3d({-1, 0, -7}), 3.5);

        vector<vector<vector<int>>> img(1000, vector<vector<int>>(1000, vector<int>(3, 0)));

        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {

                vector<int> rgb = world_condition(c.rays_grid[i][j], sphere1);

                img[i][j][0] = rgb[0];
                img[i][j][1] = rgb[1];
                img[i][j][2] = rgb[2];
            }
        }

        save_img(img);
        if (grow > 10)
            diff = -0.5;
        if (grow < 1)
            diff = 0.5;
        int a;
        cin >> a;
    }
}