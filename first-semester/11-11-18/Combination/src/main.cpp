#include <iostream>

unsigned long long combination(unsigned int n, unsigned int m) {
    unsigned int k = n - m;
    if (m > k) {
        m = k;
    }
    if (!m) {
        return 1;
    }
    k = n - m + 1;
    unsigned long long res = k;
    k++;
    for (unsigned int i = 2; i <= m; ++i, ++k) {
        res = res / i * k + res % i * k / i;
    }
    return res;
}

int main() {
    std::cout << combination(23, 15) << std::endl;
    return 0;
}
