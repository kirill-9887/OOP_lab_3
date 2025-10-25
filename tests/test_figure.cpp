#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/rhomb.h"
#include "./test.h"
#include <sstream>
#include <cmath>

TEST(FigureTest, ConstructorDefault) {
    Rectangle a;
    EXPECT_TRUE(a[0] == Vector2D(0, 0) && a[1] == Vector2D(0, 1) && a[2] == Vector2D(1, 1) && a[3] == Vector2D(1, 0));
    Trapezoid b;
    EXPECT_TRUE(b[0] == Vector2D(0, 0) && b[1] == Vector2D(0, 1) && b[2] == Vector2D(1, 1) && b[3] == Vector2D(1, 0));
    Rhomb c;
    EXPECT_TRUE(c[0] == Vector2D(0, 0) && c[1] == Vector2D(0, 1) && c[2] == Vector2D(1, 1) && c[3] == Vector2D(1, 0));
}

TEST(FigureTest, ConstructorWithParameters) {
    {
        EXPECT_NO_THROW(Rectangle(Vector2D(0, 0), Vector2D(0, 2), Vector2D(3, 2), Vector2D(3, 0)));
        EXPECT_NO_THROW(Rectangle(Vector2D(0, 0), Vector2D(0, 5), Vector2D(5, 5), Vector2D(5, 0)));
        EXPECT_NO_THROW(Rectangle(Vector2D(-1, -1), Vector2D(-1, 1), Vector2D(1, 1), Vector2D(1, -1)));
        EXPECT_THROW(Rectangle(Vector2D(0, 0), Vector2D(0, 2), Vector2D(3, 3), Vector2D(3, 0)), std::invalid_argument);
        EXPECT_THROW(Rectangle(Vector2D(0, 0), Vector2D(3, 2), Vector2D(3, 0), Vector2D(0, 2)), std::invalid_argument);
    }
    {
        EXPECT_NO_THROW(Trapezoid(Vector2D(0, 0), Vector2D(5, 0), Vector2D(4, 3), Vector2D(1, 3)));
        EXPECT_NO_THROW(Trapezoid(Vector2D(1, 1), Vector2D(7, 1), Vector2D(5, 4), Vector2D(3, 4)));
        EXPECT_NO_THROW(Trapezoid(Vector2D(2, 2), Vector2D(8, 2), Vector2D(6, 6), Vector2D(3, 6)));
        EXPECT_NO_THROW(Trapezoid(Vector2D(3, 3), Vector2D(5, 5), Vector2D(5, 2), Vector2D(4, 1)));
        EXPECT_THROW(Trapezoid(Vector2D(1, 1), Vector2D(5, 2), Vector2D(7, 7), Vector2D(0, 5)), std::invalid_argument);
        EXPECT_THROW(Trapezoid(Vector2D(0, 0), Vector2D(3, 0), Vector2D(4, 3), Vector2D(1, 4)), std::invalid_argument);
        EXPECT_THROW(Trapezoid(Vector2D(0, 0), Vector2D(4, 0), Vector2D(1, 1), Vector2D(3, 1)), std::invalid_argument);
        EXPECT_THROW(Trapezoid(Vector2D(0, 0), Vector2D(1, 1), Vector2D(1, 1), Vector2D(1, 0)), std::invalid_argument);
    }
    {
        EXPECT_NO_THROW(Rhomb(Vector2D(0, 1),  Vector2D(1, 0), Vector2D(0, -1), Vector2D(-1, 0)));
        EXPECT_NO_THROW(Rhomb(Vector2D(0, 2),  Vector2D(2, 0), Vector2D(0, -2), Vector2D(-2, 0)));
        EXPECT_NO_THROW(Rhomb(Vector2D(-2, -2),  Vector2D(-1, 0), Vector2D(1, 1), Vector2D(0, -1)));
        EXPECT_THROW(Rhomb(Vector2D(0, 1),  Vector2D(1, 0), Vector2D(0, 2), Vector2D(-1, 0)), std::invalid_argument);
        EXPECT_THROW(Rhomb(Vector2D(0, 1),  Vector2D(2, 0), Vector2D(0, -2), Vector2D(-1, 0)), std::invalid_argument);
    }
}

