#include "../include/vector2d.h"

Vector2D::Vector2D(double x, double y) :
    _x(x), _y(y)
{
}

double Vector2D::get_x() const {
    return _x;
}

double Vector2D::get_y() const {
    return _y;
}


Vector2D& operator+=(Vector2D& left, const Vector2D& right) {
    left._x += right._x;
    left._y += right._y;
    return left;
}

Vector2D& operator-=(Vector2D& left, const Vector2D& right) {
    left._x -= right._x;
    left._y -= right._y;
    return left;
}

Vector2D& Vector2D::operator*=(double k) {
    _x *= k;
    _y *= k;
    return *this;
}

Vector2D& Vector2D::operator/=(double k) {
    _x /= k;
    _y /= k;
    return *this;
}

Vector2D operator+(Vector2D left, const Vector2D& right) {
    return left += right;
}

Vector2D operator-(Vector2D left, const Vector2D& right) {
    return left -= right;
}

Vector2D Vector2D::operator*(double k) const {
    Vector2D res(*this);
    res *= k;
    return res;
}

Vector2D operator*(double k, Vector2D right) {
    return right *= k;
}

bool operator==(const Vector2D& left, const Vector2D& right) {
    return std::abs(left._x - right._x) < Vector2D::eps && std::abs(left._y - right._y) < Vector2D::eps;
}

bool operator!=(const Vector2D& left, const Vector2D& right) {
    return !(left == right);
}

Vector2D Vector2D::operator/(double k) const {
    Vector2D res(*this);
    res /= k;
    return res;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& obj) {
    obj.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Vector2D& obj) {
    obj.read(is);
    return is;
}

double vector_product_factor(const Vector2D& v1, const Vector2D& v2) {
    return v1._x * v2._y - v2._x * v1._y;
}

double scalar_product(const Vector2D& v1, const Vector2D& v2) {
    return v1._x * v2._x + v1._y * v2._y;
}

double dist_to_line(const Vector2D& target_point, const Vector2D& line_point_1, const Vector2D& line_point_2) {
    return std::abs(vector_product_factor(line_point_1 - target_point, line_point_2 - target_point)) / (line_point_2 - line_point_1).length();
}

double Vector2D::length() const {
    return std::sqrt(scalar_product(*this, *this));
}

bool Vector2D::abs_eq(const Vector2D& other) const {
    return std::abs(length() - other.length()) < eps;
}

double Vector2D::angle_to(const Vector2D& other) const {
    if (std::abs(length()) < eps || std::abs(other.length()) < eps) {
        throw std::invalid_argument("Angle with null length vector is not defined");
    }
    double cos_ = scalar_product(*this, other) / length() / other.length();
    if (cos_ > 1.0) {
        cos_ = 1.0;
    } else if (cos_ < -1.0) {
        cos_ = -1.0;
    }
    return acos(cos_);
}

std::string Vector2D::str() const {
    return "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
}

void Vector2D::print(std::ostream& os) const {
    os << "(" << _x << ", " << _y << ")";
}

void Vector2D::read(std::istream& is) {
    is >> _x >> _y;
}