#include "LongNumber.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

LongNumber ONE("1");
LongNumber ZERO("0");

LongNumber ackermann(LongNumber m, LongNumber n) {
    if (m == ZERO) return n + ONE;
    if (n == ZERO) return ackermann(m - ONE, ONE);
    return ackermann(m - ONE, ackermann(m, n - ONE));
}

int main() {
    LongNumber m1("4");
    LongNumber n1("0");
    LongNumber ack(ackermann(m1, n1));
    ack.print();

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            LongNumber m(std::to_string(i));
            LongNumber n(std::to_string(j));
            cout << "\nAckermann(" << i << ", " << j << ") = ";
            LongNumber ackermannNumber(ackermann(m, n));
            ackermannNumber.print();
        }
    }
    return 0;
}
