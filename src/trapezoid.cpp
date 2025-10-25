#include "../include/trapezoid.h"

Trapezoid::Trapezoid(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    set_points(p1, p2, p3, p4);
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        Figure::operator=(other);
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
    }
    return *this;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: ";
    Figure::print(os);
}

void Trapezoid::read(std::istream& is) {
    Vector2D p1;
    Vector2D p2;
    Vector2D p3;
    Vector2D p4;
    is >> p1 >> p2 >> p3 >> p4;
    set_points(p1, p2, p3, p4);
}

double Trapezoid::square() const {
    Vector2D base1 = _p2 - _p1;
    Vector2D base2 = _p4 - _p3;
    double height = dist_to_line(_p4, _p1, _p2);
    if (std::abs(vector_product_factor(base1, base2)) > Vector2D::eps) {
        base1 = _p3 - _p2;
        base2 = _p1 - _p4;
        height = dist_to_line(_p1, _p2, _p3);
    }
    return (base1.length() + base2.length()) / 2 * height;
}

Trapezoid::operator double() const {
    return square();
}

bool Trapezoid::operator==(const Figure& other) const {
    return Figure::operator==(other);
}

void Trapezoid::set_points(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) noexcept(false) {
    if (!is_trapezoid(p1, p2, p3, p4)) {
        throw std::invalid_argument("Entered points " + p1.str() + p2.str() + p3.str() + p4.str() + " are not valid for trapezoid");
    }
    Figure::set_points(p1, p2, p3, p4);
}

bool Trapezoid::is_trapezoid(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    bool side_12_parallel_34 = std::abs(vector_product_factor(p2 - p1, p4 - p3)) < Vector2D::eps;
    bool side_23_parallel_14 = std::abs(vector_product_factor(p3 - p2, p4 - p1)) < Vector2D::eps;
    return !sides_invalid(p1, p2, p3, p4) && (side_12_parallel_34 || side_23_parallel_14);
}