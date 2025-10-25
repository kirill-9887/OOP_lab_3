#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "./figure.h"
#include <exception>

class Rectangle : public Figure
{
public:
    Rectangle() : Figure() {};
    Rectangle(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
    Rectangle(const Rectangle& other) : Figure(other) {};
    Rectangle(Rectangle&& other) noexcept : Figure(other) {};
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    ~Rectangle() noexcept = default;
public:
    virtual explicit operator double() const override;
protected:
    virtual void set_points(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4) noexcept(false) override;
    virtual void print(std::ostream& os) const override;
    virtual void read(std::istream& is) noexcept(false) override;
    virtual double square() const override;
public:
    virtual bool operator==(const Figure& other) const override;
protected:
    static bool is_rectangle(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
};

#endif