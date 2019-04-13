#pragma once

#include <cstddef>
#include <iostream>
#include "types.h"

class Matrix2DUtils {
public:
    static Matrix2DUtils &instance();

    float **create_2d_array(std::size_t rows, std::size_t cols) const;

    Matrix2D get_reduced_row_echelon(Matrix2D mat) const;

    void solve_system(std::istream &in, std::ostream &out) const;

    Matrix2DUtils(Matrix2DUtils const &) = delete;

    void operator=(Matrix2DUtils const &) = delete;

private:
    Matrix2DUtils();
};
