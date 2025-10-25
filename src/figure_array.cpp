#include "../include/figure_array.h"
#include "../include/figure.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/rhomb.h"

FigureArray::FigureArray(size_t n) :
    _capacity(n), _size(0), _body(new Figure*[n])
{
}

FigureArray::FigureArray(const FigureArray& other) :
    _capacity(other._capacity), _size(other._size), _body(new Figure*[other._capacity])
{
    for (size_t i{0}; i < _size; ++i) {
        if (Rectangle *rect_ptr = dynamic_cast<Rectangle*>(other._body[i])) {
            _body[i] = new(std::nothrow) Rectangle(*rect_ptr);
        } else if (Trapezoid *tr_ptr = dynamic_cast<Trapezoid*>(other._body[i])) {
            _body[i] = new(std::nothrow) Trapezoid(*tr_ptr);
        } else if (Rhomb *rhomb_ptr = dynamic_cast<Rhomb*>(other._body[i])) {
            _body[i] = new(std::nothrow) Rhomb(*rhomb_ptr);
        } else {
            throw std::invalid_argument("Unknown figure type");
        }
        if (_body[i] == nullptr) {
            for (size_t j{0}; j < i; ++j) {
                delete _body[j];
            }
            delete[] _body;
            throw std::bad_alloc();
        }
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept
{
    _capacity = other._capacity;
    _size = other._size;
    _body = other._body;
    other._capacity = 0;
    other._size = 0;
    other._body = nullptr;
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        FigureArray other_copy(other);
        std::swap(_capacity, other_copy._capacity);
        std::swap(_size, other_copy._size);
        std::swap(_body, other_copy._body);
    }
    return *this;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        _capacity = other._capacity;
        _size = other._size;
        _body = other._body;
        other._capacity = 0;
        other._size = 0;
        other._body = nullptr;
    }
    return *this;
}

FigureArray::~FigureArray() noexcept {
    for (size_t i{0}; i < _size; ++i) {
        delete _body[i];
    }
    delete[] _body;
}

std::istream& FigureArray::read(size_t index, std::istream& is) {
    int type;
    is >> type;
    Figure *new_figure{nullptr};
    switch (type) {
    case 0:
        new_figure = new Rectangle();
        break;
    case 1:
        new_figure = new Trapezoid();
        break;
    case 2:
        new_figure = new Rhomb();
        break;
    default:
        throw std::invalid_argument("Invalid type of figure. Expected 0, 1 or 2");
    }
    try {
        is >> *new_figure;
    } catch (...) {
        delete new_figure;
        throw;
    }
    delete _body[index];
    _body[index] = new_figure;
    return is;
}

std::istream& FigureArray::read_all(std::istream& is) {
    for (size_t i{0}; i < _capacity;) {
        try {
           read(i, is);
           ++i;
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    _size = _capacity;
    return is;
}

std::ostream& FigureArray::print(std::ostream& os) {
    for (size_t i{0}; i < _size; ++i) {
        os << i << ": ";
        if (_body[i]) {
            os << *_body[i] << std::endl;
        } else {
            os << "None" << std::endl;
        }
    }
    return os;
}

std::ostream& FigureArray::print_centres(std::ostream& os) const {
    for (size_t i{0}; i < _size; ++i) {
        os << i << ": ";
        if (_body[i]) {
            _body[i]->print_centre(os) << std::endl;
        } else {
            os << "None" << std::endl;
        }
    }
    return os;
}

std::ostream& FigureArray::print_squares(std::ostream& os) const {
    for (size_t i{0}; i < _size; ++i) {
        os << i << ": ";
        if (_body[i]) {
            os << (double)*_body[i] << std::endl;
        } else {
            os << "None" << std::endl;
        }
    }
    return os;
}

double FigureArray::total_square() const {
    double total_square{0};
    for (size_t i{0}; i < _size; ++i) {
        if (_body[i]) {
            total_square += (double)*_body[i];
        }
    }
    return total_square;
}

void FigureArray::insert(size_t index, const Figure& obj) {
    if (_size == _capacity) {
        throw std::length_error("FigureArray is fill");
    }
    Figure *new_elem;
    if (const Rectangle *rect_ptr = dynamic_cast<const Rectangle*>(&obj)) {
        new_elem = new Rectangle(*rect_ptr);
    } else if (const Trapezoid *tr_ptr = dynamic_cast<const Trapezoid*>(&obj)) {
        new_elem = new Trapezoid(*tr_ptr);
    } else if (const Rhomb *rhomb_ptr = dynamic_cast<const Rhomb*>(&obj)) {
        new_elem = new Rhomb(*rhomb_ptr);
    } else {
        throw std::invalid_argument("Unknown figure type");
    }
    for (size_t i{_size}; i > index; --i) {
        _body[i] = _body[i - 1];
    }
    _body[index] = new_elem;
    ++_size;
}

void FigureArray::remove(size_t index) {
    delete _body[index];
    for (size_t i{index}; i < _size - 1; ++i) {
        _body[i] = _body[i + 1];
    }
    _body[_size - 1] = nullptr;
    --_size;
}