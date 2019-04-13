#include "AugmentedMatrix.h"
#include "MatrixUtils.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // 3 4 1 2 3 4 2 4 6 8 5 4 5 4 6 3 6
    // 3 3 2 2 -1 5 4 -6 3 2 -5 0 0 0

    unsigned int cols, rows;
    cout << "\nEnter number of linear equations: ";
    cin >> rows;
    cout << "\nEnter number of unknowns: ";
    cin >> cols;
    cout << "\nConsider a system of linear equation in form Ax=b";

    AugmentedMatrix matrix(rows, cols);
    // matrix.printAll();
    // matrix.print();

    MatrixUtils::GaussianElimination(matrix);

    // for (auto i = 0; i < cols; ++i) {
    //     if (std::isinf(roots[i])) {
    //         cout << "No solutions.\t";
    //         break;
    //     } else if (std::isnan(roots[i])) {
    //         cout << "Infinite number of solutions.\t";
    //         break;
    //     } else { cout << roots[i] << "  "; }
    // }

    // TODO: fix case with infinite number of solutions
    return 0;
}
