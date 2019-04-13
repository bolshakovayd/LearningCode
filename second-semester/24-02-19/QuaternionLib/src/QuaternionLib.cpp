#include "QuaternionLib.h"
#include <cmath>
#include <iostream>

Quaternion invertedQuaternion(Quaternion const &a) {
    return Quaternion(-a.getX(), -a.getY(), -a.getZ(), -a.getScalar());
}

Quaternion operator*(Quaternion const &a, double scale) {
    return Quaternion(a.getX() * scale, a.getY() * scale, a.getZ() * scale, a.getScalar() * scale);
}

Quaternion operator/(Quaternion const &a, double scale) {
    return Quaternion(a.getX() / scale, a.getY() / scale, a.getZ() / scale, a.getScalar() / scale);
}

Quaternion operator+(Quaternion const &a, Quaternion const &b) {
    return Quaternion(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ(), a.getScalar() + b.getScalar());
}

Quaternion operator-(Quaternion const &a, Quaternion const &b) {
    return Quaternion(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ(), a.getScalar() - b.getScalar());
}

Quaternion operator*(Quaternion const &a, Quaternion const &b) {
    return Quaternion(a.getScalar() * b.getX() + a.getX() * b.getScalar() + a.getY() * b.getZ() - a.getZ() * b.getY(),
                      a.getScalar() * b.getY() - a.getX() * b.getZ() + a.getY() * b.getScalar() + a.getZ() * b.getX(),
                      a.getScalar() * b.getZ() + a.getX() * b.getY() - a.getY() * b.getX() + a.getZ() * b.getScalar(),
                      a.getScalar() * b.getScalar() - a.getX() * b.getX() - a.getY() * b.getY() - a.getZ() * b.getZ());
}

Quaternion operator/(Quaternion const &a, Quaternion const &b) {
    return a * invertedQuaternion(b);
}

Quaternion::Quaternion(double x, double y, double z, double scalar) : x(x), y(y), z(z), scal(scalar) {}

Quaternion::Quaternion(Quaternion const &other) : x(other.x), y(other.y), z(other.z), scal(other.scal) {}

void Quaternion::setX(double newX) {
    x = newX;
}

void Quaternion::setY(double newY) {
    y = newY;
}

void Quaternion::setZ(double newZ) {
    z = newZ;
}

void Quaternion::setScalar(double newScalar) {
    scal = newScalar;
}

double Quaternion::getX() const {
    return x;
}

double Quaternion::getY() const {
    return y;
}

double Quaternion::getZ() const {
    return z;
}

double Quaternion::getScalar() const {
    return scal;
}

Quaternion &Quaternion::operator=(Quaternion const &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    scal = other.scal;
    return *this;
}

bool Quaternion::operator==(Quaternion const &other) const {
    return x == other.x && y == other.y && z == other.z && scal == other.scal;
}

bool Quaternion::operator!=(Quaternion const &other) const {
    return !(x == other.x && y == other.y && z == other.z && scal == other.scal);
}

Quaternion &Quaternion::operator*=(double scale) {
    x *= scale;
    y *= scale;
    z *= scale;
    scal *= scale;
    return *this;
}

Quaternion &Quaternion::operator/=(double scale) {
    x /= scale;
    y /= scale;
    z /= scale;
    scal /= scale;
    return *this;
}

Quaternion &Quaternion::operator+=(Quaternion const &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    scal += other.scal;
    return *this;
}

Quaternion &Quaternion::operator-=(Quaternion const &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    scal -= other.scal;
    return *this;
}

Quaternion &Quaternion::operator*=(Quaternion const &other) {
    double tx = x;
    double ty = y;
    double tz = z;
    double tscal = scal;
    x = tscal * other.x + tx * other.scal + ty * other.z - tz * other.y;
    y = tscal * other.y - tx * other.z + ty * other.scal + tz * other.x;
    z = tscal * other.z + tx * other.y - ty * other.x + tz * other.scal;
    scal = tscal * other.scal - tx * other.x - ty * other.y - tz * other.z;
    return *this;
}

Quaternion &Quaternion::operator/=(Quaternion const &other) {
    *this *= invertedQuaternion(other);
    return *this;
}

double Quaternion::magnitude() {
    return sqrt(x * x + y * y + z * z);
}

void Quaternion::normalize() {
    double tmagnitude = magnitude();
    if (tmagnitude) {
        x /= tmagnitude;
        y /= tmagnitude;
        z /= tmagnitude;
    }
}

void Quaternion::invert() {
    x = -x;
    y = -y;
    z = -z;
}

void Quaternion::print() {
    std::cout << "\nx: " << x << "  y: " << y << "  z: " << z << "  scalar: " << scal;
}
