#ifndef RHOMB_H
#define RHOMB_H

#include "./figure.h"
#include <exception>

class Rhomb : public Figure
{
public:
    Rhomb() : Figure() {};
    Rhomb(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
    Rhomb(const Rhomb& other) : Figure(other) {};
    Rhomb(Rhomb&& other) noexcept : Figure(other) {};
    Rhomb& operator=(const Rhomb& other);
    Rhomb& operator=(Rhomb&& other) noexcept;
    ~Rhomb() noexcept = default;
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
    static bool is_rhomb(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3, const Vector2D& p4);
};

#endif