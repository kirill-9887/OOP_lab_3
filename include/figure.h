#ifndef FIGURE_H
#define FIGURE_H

#include "./vector2d.h"
#include <iostream>

class Figure
{
    friend std::ostream& operator<<(std::ostream& os, const Figure& obj);
    friend std::istream& operator>>(std::istream& is, Figure& obj);
protected:
    Vector2D _p1;
    Vector2D _p2;
    Vector2D _p3;
    Vector2D _p4;
protected:
    Figure();
    Figure(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;
public:
    virtual ~Figure() noexcept = default;
public:
    virtual Vector2D operator[](int point_index) const;
public:
    Vector2D calc_centre() const;
    std::ostream& print_centre(std::ostream& os) const;
    virtual explicit operator double() const = 0;
    virtual bool operator==(const Figure& other) const;
    bool operator!=(const Figure& other) const;
protected:
    virtual void set_points(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) noexcept(false);
    virtual void print(std::ostream& os) const;
    virtual void read(std::istream& is) noexcept(false) = 0;
    virtual double square() const = 0;
protected:
    static bool sides_invalid(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
};

std::ostream& operator<<(std::ostream& os, const Figure& obj);
std::istream& operator>>(std::istream& is, Figure& obj);

#endif