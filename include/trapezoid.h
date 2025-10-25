#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "./figure.h"

class Trapezoid : public Figure
{
public:
    Trapezoid() : Figure() {};
    Trapezoid(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
    Trapezoid(const Trapezoid& other) : Figure(other) {};
    Trapezoid(Trapezoid&& other) noexcept : Figure(other) {};
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    ~Trapezoid() noexcept = default;
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
    static bool is_trapezoid(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
};

#endif