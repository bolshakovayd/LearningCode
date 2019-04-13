#pragma once

#include <cstddef>
#include <utility>
#include <ostream>
#include <cassert>

class Matrix2D {
public:
    Matrix2D(std::size_t rows, std::size_t cols, float default_value = 0);

    Matrix2D(std::initializer_list <std::initializer_list<float>> l);

    Matrix2D(const Matrix2D &other);

    Matrix2D(Matrix2D &&other) noexcept;

    Matrix2D &operator=(const Matrix2D &other);

    Matrix2D &operator=(Matrix2D &&other) noexcept;

    virtual ~Matrix2D();

    friend void swap(Matrix2D &left, Matrix2D &right) {
        std::swap(left._data, right._data);
        std::swap(left._rows, right._rows);
        std::swap(left._cols, right._cols);
    }

    friend std::ostream &operator<<(std::ostream &stream, const Matrix2D &matrix) {
        for (std::size_t i = 0; i < matrix._rows; ++i) {
            for (std::size_t j = 0; j < matrix._cols; ++j) {
                stream << matrix._data[i][j] << '\t';
            }
            if (i != matrix._rows - 1) {
                stream << '\n';
            }
        }
        return stream;
    }

    class Proxy {
    public:
        inline float &operator[](std::size_t const idx) {
            assert(idx < _size);
            return _proxy_data[idx];
        }

        explicit Proxy(float *data, std::size_t cols)
                : _proxy_data(data), _size(cols) {}

    private:
        std::size_t _size;
        float *_proxy_data;
    };

    inline Proxy operator[](std::size_t const idx) {
        assert(idx < _rows);
        return Proxy(_data[idx], _cols);
    }

    inline std::size_t const rows() const { return _rows; }

    inline std::size_t const cols() const { return _cols; }

    friend class Matrix2DUtils;

private:
    std::size_t _cols;
    std::size_t _rows;
    float **_data;
};
