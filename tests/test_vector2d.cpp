#include <gtest/gtest.h>
#include "../include/vector2d.h"
#include "./test.h"
#include <sstream>
#include <cmath>

TEST(Vector2DTest, ConstructorDefault) {
    Vector2D v;
    EXPECT_TRUE(double_eq(v.get_x(), 0.0));
    EXPECT_TRUE(double_eq(v.get_y(), 0.0));
}

TEST(Vector2DTest, ConstructorWithValues) {
    Vector2D v1(1.0, 2.0);
    EXPECT_TRUE(double_eq(v1.get_x(), 1.0));
    EXPECT_TRUE(double_eq(v1.get_y(), 2.0));

    Vector2D v2(-3.5, 4.1);
    EXPECT_TRUE(double_eq(v2.get_x(), -3.5));
    EXPECT_TRUE(double_eq(v2.get_y(), 4.1));

    Vector2D v3(0.0, 0.0);
    EXPECT_TRUE(double_eq(v3.get_x(), 0.0));
    EXPECT_TRUE(double_eq(v3.get_y(), 0.0));

    Vector2D v4(1e9, -1e9);
    EXPECT_TRUE(double_eq(v4.get_x(), 1e9));
    EXPECT_TRUE(double_eq(v4.get_y(), -1e9));

    Vector2D v5(0.123, -0.456);
    EXPECT_TRUE(double_eq(v5.get_x(), 0.123));
    EXPECT_TRUE(double_eq(v5.get_y(), -0.456));
}

TEST(Vector2DTest, ConstructorCopy) {
    Vector2D original(5.0, -7.0);
    Vector2D copy(original);

    EXPECT_TRUE(double_eq(copy.get_x(), 5.0));
    EXPECT_TRUE(double_eq(copy.get_y(), -7.0));
    EXPECT_NE(&original, &copy);
}

TEST(Vector2DTest, OperatorPlusEqual) {
    Vector2D vA(1, 1);
    Vector2D vB(1, 1);
    vA += vB;
    EXPECT_TRUE(double_eq(vA.get_x(), 2.0));
    EXPECT_TRUE(double_eq(vA.get_y(), 2.0));

    Vector2D vC(-2, 3);
    Vector2D vD(4, -5);
    vC += vD;
    EXPECT_TRUE(double_eq(vC.get_x(), 2.0));
    EXPECT_TRUE(double_eq(vC.get_y(), -2.0));

    Vector2D vE(0, 0);
    Vector2D vF(5, 6);
    vE += vF;
    EXPECT_TRUE(double_eq(vE.get_x(), 5.0));
    EXPECT_TRUE(double_eq(vE.get_y(), 6.0));

    Vector2D vG(7, 8);
    Vector2D vH(0, 0);
    vG += vH;
    EXPECT_TRUE(double_eq(vG.get_x(), 7.0));
    EXPECT_TRUE(double_eq(vG.get_y(), 8.0));

    Vector2D vI(-10, -20);
    Vector2D vJ(-30, -40);
    vI += vJ;
    EXPECT_TRUE(double_eq(vI.get_x(), -40.0));
    EXPECT_TRUE(double_eq(vI.get_y(), -60.0));
}

TEST(Vector2DTest, OperatorMinusEqual) {
    Vector2D vA(5, 5);
    Vector2D vB(2, 2);
    vA -= vB;
    EXPECT_TRUE(double_eq(vA.get_x(), 3.0));
    EXPECT_TRUE(double_eq(vA.get_y(), 3.0));

    Vector2D vC(-2, 3);
    Vector2D vD(4, -5);
    vC -= vD;
    EXPECT_TRUE(double_eq(vC.get_x(), -6.0));
    EXPECT_TRUE(double_eq(vC.get_y(), 8.0));

    Vector2D vE(0, 0);
    Vector2D vF(5, 6);
    vE -= vF;
    EXPECT_TRUE(double_eq(vE.get_x(), -5.0));
    EXPECT_TRUE(double_eq(vE.get_y(), -6.0));

    Vector2D vG(7, 8);
    Vector2D vH(0, 0);
    vG -= vH;
    EXPECT_TRUE(double_eq(vG.get_x(), 7.0));
    EXPECT_TRUE(double_eq(vG.get_y(), 8.0));

    Vector2D vI(-10, -20);
    Vector2D vJ(-30, -40);
    vI -= vJ;
    EXPECT_TRUE(double_eq(vI.get_x(), 20.0));
    EXPECT_TRUE(double_eq(vI.get_y(), 20.0));
}

