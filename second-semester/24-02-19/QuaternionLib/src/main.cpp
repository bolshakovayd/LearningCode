#include <iostream>
#include "QuaternionLib.h"

using namespace std;

int main() {
    Quaternion a(1, 2, 3, 4);
    Quaternion b(1, 5, 3, -1);
    a *= b;
    Quaternion c = a + b;
    c /= c;
    c.invert();
    c.normalize();
    c.print();

    return 0;
}
