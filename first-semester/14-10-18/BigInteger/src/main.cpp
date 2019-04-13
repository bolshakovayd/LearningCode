#include "BigInteger.h"

#include <iostream>

using namespace std;

int main() {
    BigInteger a("4567834567890876543567863437845968529384563589123456789987654345678765456");
    BigInteger b("7654676754334553478692378407938645891246724579189476589238749634234");
    BigInteger res = karatsubaMultiplication(a, b);
    a.print();
    cout << "\n*";
    b.print();
    cout << "\n=";
    res.print();
    return 0;
}