TEST(Vector2DTest, OperatorPlus) {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D result = v1 + v2;
    EXPECT_TRUE(double_eq(result.get_x(), 4.0));
    EXPECT_TRUE(double_eq(result.get_y(), 6.0));
    EXPECT_TRUE(double_eq(v1.get_x(), 1.0));
    EXPECT_TRUE(double_eq(v1.get_y(), 2.0));
    EXPECT_TRUE(double_eq(v2.get_x(), 3.0));
    EXPECT_TRUE(double_eq(v2.get_y(), 4.0));
}

TEST(Vector2DTest, OperatorMinus) {
    Vector2D v1(5.0, 6.0);
    Vector2D v2(2.0, 3.0);
    Vector2D result = v1 - v2;
    EXPECT_TRUE(double_eq(result.get_x(), 3.0));
    EXPECT_TRUE(double_eq(result.get_y(), 3.0));
    EXPECT_TRUE(double_eq(v1.get_x(), 5.0));
    EXPECT_TRUE(double_eq(v1.get_y(), 6.0));
    EXPECT_TRUE(double_eq(v2.get_x(), 2.0));
    EXPECT_TRUE(double_eq(v2.get_y(), 3.0));
}

TEST(Vector2DTest, OperatorMultiplyScalar) {
    Vector2D v(2.0, 3.0);
    double k = 2.5;
    Vector2D result = k * v;
    EXPECT_TRUE(double_eq(result.get_x(), 5.0));
    EXPECT_TRUE(double_eq(result.get_y(), 7.5));
    EXPECT_TRUE(double_eq(v.get_x(), 2.0));
    EXPECT_TRUE(double_eq(v.get_y(), 3.0));

    Vector2D vA(1, 2);
    double kA = 3;
    Vector2D resA = kA * vA;
    EXPECT_TRUE(double_eq(resA.get_x(), 3.0));
    EXPECT_TRUE(double_eq(resA.get_y(), 6.0));

    Vector2D vB(-3, 4);
    double kB = -0.5;
    Vector2D resB = kB * vB;
    EXPECT_TRUE(double_eq(resB.get_x(), 1.5));
    EXPECT_TRUE(double_eq(resB.get_y(), -2.0));

    Vector2D vC(0, 0);
    double kC = 100;
    Vector2D resC = kC * vC;
    EXPECT_TRUE(double_eq(resC.get_x(), 0.0));
    EXPECT_TRUE(double_eq(resC.get_y(), 0.0));

    Vector2D vD(5, 6);
    double kD = 0;
    Vector2D resD = kD * vD;
    EXPECT_TRUE(double_eq(resD.get_x(), 0.0));
    EXPECT_TRUE(double_eq(resD.get_y(), 0.0));

    Vector2D vE(1e6, 1e-6);
    double kE = 1e-3;
    Vector2D resE = kE * vE;
    EXPECT_TRUE(double_eq(resE.get_x(), 1e3));
    EXPECT_TRUE(double_eq(resE.get_y(), 1e-9));
}

TEST(Vector2DTest, OperatorEqual) {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(1.0, 2.0);
    Vector2D v3(1.0, 3.0);
    Vector2D v4(2.0, 2.0);

    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
    EXPECT_FALSE(v1 == v4);

    Vector2D vA(5, 5); Vector2D vB(5, 5); EXPECT_TRUE(vA == vB);
    Vector2D vC(5, 5); Vector2D vD(5, 6); EXPECT_FALSE(vC == vD);
    Vector2D vE(5, 5); Vector2D vF(6, 5); EXPECT_FALSE(vE == vF);
    Vector2D vG(0, 0); Vector2D vH(0, 0); EXPECT_TRUE(vG == vH);
    Vector2D vI(-1.23, 4.56); Vector2D vJ(-1.23, 4.56); EXPECT_TRUE(vI == vJ);
}

