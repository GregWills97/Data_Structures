#include <iostream>
#include <string>
#include "rbt.h"

using namespace std;

int main(){
    Map mymap;
    mymap.insert(1, "Hydrogen");
    mymap.insert(2, "Helium");;
    mymap.insert(3, "Lithium");
    mymap.insert(4, "Beryllium");
    mymap.insert(5, "Boron");
    mymap.insert(6, "Carbon");
    mymap.insert(7, "Nitrogen");
    mymap.insert(8, "Oxygen");
    mymap.insert(9, "Fluorine");
    Iterator it = mymap.begin();
    it.next();
    mymap.clear();
    return 0;
}
