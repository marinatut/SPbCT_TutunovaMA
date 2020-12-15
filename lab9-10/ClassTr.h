#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#define _USE_MATH_DEFINES
#define M_PI

class Triangle
{
private:
    double a, b, c;
public:
    Triangle() : a(0), b(0), c(0) {}
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {}

    ~Triangle() {}
    double perimeter() const { return a + b + c; }
    double area() const
    {
        double p = (b * b + c * c - a * a) / (2.0 * c * b);
        double angle_a = acos(p - static_cast<int>(p));
        return (b * c * sin(angle_a)) / 2.0;
    }
    bool is_possible() const { return ((a + b) > c) || ((b + c) > a) || ((a + c) > b); }
  
    friend std::ostream& operator<< (std::ostream& o, const Triangle& T)
    {
        o << "a: " << T.a << ", b: " << T.b << ", c: " << T.c << ". ";
        if (T.is_possible())
            o << "Ďëîůŕäü: " << T.area() << ", Ďĺđčěĺňđ: " << T.perimeter();
        else
            o << "Ňđĺóăîëüíčę íĺ ńóůĺńňâóĺň";
        return o;
    }
};