TEST(Vector2DTest, OperatorNotEqual) {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(1.0, 2.0);
    Vector2D v3(1.0, 3.0);
    Vector2D v4(2.0, 2.0);

    EXPECT_FALSE(v1 != v2);
    EXPECT_TRUE(v1 != v3);
    EXPECT_TRUE(v1 != v4);

    Vector2D vA(5, 5); Vector2D vB(5, 5); EXPECT_FALSE(vA != vB);
    Vector2D vC(5, 5); Vector2D vD(5, 6); EXPECT_TRUE(vC != vD);
    Vector2D vE(5, 5); Vector2D vF(6, 5); EXPECT_TRUE(vE != vF);
    Vector2D vG(0, 0); Vector2D vH(0, 0); EXPECT_FALSE(vG != vH);
    Vector2D vI(-1.23, 4.56); Vector2D vJ(-1.23, 4.56); EXPECT_FALSE(vI != vJ);
}

TEST(Vector2DTest, OperatorStreamOutput) {
    Vector2D v(1.5, -2.5);
    std::stringstream ss;
    ss << v;
    std::string output = ss.str();
    EXPECT_EQ(output, "(1.5, -2.5)");

    Vector2D vA(1, 2); std::stringstream ssA; ssA << vA;
    EXPECT_EQ(ssA.str(), "(1, 2)");

    Vector2D vB(-3, 4); std::stringstream ssB; ssB << vB;
    EXPECT_EQ(ssB.str(), "(-3, 4)");

    Vector2D vC(0, 0); std::stringstream ssC; ssC << vC;
    EXPECT_EQ(ssC.str(), "(0, 0)");

    Vector2D vD(0.123, -0.456); std::stringstream ssD; ssD << vD;
    EXPECT_EQ(ssD.str(), "(0.123, -0.456)");
}

TEST(Vector2DTest, OperatorStreamInput) {
    Vector2D v;
    std::stringstream ss("10.5 -5.2");
    ss >> v;
    EXPECT_TRUE(double_eq(v.get_x(), 10.5));
    EXPECT_TRUE(double_eq(v.get_y(), -5.2));

    Vector2D vA; std::stringstream ssA("5 10"); ssA >> vA;
    EXPECT_TRUE(double_eq(vA.get_x(), 5.0)); EXPECT_TRUE(double_eq(vA.get_y(), 10.0));

    Vector2D vB; std::stringstream ssB("-2 8"); ssB >> vB;
    EXPECT_TRUE(double_eq(vB.get_x(), -2.0)); EXPECT_TRUE(double_eq(vB.get_y(), 8.0));

    Vector2D vC; std::stringstream ssC("0 0"); ssC >> vC;
    EXPECT_TRUE(double_eq(vC.get_x(), 0.0)); EXPECT_TRUE(double_eq(vC.get_y(), 0.0));

    Vector2D vD; std::stringstream ssD("0.789 -0.123"); ssD >> vD;
    EXPECT_TRUE(double_eq(vD.get_x(), 0.789)); EXPECT_TRUE(double_eq(vD.get_y(), -0.123));

    Vector2D vE; std::stringstream ssE("1000000 -2000000"); ssE >> vE;
    EXPECT_TRUE(double_eq(vE.get_x(), 1e6)); EXPECT_TRUE(double_eq(vE.get_y(), -2e6));
}

TEST(Vector2DTest, VectorProductFactor) {
    Vector2D v1(1.0, 0.0);
    Vector2D v2(0.0, 1.0);
    EXPECT_TRUE(double_eq(vector_product_factor(v1, v2), 1.0));

    Vector2D v3(0.0, 1.0);
    Vector2D v4(1.0, 0.0);
    EXPECT_TRUE(double_eq(vector_product_factor(v3, v4), -1.0));

    Vector2D vA(2, 3); Vector2D vB(4, 5);
    EXPECT_TRUE(double_eq(vector_product_factor(vA, vB), -2.0));

    Vector2D vC(1, 0); Vector2D vD(1, 0);
    EXPECT_TRUE(double_eq(vector_product_factor(vC, vD), 0.0));

    Vector2D vE(0, 1); Vector2D vF(0, 1);
    EXPECT_TRUE(double_eq(vector_product_factor(vE, vF), 0.0));

    Vector2D vG(1, 1); Vector2D vH(-1, 1);
    EXPECT_TRUE(double_eq(vector_product_factor(vG, vH), 2.0));

    Vector2D vI(3, -2); Vector2D vJ(-1, 4);
    EXPECT_TRUE(double_eq(vector_product_factor(vI, vJ), 10.0));
}

