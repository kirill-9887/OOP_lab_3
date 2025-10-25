#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H

#include <iostream>
#include <exception>
#include <limits>

class Figure;

class FigureArray
{
private:
    size_t _capacity;
    size_t _size;
    Figure **_body;
public:
    FigureArray(size_t n);
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;
    virtual ~FigureArray() noexcept;
public:
    std::istream& read(size_t index, std::istream& is);
    std::istream& read_all(std::istream& is);
    std::ostream& print(std::ostream& os);
    std::ostream& print_centres(std::ostream& os) const;
    std::ostream& print_squares(std::ostream& os) const;
    double total_square() const;
    void insert(size_t index, const Figure& obj);
    void remove(size_t index);
};

#endif