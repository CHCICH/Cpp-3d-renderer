#include <iostream>
#include "weakRayCast.h"
using namespace std;

int main() {
    cout << "3D Renderer Initialized" << endl;
    WeakRayCast cast = WeakRayCast(1231);
    cast.add_New_Point(1,2,3);
    return 0;
}