TEST(Vector2DTest, ScalarProduct) {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    EXPECT_TRUE(double_eq(scalar_product(v1, v2), 11.0));

    Vector2D vA(2, 3); Vector2D vB(4, 5);
    EXPECT_TRUE(double_eq(scalar_product(vA, vB), 23.0));

    Vector2D vC(1, 0); Vector2D vD(0, 1);
    EXPECT_TRUE(double_eq(scalar_product(vC, vD), 0.0));

    Vector2D vE(-1, -2); Vector2D vF(-3, -4);
    EXPECT_TRUE(double_eq(scalar_product(vE, vF), 11.0));

    Vector2D vG(0, 0); Vector2D vH(5, 6);
    EXPECT_TRUE(double_eq(scalar_product(vG, vH), 0.0));

    Vector2D vI(10, 20); Vector2D vJ(0.1, 0.2);
    EXPECT_TRUE(double_eq(scalar_product(vI, vJ), 5.0));
}

TEST(Vector2DTest, DistToLine) {
    Vector2D target(5, 5);
    Vector2D p1(0, 0);
    Vector2D p2(10, 0);
    EXPECT_TRUE(double_eq(dist_to_line(target, p1, p2), 5.0));

    Vector2D targetA(1, 1); Vector2D p1A(0, 0); Vector2D p2A(2, 0);
    EXPECT_TRUE(double_eq(dist_to_line(targetA, p1A, p2A), 1.0));

    Vector2D targetB(0, 0); Vector2D p1B(1, 1); Vector2D p2B(3, 3);
    EXPECT_TRUE(double_eq(dist_to_line(targetB, p1B, p2B), 0.0));

    Vector2D targetC(0, 5); Vector2D p1C(0, 0); Vector2D p2C(0, 10);
    EXPECT_TRUE(double_eq(dist_to_line(targetC, p1C, p2C), 0.0));

    Vector2D targetD(3, 4); Vector2D p1D(0, 0); Vector2D p2D(6, 8);
    EXPECT_TRUE(double_eq(dist_to_line(targetD, p1D, p2D), 0.0));

    Vector2D targetE(0, 0); Vector2D p1E(0, 2); Vector2D p2E(2, 0);
    EXPECT_TRUE(double_eq(dist_to_line(targetE, p1E, p2E), std::sqrt(2.0)));
}

TEST(Vector2DTest, OperatorMultiplyScalarMember) {
    Vector2D v(2.0, 3.0);
    double k = 2.5;
    Vector2D result = v * k;
    EXPECT_TRUE(double_eq(result.get_x(), 5.0));
    EXPECT_TRUE(double_eq(result.get_y(), 7.5));
    EXPECT_TRUE(double_eq(v.get_x(), 2.0));
    EXPECT_TRUE(double_eq(v.get_y(), 3.0));

    Vector2D vA(1, 2); double kA = 3; Vector2D resA = vA * kA;
    EXPECT_TRUE(double_eq(resA.get_x(), 3.0)); EXPECT_TRUE(double_eq(resA.get_y(), 6.0));

    Vector2D vB(-3, 4); double kB = -0.5; Vector2D resB = vB * kB;
    EXPECT_TRUE(double_eq(resB.get_x(), 1.5)); EXPECT_TRUE(double_eq(resB.get_y(), -2.0));

    Vector2D vC(0, 0); double kC = 100; Vector2D resC = vC * kC;
    EXPECT_TRUE(double_eq(resC.get_x(), 0.0)); EXPECT_TRUE(double_eq(resC.get_y(), 0.0));

    Vector2D vD(5, 6); double kD = 0; Vector2D resD = vD * kD;
    EXPECT_TRUE(double_eq(resD.get_x(), 0.0)); EXPECT_TRUE(double_eq(resD.get_y(), 0.0));

    Vector2D vE(1e6, 1e-6); double kE = 1e-3; Vector2D resE = vE * kE;
    EXPECT_TRUE(double_eq(resE.get_x(), 1e3)); EXPECT_TRUE(double_eq(resE.get_y(), 1e-9));
}

