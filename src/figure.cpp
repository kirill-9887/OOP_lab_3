#include "../include/figure.h"

Figure::Figure() :
    _p1(0, 0),
    _p2(0, 1),
    _p3(1, 1),
    _p4(1, 0)
{
}

Figure::Figure(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    set_points(p1, p2, p3, p4);
}

Figure::Figure(const Figure& other) :
    _p1(other._p1),
    _p2(other._p2),
    _p3(other._p3),
    _p4(other._p4)
{
}

Figure::Figure(Figure&& other) noexcept : 
    _p1(std::move(other._p1)),
    _p2(std::move(other._p2)),
    _p3(std::move(other._p3)),
    _p4(std::move(other._p4))
{
}

Vector2D Figure::operator[](int point_index) const {
    switch (point_index) {
    case 0:
        return _p1;
    case 1:
        return _p2;
    case 2:
        return _p3;
    case 3:
        return _p4;
    default:
        throw std::out_of_range("Point index is out of range, should be in [0, 3]");
    }
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        _p1 = other._p1;
        _p2 = other._p2;
        _p3 = other._p3;
        _p4 = other._p4;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        _p1 = other._p1;
        _p2 = other._p2;
        _p3 = other._p3;
        _p4 = other._p4;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Figure& obj) {
    obj.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& obj) {
    obj.read(is);
    return is;
}

bool Figure::operator==(const Figure& other) const {
    Vector2D _v1 = _p2 - _p1;
    Vector2D _v2 = _p3 - _p1;
    Vector2D _v3 = _p4 - _p1;
    Vector2D points[]{ other._p1, other._p2, other._p3, other._p4 };
    for (int i{0}; i < 4; ++i) {
        Vector2D p1 = points[i];
        Vector2D p2 = points[(i + 1) % 4];
        Vector2D p3 = points[(i + 2) % 4];
        Vector2D p4 = points[(i + 3) % 4];
        if (_v1.abs_eq(p2 - p1) && _v2.abs_eq(p3 - p1) && _v3.abs_eq(p4 - p1)
                && std::abs(_v1.angle_to(_v2) - (p2 - p1).angle_to(p3 - p1)) < Vector2D::eps
                && std::abs(_v2.angle_to(_v3) - (p3 - p1).angle_to(p4 - p1)) < Vector2D::eps
                || _v1.abs_eq(p4 - p1) && _v2.abs_eq(p3 - p1) && _v3.abs_eq(p2 - p1)
                && std::abs(_v1.angle_to(_v2) - (p4 - p1).angle_to(p3 - p1)) < Vector2D::eps
                && std::abs(_v2.angle_to(_v3) - (p3 - p1).angle_to(p2 - p1)) < Vector2D::eps) {
            return true;
        }
    }
    return false;
}

bool Figure::operator!=(const Figure& other) const {
    return !(*this == other);
}

Vector2D Figure::calc_centre() const {
    return (_p1 + _p2 + _p3 + _p4) / 4;
}

std::ostream& Figure::print_centre(std::ostream& os) const {
    os << calc_centre();
    return os;
}

void Figure::set_points(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) noexcept(false) {
    _p1 = p1;
    _p2 = p2;
    _p3 = p3;
    _p4 = p4;
}

void Figure::print(std::ostream& os) const {
    os << "[ " << _p1 << ", " << _p2 << ", " << _p3 << ", " << _p4 << " ]";
}

bool Figure::sides_invalid(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    double prod1_1 = vector_product_factor(p2 - p1, p3 - p2) * vector_product_factor(p2 - p1, p4 - p2);
    double prod1_2 = vector_product_factor(p4 - p3, p1 - p4) * vector_product_factor(p4 - p3, p2 - p4);
    double prod2_1 = vector_product_factor(p3 - p2, p4 - p3) * vector_product_factor(p3 - p2, p1 - p3);
    double prod2_2 = vector_product_factor(p1 - p4, p2 - p1) * vector_product_factor(p1 - p4, p3 - p1);
    return prod1_1 < 0 && prod1_2 < 0 || prod2_1 < 0 && prod2_2 < 0
               || std::abs(prod1_1) < Vector2D::eps || std::abs(prod1_2) < Vector2D::eps
               || std::abs(prod2_1) < Vector2D::eps || std::abs(prod2_2) < Vector2D::eps 
               || (p2 - p1).abs_eq(Vector2D(0, 0)) || (p3 - p2).abs_eq(Vector2D(0, 0))
               || (p4 - p3).abs_eq(Vector2D(0, 0)) || (p1 - p4).abs_eq(Vector2D(0, 0));
}