TEST(FigureTest, ConstructorCopy) {
    {
        Rectangle original;
        Rectangle copy(original);
        EXPECT_TRUE(copy[0] == Vector2D(0, 0) && copy[1] == Vector2D(0, 1) && copy[2] == Vector2D(1, 1) && copy[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &copy);
    }
    {
        Rhomb original;
        Rhomb copy(original);
        EXPECT_TRUE(copy[0] == Vector2D(0, 0) && copy[1] == Vector2D(0, 1) && copy[2] == Vector2D(1, 1) && copy[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &copy);
    }
    {
        Trapezoid original;
        Trapezoid copy(original);
        EXPECT_TRUE(copy[0] == Vector2D(0, 0) && copy[1] == Vector2D(0, 1) && copy[2] == Vector2D(1, 1) && copy[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &copy);
    }
}

TEST(FigureTest, ConstructorMove) {
    {
        Rectangle original;
        Rectangle moved(std::move(original));
        EXPECT_TRUE(moved[0] == Vector2D(0, 0) && moved[1] == Vector2D(0, 1) && moved[2] == Vector2D(1, 1) && moved[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &moved);
    }
    {
        Rhomb original;
        Rhomb moved(std::move(original));
        EXPECT_TRUE(moved[0] == Vector2D(0, 0) && moved[1] == Vector2D(0, 1) && moved[2] == Vector2D(1, 1) && moved[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &moved);
    }
    {
        Trapezoid original;
        Trapezoid moved(std::move(original));
        EXPECT_TRUE(moved[0] == Vector2D(0, 0) && moved[1] == Vector2D(0, 1) && moved[2] == Vector2D(1, 1) && moved[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &moved);
    }
}

TEST(FigureTest, AssignCopyOperator) {
    {
        Rectangle original;
        Rectangle copy;
        copy = original;
        EXPECT_TRUE(copy[0] == Vector2D(0, 0) && copy[1] == Vector2D(0, 1) && copy[2] == Vector2D(1, 1) && copy[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &copy);
    }
    {
        Rhomb original;
        Rhomb copy;
        copy = original;
        EXPECT_TRUE(copy[0] == Vector2D(0, 0) && copy[1] == Vector2D(0, 1) && copy[2] == Vector2D(1, 1) && copy[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &copy);
    }
    {
        Trapezoid original;
        Trapezoid copy;
        copy = original;
        EXPECT_TRUE(copy[0] == Vector2D(0, 0) && copy[1] == Vector2D(0, 1) && copy[2] == Vector2D(1, 1) && copy[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
        EXPECT_NE(&original, &copy);
    }
}

TEST(FigureTest, AssignMoveOperator) {
    {
        Rectangle original;
        Rectangle moved;
        moved = std::move(original);
        EXPECT_TRUE(moved[0] == Vector2D(0, 0) && moved[1] == Vector2D(0, 1) && moved[2] == Vector2D(1, 1) && moved[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
    }
    {
        Rhomb original;
        Rhomb moved;
        moved = std::move(original);
        EXPECT_TRUE(moved[0] == Vector2D(0, 0) && moved[1] == Vector2D(0, 1) && moved[2] == Vector2D(1, 1) && moved[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
    }
    {
        Trapezoid original;
        Trapezoid moved;
        moved = std::move(original);
        EXPECT_TRUE(moved[0] == Vector2D(0, 0) && moved[1] == Vector2D(0, 1) && moved[2] == Vector2D(1, 1) && moved[3] == Vector2D(1, 0));
        EXPECT_TRUE(original[0] == Vector2D(0, 0) && original[1] == Vector2D(0, 1) && original[2] == Vector2D(1, 1) && original[3] == Vector2D(1, 0));
    }
}

TEST(FigureTest, OperatorDouble_Square) {
    {
        Rectangle a(Vector2D(0, 0), Vector2D(0, 2), Vector2D(3, 2), Vector2D(3, 0));
        Rectangle b(Vector2D(0, 0), Vector2D(0, 3), Vector2D(4, 3), Vector2D(4, 0));
        Rectangle c(Vector2D(1, 1), Vector2D(1, 4), Vector2D(5, 4), Vector2D(5, 1));
        Rectangle d(Vector2D(0, 0), Vector2D(0, 5), Vector2D(5, 5), Vector2D(5, 0));
        Rectangle e(Vector2D(-1, -1), Vector2D(-1, 1), Vector2D(1, 1), Vector2D(1, -1));
        Rectangle f(Vector2D(0, 2), Vector2D(3, 5), Vector2D(4, 4), Vector2D(1, 1));
        
        EXPECT_TRUE(double_eq(static_cast<double>(a), 6.0));
        EXPECT_TRUE(double_eq(static_cast<double>(b), 12.0));
        EXPECT_TRUE(double_eq(static_cast<double>(c), 12.0));
        EXPECT_TRUE(double_eq(static_cast<double>(d), 25.0));
        EXPECT_TRUE(double_eq(static_cast<double>(e), 4.0));
        EXPECT_TRUE(double_eq(static_cast<double>(f), 6.0));
    }
    {
        Rhomb a(Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1));
        Rhomb b(Vector2D(0, 0), Vector2D(2, 3), Vector2D(4, 0), Vector2D(2, -3));
        Rhomb c(Vector2D(3, 2), Vector2D(5, 5), Vector2D(2, 3), Vector2D(0, 0));
        
        EXPECT_TRUE(double_eq(static_cast<double>(a), 2.0));
        EXPECT_TRUE(double_eq(static_cast<double>(b), 12.0));
        EXPECT_TRUE(double_eq(static_cast<double>(c), 5.0));
    }
    {
        Trapezoid a(Vector2D(1, -3), Vector2D(4, -2), Vector2D(4, -1), Vector2D(1, 1));
        Trapezoid b(Vector2D(5, 5), Vector2D(3, 3), Vector2D(4, 1), Vector2D(5, 2));
        Trapezoid c(Vector2D(5, 2), Vector2D(5, 5), Vector2D(3, 3), Vector2D(4, 1));
        
        EXPECT_TRUE(double_eq(static_cast<double>(a), 7.5));
        EXPECT_TRUE(double_eq(static_cast<double>(b), 4.5));
        EXPECT_TRUE(double_eq(static_cast<double>(c), 4.5));
    }
}

TEST(FigureTest, OperatorEquals) {
    {
        Rectangle a(Vector2D(0, 0), Vector2D(0, 2), Vector2D(3, 2), Vector2D(3, 0));
        EXPECT_TRUE(a == Rectangle(Vector2D(0, 0), Vector2D(0, 2), Vector2D(3, 2), Vector2D(3, 0)));
        EXPECT_TRUE(a == Rectangle(Vector2D(1, 1), Vector2D(1, 3), Vector2D(4, 3), Vector2D(4, 1)));
        EXPECT_TRUE(a == Rectangle(Vector2D(-1, 0), Vector2D(-1, -2), Vector2D(2, -2), Vector2D(2, 0)));
        
        EXPECT_FALSE(a == Rectangle(Vector2D(1, 0), Vector2D(1, 4), Vector2D(4, 4), Vector2D(4, 0)));
        EXPECT_FALSE(a == Rectangle(Vector2D(0, 0), Vector2D(0, 3), Vector2D(4, 3), Vector2D(4, 0)));
        EXPECT_FALSE(a == Rectangle(Vector2D(0, 0), Vector2D(0, 1), Vector2D(1, 1), Vector2D(1, 0)));
        EXPECT_FALSE(a == Rectangle(Vector2D(-1, -1), Vector2D(-1, 1), Vector2D(5, 1), Vector2D(5, -1)));
    }
    {
        EXPECT_TRUE(Rhomb(Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1)) == 
                    Rhomb(Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1)));
        EXPECT_TRUE(Rhomb(Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1)) == 
                    Rhomb(Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1), Vector2D(0, 0)));
        EXPECT_TRUE(Rhomb(Vector2D(-1, 0), Vector2D(0, 3), Vector2D(1, 0), Vector2D(0, -3)) == 
                    Rhomb(Vector2D(-4, 0), Vector2D(-1, 1), Vector2D(2, 0), Vector2D(-1, -1)));
        EXPECT_TRUE(Rhomb(Vector2D(4, 2), Vector2D(6, 5), Vector2D(3, 3), Vector2D(1, 0)) == 
                    Rhomb(Vector2D(0, 5), Vector2D(3, 3), Vector2D(5, 0), Vector2D(2, 2)));
        
        EXPECT_FALSE(Rhomb(Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1)) == 
                    Rhomb(Vector2D(0, 5), Vector2D(3, 3), Vector2D(5, 0), Vector2D(2, 2)));
        EXPECT_FALSE(Rhomb(Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1)) == 
                    Rhomb(Vector2D(-1, 0), Vector2D(0, 3), Vector2D(1, 0), Vector2D(0, -3)));
        EXPECT_FALSE(Rhomb(Vector2D(-1, 0), Vector2D(0, 3), Vector2D(1, 0), Vector2D(0, -3)) == 
                    Rhomb(Vector2D(4, 2), Vector2D(6, 5), Vector2D(3, 3), Vector2D(1, 0)));
    }
    {
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(4, 0), Vector2D(3, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(5, 5), Vector2D(9, 5), Vector2D(8, 7), Vector2D(6, 7)));
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(4, 0), Vector2D(3, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(0, 4), Vector2D(-2, 3), Vector2D(-2, 1)));
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(4, 0), Vector2D(3, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(-4, 0), Vector2D(-3, 2), Vector2D(-1, 2)));
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(4, 0), Vector2D(3, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(10, 1), Vector2D(6, 1), Vector2D(7, 3), Vector2D(9, 3)));
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(6, 0), Vector2D(4, 3), Vector2D(2, 3)) == 
                    Trapezoid(Vector2D(5, 5), Vector2D(-1, 5), Vector2D(1, 2), Vector2D(3, 2)));
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(2, 3), Vector2D(4, 3), Vector2D(6, 0)) == 
                    Trapezoid(Vector2D(6, 0), Vector2D(4, 3), Vector2D(2, 3), Vector2D(0, 0)));
        
        EXPECT_FALSE(Trapezoid(Vector2D(0, 0), Vector2D(6, 0), Vector2D(4, 2), Vector2D(2, 2)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(6, 0), Vector2D(5, 2), Vector2D(1, 2)));
        EXPECT_FALSE(Trapezoid(Vector2D(0, 0), Vector2D(5, 0), Vector2D(4, 3), Vector2D(1, 3)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(5, 0), Vector2D(4, 1), Vector2D(1, 1)));
        EXPECT_FALSE(Trapezoid(Vector2D(0, 0), Vector2D(4, 0), Vector2D(3, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(6, 0), Vector2D(5, 2), Vector2D(1, 2)));
        EXPECT_FALSE(Trapezoid(Vector2D(0, 0), Vector2D(5, 0), Vector2D(3, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(5, 0), Vector2D(3, 2), Vector2D(0, 2)));
        EXPECT_FALSE(Trapezoid(Vector2D(0, 0), Vector2D(5, 0), Vector2D(4, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(5, 0), Vector2D(4, 2), Vector2D(2, 2)));
        EXPECT_FALSE(Trapezoid(Vector2D(0, 0), Vector2D(4, 0), Vector2D(3, 2), Vector2D(1, 2)) == 
                    Trapezoid(Vector2D(0, 0), Vector2D(8, 0), Vector2D(6, 4), Vector2D(2, 4)));
    }
}

TEST(FigureTest, OperatorOStream) {
    {
        Rectangle a(Vector2D(0, 0), Vector2D(0, 2), Vector2D(3, 2), Vector2D(3, 0));
        std::stringstream ss;
        ss << a;
        EXPECT_EQ(ss.str(), "Rectangle: [ (0, 0), (0, 2), (3, 2), (3, 0) ]");
    }
    {
        Trapezoid a(Vector2D(0, 0), Vector2D(2.5, 3), Vector2D(4.78, 3), Vector2D(6, 0));
        std::stringstream ss;
        ss << a;
        EXPECT_EQ(ss.str(), "Trapezoid: [ (0, 0), (2.5, 3), (4.78, 3), (6, 0) ]");
    }
    {
        Rhomb a(Vector2D(-3, 1), Vector2D(1, 5), Vector2D(5, 1), Vector2D(1, -3));
        std::stringstream ss;
        ss << a;
        EXPECT_EQ(ss.str(), "Rhomb: [ (-3, 1), (1, 5), (5, 1), (1, -3) ]");
    }
}

TEST(FigureTest, OperatorIStream) {
    {
        Rectangle a;

        std::stringstream ss1("0 0 0 2 3 2 3 0");
        std::stringstream ss2("0 0 0 5 5 5 5 0");
        std::stringstream ss3("-1 -1 -1 1 1 1 1 -1");
        EXPECT_NO_THROW(ss1 >> a);
        EXPECT_NO_THROW(ss2 >> a);
        EXPECT_NO_THROW(ss3 >> a);

        std::stringstream ss4("0 0 0 2 3 3 3 0");
        std::stringstream ss5("0 0 3 2 3 0 0 2");
        EXPECT_THROW(ss4 >> a, std::invalid_argument);
        EXPECT_THROW(ss5 >> a, std::invalid_argument);
    }
    {
        Trapezoid a;
        
        std::stringstream ss1("0 0 5 0 4 3 1 3");
        std::stringstream ss2("1 1 7 1 5 4 3 4");
        std::stringstream ss3("2 2 8 2 6 6 3 6");
        std::stringstream ss4("3 3 5 5 5 2 4 1");
        EXPECT_NO_THROW(ss1 >> a);
        EXPECT_NO_THROW(ss2 >> a);
        EXPECT_NO_THROW(ss3 >> a);
        EXPECT_NO_THROW(ss4 >> a);

        std::stringstream ss5("1 1 5 2 7 7 0 5");
        std::stringstream ss6("0 0 3 0 4 3 1 4");
        std::stringstream ss7("0 0 4 0 1 1 3 1");
        std::stringstream ss8("0 0 1 1 1 1 1 0");
        EXPECT_THROW(ss5 >> a, std::invalid_argument);
        EXPECT_THROW(ss6 >> a, std::invalid_argument);
        EXPECT_THROW(ss7 >> a, std::invalid_argument);
        EXPECT_THROW(ss8 >> a, std::invalid_argument);
    }
    {
        Rhomb a;

        std::stringstream ss1("0 1 1 0 0 -1 -1 0");
        std::stringstream ss2("0 2 2 0 0 -2 -2 0");
        std::stringstream ss3("-2 -2 -1 0 1 1 0 -1");
        EXPECT_NO_THROW(ss1 >> a);
        EXPECT_NO_THROW(ss2 >> a);
        EXPECT_NO_THROW(ss3 >> a);

        std::stringstream ss4("0 1 1 0 0 2 -1 0");
        std::stringstream ss5("0 1 2 0 0 -2 -1 0");
        EXPECT_THROW(ss4 >> a, std::invalid_argument);
        EXPECT_THROW(ss5 >> a, std::invalid_argument);
    }
}

TEST(FigureTest, CalcCentre) {
    {
        EXPECT_TRUE(Rectangle(Vector2D(0, 0), Vector2D(0, 2), Vector2D(2, 2), Vector2D(2, 0)).calc_centre() == Vector2D(1, 1));
        EXPECT_TRUE(Rectangle(Vector2D(1, 1), Vector2D(1, 3), Vector2D(3, 3), Vector2D(3, 1)).calc_centre() == Vector2D(2, 2));
        EXPECT_TRUE(Rectangle(Vector2D(-1, -1), Vector2D(-1, 1), Vector2D(1, 1), Vector2D(1, -1)).calc_centre() == Vector2D(0, 0));
    }
    {
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(1, 2), Vector2D(3, 2), Vector2D(4, 0)).calc_centre() == Vector2D(2, 1));
        EXPECT_TRUE(Trapezoid(Vector2D(0, 0), Vector2D(2, 3), Vector2D(4, 3), Vector2D(6, 0)).calc_centre() == Vector2D(3, 1.5));
        EXPECT_TRUE(Trapezoid(Vector2D(-2, 0), Vector2D(-1, 1), Vector2D(1, 1), Vector2D(2, 0)).calc_centre() == Vector2D(0, 0.5));
        EXPECT_TRUE(Trapezoid(Vector2D(5, 2), Vector2D(5, 5), Vector2D(3, 3), Vector2D(4, 1)).calc_centre() == Vector2D(4.25, 2.75));
    }
    {
        EXPECT_TRUE(Rhomb(Vector2D(0, 0), Vector2D(1, 1), Vector2D(2, 0), Vector2D(1, -1)).calc_centre() == Vector2D(1, 0));
        EXPECT_TRUE(Rhomb(Vector2D(0, 0), Vector2D(2, 2), Vector2D(4, 0), Vector2D(2, -2)).calc_centre() == Vector2D(2, 0));
        EXPECT_TRUE(Rhomb(Vector2D(-1, 0), Vector2D(0, 1), Vector2D(1, 0), Vector2D(0, -1)).calc_centre() == Vector2D(0, 0));
    }
}