TEST(Vector2DTest, OperatorDivideScalar) {
    Vector2D v(10.0, -4.0);
    double k = 2.0;
    Vector2D result = v / k;
    EXPECT_TRUE(double_eq(result.get_x(), 5.0));
    EXPECT_TRUE(double_eq(result.get_y(), -2.0));
    EXPECT_TRUE(double_eq(v.get_x(), 10.0));
    EXPECT_TRUE(double_eq(v.get_y(), -4.0));

    Vector2D vA(6, 8); double kA = 2; Vector2D resA = vA / kA;
    EXPECT_TRUE(double_eq(resA.get_x(), 3.0)); EXPECT_TRUE(double_eq(resA.get_y(), 4.0));

    Vector2D vB(-5, 10); double kB = -5; Vector2D resB = vB / kB;
    EXPECT_TRUE(double_eq(resB.get_x(), 1.0)); EXPECT_TRUE(double_eq(resB.get_y(), -2.0));

    Vector2D vC(0, 0); double kC = 10; Vector2D resC = vC / kC;
    EXPECT_TRUE(double_eq(resC.get_x(), 0.0)); EXPECT_TRUE(double_eq(resC.get_y(), 0.0));

    Vector2D vD(7, 9); double kD = 1; Vector2D resD = vD / kD;
    EXPECT_TRUE(double_eq(resD.get_x(), 7.0)); EXPECT_TRUE(double_eq(resD.get_y(), 9.0));

    Vector2D vE(1e6, 1e-6); double kE = 1e3; Vector2D resE = vE / kE;
    EXPECT_TRUE(double_eq(resE.get_x(), 1e3)); EXPECT_TRUE(double_eq(resE.get_y(), 1e-9));
}

TEST(Vector2DTest, OperatorMultiplyEqualScalar) {
    Vector2D v(2.0, 3.0);
    double k = 2.5;
    v *= k;
    EXPECT_TRUE(double_eq(v.get_x(), 5.0));
    EXPECT_TRUE(double_eq(v.get_y(), 7.5));

    Vector2D vA(1, 2); double kA = 3; vA *= kA;
    EXPECT_TRUE(double_eq(vA.get_x(), 3.0)); EXPECT_TRUE(double_eq(vA.get_y(), 6.0));

    Vector2D vB(-3, 4); double kB = -0.5; vB *= kB;
    EXPECT_TRUE(double_eq(vB.get_x(), 1.5)); EXPECT_TRUE(double_eq(vB.get_y(), -2.0));

    Vector2D vC(0, 0); double kC = 100; vC *= kC;
    EXPECT_TRUE(double_eq(vC.get_x(), 0.0)); EXPECT_TRUE(double_eq(vC.get_y(), 0.0));

    Vector2D vD(5, 6); double kD = 0; vD *= kD;
    EXPECT_TRUE(double_eq(vD.get_x(), 0.0)); EXPECT_TRUE(double_eq(vD.get_y(), 0.0));

    Vector2D vE(1e6, 1e-6); double kE = 1e-3; vE *= kE;
    EXPECT_TRUE(double_eq(vE.get_x(), 1e3)); EXPECT_TRUE(double_eq(vE.get_y(), 1e-9));
}

TEST(Vector2DTest, OperatorDivideEqualScalar) {
    Vector2D v(10.0, -4.0);
    double k = 2.0;
    v /= k;
    EXPECT_TRUE(double_eq(v.get_x(), 5.0));
    EXPECT_TRUE(double_eq(v.get_y(), -2.0));

    Vector2D vA(6, 8); double kA = 2; vA /= kA;
    EXPECT_TRUE(double_eq(vA.get_x(), 3.0)); EXPECT_TRUE(double_eq(vA.get_y(), 4.0));

    Vector2D vB(-5, 10); double kB = -5; vB /= kB;
    EXPECT_TRUE(double_eq(vB.get_x(), 1.0)); EXPECT_TRUE(double_eq(vB.get_y(), -2.0));

    Vector2D vC(0, 0); double kC = 10; vC /= kC;
    EXPECT_TRUE(double_eq(vC.get_x(), 0.0)); EXPECT_TRUE(double_eq(vC.get_y(), 0.0));

    Vector2D vD(7, 9); double kD = 1; vD /= kD;
    EXPECT_TRUE(double_eq(vD.get_x(), 7.0)); EXPECT_TRUE(double_eq(vD.get_y(), 9.0));

    Vector2D vE(1e6, 1e-6); double kE = 1e3; vE /= kE;
    EXPECT_TRUE(double_eq(vE.get_x(), 1e3)); EXPECT_TRUE(double_eq(vE.get_y(), 1e-9));
}

TEST(Vector2DTest, Length) {
    Vector2D v(3.0, 4.0);
    EXPECT_TRUE(double_eq(v.length(), 5.0));

    Vector2D vA(0, 0);
    EXPECT_TRUE(double_eq(vA.length(), 0.0));

    Vector2D vB(1, 0);
    EXPECT_TRUE(double_eq(vB.length(), 1.0));

    Vector2D vC(0, -1);
    EXPECT_TRUE(double_eq(vC.length(), 1.0));

    Vector2D vD(5, 12);
    EXPECT_TRUE(double_eq(vD.length(), 13.0));

    Vector2D vE(-6, -8);
    EXPECT_TRUE(double_eq(vE.length(), 10.0));
}

