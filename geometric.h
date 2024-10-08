#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include <cmath>

using namespace std;
class Point {
    public:
        float x = 0;
        float y = 0;
        float z = 0;

        Point(float x1, float y1, float z1) {
            this->x = x1;
            this->y = y1;
            this->z = z1;
        }
};
class SphericalPoint: public Point {
    public:
        SphericalPoint(float z_rotation, float xy_rotation, float focal_length)
        : Point(0, 0, 0) {
            this->x = focal_length * cos(xy_rotation) * sin(z_rotation);
            this->y = focal_length * sin(xy_rotation) * sin(z_rotation);
            this->z = focal_length * cos(xy_rotation);
        }
};

class Plane{
    public:
        float a = 0;
        float b = 0;
        float c = 0;
        float d = 0;

        Plane(float a, float b, float c, float d) {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
        }
};
class Plane_normalVec_point : public Plane {
    public:
        Plane_normalVec_point(const Point &point, const Point &normal)
        :Plane(normal.x, normal.y, normal.z, -(normal.x * point.x + normal.y * point.y + normal.z * point.z)) {
                
        }
};

class Line {
    public:
        float a = 0;
        float b = 0;
        float c = 0;
        float x_0 = 0;
        float y_0 = 0;
        float z_0 = 0;

        Line(Point p1, Point p2) {
            this->a = p2.x - p1.x;
            this->b = p2.y - p1.y;
            this->c = p2.z - p1.z;
            this->x_0 = p1.x;
            this->y_0 = p1.y;
            this->z_0 = p1.z;
        }
};



#endif // GEOMETRIC_H