
class vector3d {
  public:
    float pos_x, pos_y, pos_z;
    float dir_x, dir_y, dir_z;
    int r, g, b;

	//
	
    // Constructor logic written inline
    vector3d(vector<float> pos, vector<float> dir, vector<int> color) {
        pos_x = pos[0], pos_y = pos[1], pos_z = pos[2];
        dir_x = dir[0], dir_y = dir[1], dir_z = dir[2];
        r = color[0], g = color[1], b = color[2];
    }

	vector3d(): vector3d({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0, 0, 0}){}

    vector3d add_vectors(vector3d v1, vector3d v2) {
        vector3d v3({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0, 0, 0});
		// Add Directions
        v3.dir_x = v1.dir_x + v2.dir_x;
        v3.dir_y = v1.dir_y + v2.dir_y;
        v3.dir_z = v1.dir_z + v2.dir_z;

		// Add Positions
        v3.pos_x = v1.pos_x + v2.pos_x;
        v3.pos_y = v1.pos_y + v2.pos_y;
        v3.pos_z = v1.pos_z + v2.pos_z;

        // Add Colors 
        // Note: If you are doing strict RGB, you might want to wrap these 
        // in an if-statement or std::min() to ensure they don't exceed 255.
        v3.r = v1.r + v2.r;
        v3.g = v1.g + v2.g;
        v3.b = v1.b + v2.b;

        // Return the final combined object
        return v3;
    }

	void print() {
        cout << "Position: (" << pos_x << ", " << pos_y << ", " << pos_z << ") | ";
        cout << "Direction: (" << dir_x << ", " << dir_y << ", " << dir_z << ") | ";
        cout << "RGB: (" << r << ", " << g << ", " << b << ")\n";
    }
};

class ray3d {
  public:
    float origin_x, origin_y, origin_z;
    float ray_dir_x, ray_dir_y, ray_dir_z;
    float t;
};