TEST(Vector2DTest, AbsEq) {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(1.0, 2.0);
    EXPECT_TRUE(v1.abs_eq(v2));

    Vector2D v3(1.0, 0.0);
    Vector2D v4(1.0 + Vector2D::eps / 2.0, 0.0);
    EXPECT_TRUE(v3.abs_eq(v4));

    Vector2D v5(1.0 + Vector2D::eps * 2.0, 0.0);
    EXPECT_FALSE(v3.abs_eq(v5));
}

TEST(Vector2DTest, AngleTo) {
    Vector2D v1(1.0, 0.0);
    Vector2D v2(0.0, 1.0);
    EXPECT_TRUE(double_eq(v1.angle_to(v2), M_PI / 2.0));

    Vector2D v3(1.0, 0.0);
    Vector2D v4(1.0, 0.0);
    EXPECT_TRUE(double_eq(v3.angle_to(v4), 0.0));

    Vector2D vA(1, 0); Vector2D vB(0, 1);
    EXPECT_TRUE(double_eq(vA.angle_to(vB), M_PI / 2.0));

    Vector2D vC(1, 0); Vector2D vD(-1, 0);
    EXPECT_TRUE(double_eq(vC.angle_to(vD), M_PI));

    Vector2D vE(1, 1); Vector2D vF(1, 0);
    EXPECT_TRUE(double_eq(vE.angle_to(vF), M_PI / 4.0));

    Vector2D vG(0, 0); Vector2D vH(1, 0);
    EXPECT_ANY_THROW(vG.angle_to(vH));

    Vector2D vI(1, 0); Vector2D vJ(0, -1);
    EXPECT_TRUE(double_eq(vI.angle_to(vJ), M_PI / 2.0));
}

TEST(Vector2DTest, Print) {
    Vector2D v(3.14, -2.71);
    std::stringstream ss;
    v.print(ss);
    EXPECT_EQ(ss.str(), "(3.14, -2.71)");

    Vector2D vA(1, 2); std::stringstream ssA; vA.print(ssA);
    EXPECT_EQ(ssA.str(), "(1, 2)");

    Vector2D vB(-5, 0); std::stringstream ssB; vB.print(ssB);
    EXPECT_EQ(ssB.str(), "(-5, 0)");

    Vector2D vC(0, 0); std::stringstream ssC; vC.print(ssC);
    EXPECT_EQ(ssC.str(), "(0, 0)");

    Vector2D vD(0.123, 0.456); std::stringstream ssD; vD.print(ssD);
    EXPECT_EQ(ssD.str(), "(0.123, 0.456)");
}

TEST(Vector2DTest, Read) {
    Vector2D v;
    std::stringstream ss("15.7 -9.3");
    v.read(ss);
    EXPECT_TRUE(double_eq(v.get_x(), 15.7));
    EXPECT_TRUE(double_eq(v.get_y(), -9.3));

    Vector2D vA; std::stringstream ssA("10 20"); vA.read(ssA);
    EXPECT_TRUE(double_eq(vA.get_x(), 10.0)); EXPECT_TRUE(double_eq(vA.get_y(), 20.0));

    Vector2D vB; std::stringstream ssB("-30 40"); vB.read(ssB);
    EXPECT_TRUE(double_eq(vB.get_x(), -30.0)); EXPECT_TRUE(double_eq(vB.get_y(), 40.0));

    Vector2D vC; std::stringstream ssC("0 0"); vC.read(ssC);
    EXPECT_TRUE(double_eq(vC.get_x(), 0.0)); EXPECT_TRUE(double_eq(vC.get_y(), 0.0));

    Vector2D vD; std::stringstream ssD("0.987 -0.654"); vD.read(ssD);
    EXPECT_TRUE(double_eq(vD.get_x(), 0.987)); EXPECT_TRUE(double_eq(vD.get_y(), -0.654));

    Vector2D vE; std::stringstream ssE("500000 -700000"); vE.read(ssE);
    EXPECT_TRUE(double_eq(vE.get_x(), 5e5)); EXPECT_TRUE(double_eq(vE.get_y(), -7e5));
}