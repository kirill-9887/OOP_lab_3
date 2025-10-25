#include "./include/figure.h"
#include "./include/rectangle.h"
#include "./include/trapezoid.h"
#include "./include/rhomb.h"
#include "./include/figure_array.h"
#include <string>

void process_input(FigureArray *arr) {
    std::string command;
    std::cin.ignore();
    std::getline(std::cin, command);
    while (!command.empty()) {
        if (command == "read_all") {
            std::cout << "Введите тип каждой фигуры и координаты вершин:" << std::endl;
            std::cout << "0 - прямоугольник, 1 - трапеция, 2 - ромб" << std::endl;
            arr->read_all(std::cin);
            std::cin.ignore();
        } else if (command == "squares") {
            arr->print_squares(std::cout);
        } else if (command == "total_square") {
            std::cout << arr->total_square() << std::endl;
        } else if (command == "centres") {
            arr->print_centres(std::cout);
        } else if (command == "print") {
            arr->print(std::cout);
        } else if (command == "del") {
            size_t ind;
            std::cin >> ind;
            std::cin.ignore();
            arr->remove(ind);
        } else {
            std::cout << "Error: Unknown command\"" << command << "\". Use read_all, squares, total_square, centres, print, del [ind]" << std::endl;
        }
        std::getline(std::cin, command);
    }
}

int main() {
    int n;
    std::cout << "Введите количество фигур: ";
    std::cin >> n;
    FigureArray* a = new FigureArray(n);
    process_input(a);
    delete a;
    return 0;
}