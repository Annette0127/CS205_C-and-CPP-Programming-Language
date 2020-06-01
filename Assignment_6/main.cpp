#include <iostream>
#include "box.hpp"

using namespace std;

int main() {
    Box b1;
    Box b2 = Box(100000, 100000, 100000);
    Box b3 = Box(100000, 100000, 999);
    cout << b1;
    cout << b1.getLength() << " " << b1.getBreadth() << " " << b1.getHeight()<<endl;
    cout << b2 << "Volume of b2 is:" << b2.CalculateVolume()<<endl;
    cout << b2 << b3 << "b2 is \"<\" b3:" << (bool) (b2 < b3)<<endl;
    cout << b2 << b3 << "b3 is \"<\" b2:" << (bool) (b3 < b2)<<endl;

    return 0;
}