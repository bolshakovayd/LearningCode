#include <cstddef>
#include <utility>
#include <algorithm>
#include "types.h"
#include "utils.h"

Matrix2D::Matrix2D(std::size_t const rows, std::size_t const cols, float const default_value)
        : _rows{rows}, _cols{cols}, _data{Matrix2DUtils::instance().create_2d_array(rows, cols)} {
    std::fill(_data[0], _data[0] + rows * cols, default_value);
}

Matrix2D::Matrix2D(std::initializer_list <std::initializer_list<float>> l)
        : _rows{l.size()}, _cols{0} {
    for (auto &e : l) {
        if (e.size() > _cols) {
            _cols = e.size();
        }
    }
    _data = Matrix2DUtils::instance().create_2d_array(_rows, _cols);

    auto it = l.begin();
    for (std::size_t i = 0; i < _rows; ++i, ++it) {
        std::copy(it->begin(), it->end(), _data[i]);
        std::fill(_data[i] + it->size(), _data[i] + _cols, 0);
    }
}

Matrix2D::Matrix2D(const Matrix2D &other)
        : _rows{other._rows}, _cols{other._cols},
          _data{Matrix2DUtils::instance().create_2d_array(other._rows, other._cols)} {
    std::copy(other._data[0], other._data[0] + other._rows * other._cols, _data[0]);
}

Matrix2D::Matrix2D(Matrix2D &&other) noexcept
        : _data{std::exchange(other._data, nullptr)}, _rows{other._rows}, _cols{other._cols} {}

Matrix2D &Matrix2D::operator=(const Matrix2D &other) {
    *this = Matrix2D(other);
    return *this;
}

Matrix2D &Matrix2D::operator=(Matrix2D &&other) noexcept {
    swap(*this, other);
    return *this;
}

Matrix2D::~Matrix2D() {
    delete[] _data[0];
    delete[] _data;
}
