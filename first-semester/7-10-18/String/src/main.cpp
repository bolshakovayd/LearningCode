#include "String.h"

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    String str("Hello, ");
    str.print();

    String str2("world ");
    str += str2;
    str.print();

    str += "of programming!";
    str.print();

    str2 = "c-string";
    str = str2;
    str.print();
    return 0;
}
