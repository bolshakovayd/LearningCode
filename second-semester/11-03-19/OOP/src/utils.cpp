#include "utils.h"
#include <cstddef>
#include <cmath>
#include <utility>

float **Matrix2DUtils::create_2d_array(std::size_t const rows, std::size_t const cols) const {
    float **array = new float *[rows];
    array[0] = new float[rows * cols];
    for (std::size_t i = 1; i < rows; ++i) {
        array[i] = array[i - 1] + cols;
    }
    return array;
}

#include <iostream>

Matrix2D Matrix2DUtils::get_reduced_row_echelon(Matrix2D mat) const {
    assert(mat._cols != 0 && mat._rows != 0);
    assert(mat._cols == mat._rows + 1);

    for (std::size_t i = 0; i < mat._rows; ++i) {
        float max_val = std::abs(mat[i][i]);
        std::size_t max_row = i;
        for (std::size_t k = i + 1; k < mat._rows; ++k) {
            float current_val = std::abs(mat[k][i]);
            if (current_val > max_val) {
                max_val = current_val;
                max_row = k;
            }
        }

        for (std::size_t k = i; k < mat._cols; ++k) {
            std::swap(mat[max_row][k], mat[i][k]);
        }

        for (std::size_t k = i + 1; k < mat._rows; ++k) {
            float c = -mat[k][i] / mat[i][i];
            for (std::size_t j = i; j < mat._cols; ++j) {
                if (i == j) {
                    mat[k][j] = 0;
                } else {
                    mat[k][j] += c * mat[i][j];
                }
            }
        }
    }

    return mat;
}

void Matrix2DUtils::solve_system(std::istream &in, std::ostream &out) const {
    out << "Enter the amount of variables:" << std::endl;
    std::size_t variables;
    in >> variables;

    out << "Enter the amount of equation:" << std::endl;
    std::size_t equations;
    in >> equations;

    std::size_t size = std::max(equations, variables);
    Matrix2D mat(size, size + 1);

    out << "Enter the coefficients (matrix A):" << std::endl;
    for (std::size_t i = 0; i < equations; ++i) {
        for (std::size_t j = 0; j < variables; ++j) {
            in >> mat[i][j];
        }
    }

    out << "Enter the constant terms (b):" << std::endl;
    for (std::size_t i = 0; i < equations; ++i) {
        in >> mat[i][size];
    }

    out << "Reduced echelon form:" << std::endl;
    out << Matrix2DUtils::instance().get_reduced_row_echelon(mat) << std::endl;
}

Matrix2DUtils &Matrix2DUtils::instance() {
    static Matrix2DUtils instance;
    return instance;
}

Matrix2DUtils::Matrix2DUtils() = default;
