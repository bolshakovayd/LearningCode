#include "AugmentedMatrix.h"

#include <iostream>

AugmentedMatrix::AugmentedMatrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
    size = (rows > cols) ? rows : cols;

    data = new double *[size];
    data[0] = new double[(size + 1) * size];
    for (auto i = 1; i < size; ++i) {
        data[i] = data[i - 1] + size + 1;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size + 1; j++) {
            data[i][j] = 0;
        }
    }

    std::cout << "\nEnter the coefficients (matrix A): ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> data[i][j];
        }
    }

    std::cout << "\nEnter the constant terms (b): ";
    for (int i = 0; i < rows; i++) {
        std::cin >> data[i][size];
    }
}

AugmentedMatrix::~AugmentedMatrix() {
    delete[] data[0];
    delete[] data;
}

void AugmentedMatrix::print() {
    std::cout << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols + 1; j++) {
            if (j == cols) {
                std::cout << data[i][size] << "\t";
            } else {
                std::cout << data[i][j] << "\t";
            }
            if (j == cols - 1) {
                std::cout << "| ";
            }
        }
        std::cout << "\n";
    }
}

void AugmentedMatrix::printAll() {
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size + 1; j++) {
            std::cout << data[i][j] << "\t";
            if (j == size - 1) {
                std::cout << "| ";
            }
        }
        std::cout << "\n";
    }
}

unsigned int AugmentedMatrix::getSize() {
    return size;
}

unsigned int AugmentedMatrix::getCols() {
    return cols;
}

unsigned int AugmentedMatrix::getRows() {
    return rows;
}
