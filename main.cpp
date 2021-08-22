#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Shape
{
public:

     static string getType() { return("Shape"); }
     double getArea() const { return 0;  }
     double getPerimeter() const { return 0;  }
};

class Square : public Shape
{

public:

    // Constructor
    Square(double in_length) : length{ in_length } 
    {
    }
    
    // I made getType static to get more practice with static methods.
    static string getType() { return "Square"; }
    double getArea() const { return (length * length); }
    double getPerimeter() const { return (length * 4); }

private:

    double length;

};

class Triangle : public Shape
{

public:

    // Constructor
    Triangle(double in_side_a, double in_side_b, double in_side_c) : side_a{ in_side_a }, side_b{ in_side_b }, side_c{in_side_c}
    {
    }

    static string getType() { return "Triangle"; }
    
    // I'm not that good with geometry and all that stuff so I just searched up a random formula and just copied that haha 
    double getArea() const 
    {
        double s = (side_a + side_b + side_c) / 2;
        double area = (s - side_a) * (s - side_b) * (s - side_c) * s;
        return sqrt(area);
    }

    // I probably got this wrong I just got lazy and added all the sides together
    double getPerimeter() const { return (side_a + side_b + side_c); }

private:

    double side_a;
    double side_b;
    double side_c;

};

static void doShow(const vector<Shape*>& shapes)
{
    for (auto shape : shapes)
    {
        std::cout << "Type: " << shape->getType() <<
            ", Area: " << shape->getArea() << ", Perimeter: " << shape->getPerimeter() << "\n";
    }
}

int main()
{
    Triangle e(5, 5, 5);
    cout << e.getArea() << endl;

    return(0);
}
