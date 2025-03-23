#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "geometric.h"
#include <cmath>
#ifndef WEAKRAYCAST_H
#define WEAKRAYCAST_H
// #include <SDL.h>
using namespace std;
constexpr double PI = 3.14159265358979323846;

class WeakRayCast {
    public:
        double ID;
        int window_height = 100;
        int window_width = 100;
        vector<Point> data_point = {};
        bool isStatic;
        int Epocs;
        string background_color;
        string point_color;
        bool cast_initilalized = false;
        Point camera_pov,screen_center;
        float z_rotation,xy_rotation,focal_length;

        WeakRayCast(): camera_pov(0,0,0),screen_center(0,0,0){};
        WeakRayCast(double ID) : camera_pov(0, 0, 0), screen_center(0, 0, 0){
            this->ID = ID;
        }

        // initialzing Setup all the holder and specify the type of data allocation 
        void _init_(bool typeStates = true, int Epoc = 60, string background_color = "black", string point_color = "white", Point camera = Point(0,0,0), float focal_length=0, float xy_rotation=PI/4, float z_rotation=PI/2){
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
            this->camera_pov = camera;
            this->focal_length = abs(focal_length);
            this->xy_rotation = fmod(xy_rotation, 2 * PI);
            if (this->xy_rotation < 0) this->xy_rotation += 2 * PI;
            this->z_rotation = fmod(z_rotation, PI);
            if (this->z_rotation < 0) this->z_rotation += PI;
            this->screen_center = SphericalPoint(this->z_rotation + this->camera_pov.x,this->xy_rotation + this->camera_pov.y,this->focal_length + this->camera_pov.z);
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
        void add_data_point(const vector <Point> &newDataSet){
            if(isStatic){
                for(int i = 0 ; i < newDataSet.size(); i++){
                    this->data_point.push_back(newDataSet[i]); // Use a reference to avoid copying each Point
                }
            }else{
                cerr << "you cannot add a point to a dynamic based rendering" << endl;
            }
        }

        // after initialazation we need to start computing things
        void Render_3d_image(const vector<Point> &data_set){
            vector<Point> DATA_SET;
            if(isStatic){
                DATA_SET = this->data_point;
            }else{
                DATA_SET = data_set;
            }
            
        }
        

};

#endif // GEOMETRIC_H
