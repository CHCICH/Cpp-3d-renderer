#include <iostream>
#include "weakRayCast.h"
#include "geometric.h"

using namespace std;

int main() {
    cout << "3D Renderer Initialized" << endl;
    WeakRayCast cast = WeakRayCast(1231);
    cast.add_New_Point(1,2,3);
    Point P1 = Point(5,4,7);
    Point P2 = Point(1,2,4);
    Point P3 = Point(1,24,2);
    Point P4 = Point(0,0,0);
    Point2D system = retranspose_3D_system_into_2D(P1,P2,P3,P4); 
    cout << system.x << "," << system.y << endl;
    return 0;

}