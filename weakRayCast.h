#ifndef WEAKRAYCAST_H
#define WEAKRAYCAST_H
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "geometric.h"
// #include <SDL.h>
using namespace std;

class WeakRayCast {
    public:
        int window_height = 100;
        int window_width = 100;
        vector<Point> data_point = {};
        bool isStatic;
        int Epocs;
        string background_color;
        string point_color;
        bool cast_initilalized = false;
        // initialzing Setup all the holder and specify the type of data allocation 
    private:
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
    void _init_(bool typeStates = true, int Epoc, string background_color = "black", string point_color = "white"){
        if(typeStates == true){
            this->data_point = {};
            this->isStatic = true;

        }else if(typeStates == false){
            this->data_point = {};
            this->isStatic = false;
        }
        this->Epocs = Epoc;
        this->background_color = background_color;
        this->point_color = point_color;
        this->cast_initilalized = true;

    }

    // creating a new windows with the setup for the weak raycasting
    void create_Window(int W_width = 100, int W_height = 100){
        window_height = W_height;
        window_width = W_width;
        // logic behind creating a window

        //
    }

        
    // add a new Point
    void add_New_Point(float x_c = 0, float y_c = 0,float z_c = 0){
        if(isStatic){
            Point *point = new Point(x_c,y_c,z_c);
            this->data_point.push_back(*point);
            delete point;
            point = nullptr;

        }else{
            cerr << "you cannot add a point to a dynamic based rendering" << endl;
        }
    }
        
    // how to add multiple points at the same time
    void add_data_point(vector <Point> newDataSet){
        if(isStatic){
            for(int i = 0 ; i < newDataSet.size(); i++){
                this->data_point.push_back(newDataSet[i]); // Use a reference to avoid copying each Point
            }
        }else{
            cerr << "you cannot add a point to a dynamic based rendering" << endl;
        }
    }

    // after initialazation we need to start computing things
    void Render(vector<Point> &data_set){ 
        // Point 3d_projection_point = this->intersection_Plane_Line();
    }

};

#endif // GEOMETRIC_H
