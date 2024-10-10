#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include <cmath>

using namespace std;

class Point2D {
    public:
        float x = 0;
        float y = 0;
        Point2D(float x1, float y1) {
            this->x = x1;
            this->y = y1;
        }
};
class Point {
    public:
        float x = 0;
        float y = 0;
        float z = 0;
        bool is_3D_vector = false;
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

        Line(float a, float b, float c, float x_0, float y_0, float z_0) {
            this->a = a;
            this->b = b;
            this->c = c;
            this->x_0 = x_0;
            this->y_0 = y_0;
            this->z_0 = z_0;
        }

        Line(const Point &p1, const Point &p2) {
            this->a = p2.x - p1.x;
            this->b = p2.y - p1.y;
            this->c = p2.z - p1.z;
            this->x_0 = p1.x;
            this->y_0 = p1.y;
            this->z_0 = p1.z;
        }
};

Point intersection_Plane_Line(Plane p, Line l){
    float denominator = p.a * l.a + p.b * l.b + p.c * l.c;
    if (denominator == 0) {
        throw runtime_error("The line is parallel to the plane, no intersection.");
    }
    float numerator = -(p.a * l.x_0 + p.b * l.y_0 + p.c * l.z_0 + p.d);
    float t = numerator / denominator;
    float x = l.x_0 + t * l.a;
    float y = l.y_0 + t * l.b;
    float z = l.z_0 + t * l.c;
    return Point(x, y, z);
}
Point orthogonal_projection(const Point &point,const Plane &plane){
    Line *normal_line = new Line(plane.a,plane.b,plane.c,point.x,point.y,point.z);
    Point orthogonal_projection_point = intersection_Plane_Line(plane,*normal_line);
    delete normal_line;
    normal_line = nullptr;
    return orthogonal_projection_point;
}

Point unit_vector_transformer(const Point &vect){
    float scalar_vect = sqrt(pow(vect.x,2)+pow(vect.y,2)+pow(vect.z,2));
    return Point(vect.x/scalar_vect,vect.y/scalar_vect,vect.z/scalar_vect);
}

Point cross_Product_3D_vector(const Point &vect1,const Point &vect2){
    return Point(vect1.x*vect2.y-vect2.x*vect1.y,-(vect1.x*vect2.z-vect2.x*vect1.z),vect1.y*vect2.z-vect2.y*vect1.z);
}

Point2D retranspose_3D_system_into_2D(const Point &I, const Point &J, const Point &P,const Point &O) {
    float a,b;
    if((J.x-O.x != 0 || I.x-O.x != 0 ) &&  (J.y-O.y != 0 || I.y-O.y != 0 )){
        if(J.x-O.x == 0){
            a = (P.x - O.x)/(I.x - P.x);
            // b = 
        }else{
            a = (P.y - O.y - (P.x - O.x) * (J.y - O.y) / (J.x - O.x)) / ((I.y - O.y) - (I.x - O.x) * (J.y - O.y) / (J.x - O.x));
            b = (P.x - O.x - a * (I.x - O.x)) / (J.x - O.x);
        }
    }else if(!(J.y-O.y == 0 && I.y-O.y == 0 )){

    }else{
        throw runtime_error("Invalid transformation: the system cannot be transposed");
    }
    // Return a default Point2D if no transformation logic is added
    return Point2D(a, b);
}

#endif // GEOMETRIC_H
