#include "../include/rectangle.h"

Rectangle::Rectangle(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    set_points(p1, p2, p3, p4);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        Figure::operator=(other);
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
    }
    return *this;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: ";
    Figure::print(os);
}

void Rectangle::read(std::istream& is) {
    Vector2D p1;
    Vector2D p2;
    Vector2D p3;
    Vector2D p4;
    is >> p1 >> p2 >> p3 >> p4;
    set_points(p1, p2, p3, p4);
}

double Rectangle::square() const {
    return (_p2 - _p1).length() * (_p3 - _p2).length();
}

Rectangle::operator double() const {
    return square();
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle *other_ptr = dynamic_cast<const Rectangle*>(&other);
    if (!other_ptr) {
        return Figure::operator==(other);
    }
    return std::abs((_p2 - _p1).length() - (other_ptr->_p2 - other_ptr->_p1).length()) < Vector2D::eps
                && std::abs((_p4 - _p1).length() - (other_ptr->_p4 - other_ptr->_p1).length()) < Vector2D::eps
                || std::abs((_p4 - _p1).length() - (other_ptr->_p2 - other_ptr->_p1).length()) < Vector2D::eps
                && std::abs((_p2 - _p1).length() - (other_ptr->_p4 - other_ptr->_p1).length()) < Vector2D::eps;
}

void Rectangle::set_points(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) noexcept(false) {
    if (!is_rectangle(p1, p2, p3, p4)) {
        throw std::invalid_argument("Entered points " + p1.str() + p2.str() + p3.str() + p4.str() + " are not valid for rectangle");
    }
    Figure::set_points(p1, p2, p3, p4);
}

bool Rectangle::is_rectangle(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    bool angle_1_right = std::abs(scalar_product(p2 - p1, p4 - p1)) < Vector2D::eps;
    bool angle_2_right = std::abs(scalar_product(p3 - p2, p1 - p2)) < Vector2D::eps;
    bool angle_3_right = std::abs(scalar_product(p4 - p3, p2 - p3)) < Vector2D::eps;
    return !sides_invalid(p1, p2, p3, p4) && angle_1_right && angle_2_right && angle_3_right;
}
