#include "MatrixUtils.h"

#include <cmath>
#include <bits/waitflags.h>
#include <iostream>
#include <string>

void MatrixUtils::GaussianElimination(AugmentedMatrix matrix) {
    unsigned int size = matrix.getSize();

    for (int i = 0; i < size; i++) {
        // Search for maximum in this column
        double maxElement = std::abs(matrix.data[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < size; k++) {
            if (std::abs(matrix.data[k][i]) > maxElement) {
                maxElement = std::abs(matrix.data[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k < size + 1; k++) {
            double tmp = matrix.data[maxRow][k];
            matrix.data[maxRow][k] = matrix.data[i][k];
            matrix.data[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < size; k++) {
            double c = -matrix.data[k][i] / matrix.data[i][i];
            for (int j = i; j < size + 1; j++) {
                if (i == j) {
                    matrix.data[k][j] = 0;
                } else {
                    matrix.data[k][j] += c * matrix.data[i][j];
                }
            }
        }
    }
    matrix.printAll();
    matrix.print();

    // Solve equation Ax=b for an upper triangular data A

    unsigned int cols = matrix.getCols();
    unsigned int rows = matrix.getRows();

    // check for compatibility
    bool flag = false;
    for (int i = size - 1; i >= 0; --i) {
        for (int j = 0; j <= size; ++j) {
            double curEl = matrix.data[i][j];
            if (j == size && curEl != 0 && !std::isnan(curEl) && !std::isinf(curEl)) {
                std::cout << "\nTHIS SYSTEM IS UNCOMPATIBLE.";
                return;
            } else if (curEl != 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    } //3 3 1 2 3 4 5 6 7 8 9 3 6 3

    // find number of free and basic variables
    flag = false;
    unsigned int freeV;
    unsigned int basicV;

    for (auto i = size - 1; i >= 0; --i) {
        for (auto j = 0; j < size; ++j) {
            double curEl = matrix.data[i][j];
            if (curEl != 0 && !std::isnan(curEl) && !std::isinf(curEl)) {
                flag = true;
                freeV = size - 1 - j;
                basicV = j + 1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    if (freeV == 0) {
        double *roots = new double[size];
        for (int i = size - 1; i >= 0; i--) {
            roots[i] = matrix.data[i][size] / matrix.data[i][i];
            for (int k = i - 1; k >= 0; k--) {
                matrix.data[k][size] -= matrix.data[k][i] * roots[i];
            }
        }
        std::cout << "\nTHIS SYSTEM HAS SINGLE SOLUTION:  ";
        for (auto i = 0; i < size; ++i) {
            std::cout << "X" << i + 1 << " = " << roots[i] << ";   ";
        }
        return;
    }


    //for polinoms
    double **results = new double *[basicV];
    results[0] = new double[cols * (freeV + 1)];
    for (auto i = 1; i < basicV; ++i) {
        results[i] = results[i - 1] + freeV + 1;
    }
    for (int i = 0; i < basicV; i++) {
        for (int j = 0; j < freeV + 1; j++) {
            results[i][j] = 0;
        }
    }

    // write available coefficients of free variables
    for (int i = basicV - 1; i >= 0; --i) {
        for (auto j = 0; j <= freeV; ++j) {
            if (j == 0) {
                results[i][j] += (matrix.data[i][size - j]) / matrix.data[i][i];
            } else {
                results[i][j] -= (matrix.data[i][size - j]) / matrix.data[i][i];
            }
        }
    }
//debug
    std::cout << "\n only ";
    for (auto i = 0; i < basicV; ++i) {
        std::cout << "X" << i << " = ";
        for (auto j = 0; j < freeV; ++j) {
            std::cout << "+ " << results[i][j];
            if (j) {
                std::cout << "*X" << size - freeV << " ";
            }
        }
        std::cout << "   ";
    }
    //end debug

    //add to obtained values
    for (int i = basicV - 2; i >= 0; --i) {
        for (int k = basicV - 1; k > i; --k) {
            for (auto j = 0; j <= freeV; ++j) {
                results[i][j] -= (results[k][j] * matrix.data[i][k] / matrix.data[i][i]);
            }
        }
    }

    std::cout << "\n";
    for (auto i = 0; i < basicV; ++i) {
        std::cout << "X" << i << " = ";
        for (auto j = 0; j < freeV; ++j) {
            std::cout << "+ " << results[i][j];
            if (j) {
                std::cout << "*X" << size - freeV << " ";
            }
        }
        std::cout << "   ";
    }
}
