#include <iostream>
#include "weakRayCast.h"
using namespace std;

int main() {
    cout << "3D Renderer Initialized" << endl;
    WeakRayCast cast = WeakRayCast();
    cast.add_New_Point(1,2,3);
    return 0;
}