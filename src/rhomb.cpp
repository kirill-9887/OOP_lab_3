#include "../include/rhomb.h"

Rhomb::Rhomb(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    set_points(p1, p2, p3, p4);
}

Rhomb& Rhomb::operator=(const Rhomb& other) {
    if (this != &other) {
        Figure::operator=(other);
    }
    return *this;
}

Rhomb& Rhomb::operator=(Rhomb&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
    }
    return *this;
}

void Rhomb::print(std::ostream& os) const {
    os << "Rhomb: ";
    Figure::print(os);
}

void Rhomb::read(std::istream& is) {
    Vector2D p1;
    Vector2D p2;
    Vector2D p3;
    Vector2D p4;
    is >> p1 >> p2 >> p3 >> p4;
    set_points(p1, p2, p3, p4);
}

double Rhomb::square() const {
    return (_p3 - _p1).length() * (_p4 - _p2).length() / 2;
}

Rhomb::operator double() const {
    return square();
}

bool Rhomb::operator==(const Figure& other) const {
    const Rhomb *other_ptr = dynamic_cast<const Rhomb*>(&other);
    if (!other_ptr) {
        return Figure::operator==(other);
    }
    return std::abs((_p2 - _p1).length() - (other_ptr->_p2 - other_ptr->_p1).length()) < Vector2D::eps
                && std::abs((_p2 - _p1).angle_to(_p4 - _p1) - (other_ptr->_p2 - other_ptr->_p1).angle_to(other_ptr->_p4 - other_ptr->_p1)) < Vector2D::eps
                || std::abs((_p2 - _p1).angle_to(_p4 - _p1) - (other_ptr->_p3 - other_ptr->_p2).angle_to(other_ptr->_p1 - other_ptr->_p2)) < Vector2D::eps;
}

void Rhomb::set_points(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) noexcept(false) {
    if (!is_rhomb(p1, p2, p3, p4)) {
        throw std::invalid_argument("Entered points " + p1.str() + p2.str() + p3.str() + p4.str() + " are not valid for rhomb");
    }
    Figure::set_points(p1, p2, p3, p4);
}

bool Rhomb::is_rhomb(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) {
    double side_1_length = (p2 - p1).length();
    bool side_1_eq_2 = std::abs(side_1_length - (p3 - p2).length()) < Vector2D::eps;
    bool side_1_eq_3 = std::abs(side_1_length - (p4 - p3).length()) < Vector2D::eps;
    bool side_1_eq_4 = std::abs(side_1_length - (p4 - p1).length()) < Vector2D::eps;
    return !sides_invalid(p1, p2, p3, p4) && side_1_eq_2 && side_1_eq_3 && side_1_eq_4;
}
