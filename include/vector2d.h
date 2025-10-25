#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Vector2D final
{
    friend Vector2D& operator+=(Vector2D& left, const Vector2D& right);
    friend Vector2D& operator-=(Vector2D& left, const Vector2D& right);
    friend Vector2D operator+(Vector2D left, const Vector2D& right);
    friend Vector2D operator-(Vector2D left, const Vector2D& right);
    friend Vector2D operator*(double k, Vector2D right);
    friend bool operator==(const Vector2D& left, const Vector2D& right);
    friend bool operator!=(const Vector2D& left, const Vector2D& right);

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& obj);
    friend std::istream& operator>>(std::istream& is, Vector2D& obj);

    friend double vector_product_factor(const Vector2D& v1, const Vector2D& v2);
    friend double scalar_product(const Vector2D& v1, const Vector2D& v2);
    friend double dist_to_line(const Vector2D& target_point, const Vector2D& line_point_1, const Vector2D& line_point_2);
public:
    static constexpr double eps{1e-6};
private:
    double _x{};
    double _y{};
public:
    Vector2D() = default;
    Vector2D(double x, double y);
    Vector2D(const Vector2D& other) = default;
    Vector2D& operator=(const Vector2D& other) = default;
    ~Vector2D() noexcept = default;
public:
    double get_x() const;
    double get_y() const;
public:
    std::string str() const;
    void print(std::ostream& os) const;
    void read(std::istream& is);
public:
    Vector2D& operator*=(double k);
    Vector2D& operator/=(double k);
    Vector2D operator*(double k) const;
    Vector2D operator/(double k) const;
public:
    double length() const;
    bool abs_eq(const Vector2D& other) const;
    double angle_to(const Vector2D& other) const noexcept(false);
};

Vector2D& operator+=(Vector2D& left, const Vector2D& right);
Vector2D& operator-=(Vector2D& left, const Vector2D& right);
Vector2D operator+(Vector2D left, const Vector2D& right);
Vector2D operator-(Vector2D left, const Vector2D& right);
Vector2D operator*(double k, Vector2D right);
bool operator==(const Vector2D& left, const Vector2D& right);
bool operator!=(const Vector2D& left, const Vector2D& right);
std::ostream& operator<<(std::ostream& os, const Vector2D& obj);
std::istream& operator>>(std::istream& is, Vector2D& obj);
double vector_product_factor(const Vector2D& v1, const Vector2D& v2);
double scalar_product(const Vector2D& v1, const Vector2D& v2);
double dist_to_line(const Vector2D& target_point, const Vector2D& line_point_1, const Vector2D& line_point_2);

#endif