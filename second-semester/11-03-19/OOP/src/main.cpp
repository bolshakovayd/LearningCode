#include "types.h"
#include "utils.h"
#include <algorithm>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Matrix2DUtils::instance().solve_system(std::cin, std::cout);
    return 0;
}

/*
example:
2
2
1 1
2 3
0 5
*/
