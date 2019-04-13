#pragma once

#include <cmath>

struct Quaternion {
    explicit Quaternion(double x = 0, double y = 0, double z = 0, double scalar = 0);

    Quaternion(Quaternion const &other);

    void setX(double newX);

    void setY(double newY);

    void setZ(double newZ);

    void setScalar(double newScalar);

    double getX() const;

    double getY() const;

    double getZ() const;

    double getScalar() const;

    Quaternion &operator=(Quaternion const &other);

    bool operator==(Quaternion const &other) const;

    bool operator!=(Quaternion const &other) const;

    Quaternion &operator*=(double scale);

    Quaternion &operator/=(double scale);

    Quaternion &operator+=(Quaternion const &other);

    Quaternion &operator-=(Quaternion const &other);

    Quaternion &operator*=(Quaternion const &other);

    Quaternion &operator/=(Quaternion const &other);

    double magnitude();

    void normalize();

    void invert();

    void print();

private:
    double x;
    double y;
    double z;
    double scal;
};

Quaternion invertedQuaternion(Quaternion const &a);

Quaternion operator*(Quaternion const &a, double scale);

Quaternion operator/(Quaternion const &a, double scale);

Quaternion operator+(Quaternion const &a, Quaternion const &b);

Quaternion operator-(Quaternion const &a, Quaternion const &b);

Quaternion operator*(Quaternion const &a, Quaternion const &b);

Quaternion operator/(Quaternion const &a, Quaternion const &b);
