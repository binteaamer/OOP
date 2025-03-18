/*Picture an innovative design tool aimed at architects and graphic designers that allows for creating,
manipulating, and analyzing various geometric shapes. The system is structured around a Shape class,
which includes data members such as position, color, and an optional borderThickness. It provides functions 
like draw() for rendering, calculateArea() for area measurement, and calculatePerimeter() for perimeter computation.

Derived classes such as Circle, Rectangle, Triangle, and Polygon introduce their own properties—for example, 
a Circle includes radius and center position, while a Rectangle includes width, height, and top-left corner position. 
Each derived class overrides draw(), calculateArea(), and calculatePerimeter() to handle their respective geometries.
*/


#include <iostream>
#include <string>
using namespace std;

// Structure to represent a 2D point
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}  
};

// Base class Shape
class shape {
protected:
    Point position;
    string color;
    double borderThickness;

public:
    shape() : position(Point()), color("Black"), borderThickness(1.0) {}  

    shape(Point pos, string c = "Black", double t = 1.0) 
        : position(pos), color(c), borderThickness(t) {}

    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    string getColor() const { return color; } // Getter for color
};

// Derived class Circle
class circle : public shape {
    double radius;
    Point center;

public:
    circle(Point centerPos, double r, string c = "Black", double border = 1.0)
        : shape(centerPos, c, border), center(centerPos), radius(r) {}

    void draw() override {
        cout << "Drawing a Circle at (" << center.x << ", " << center.y 
             << ") with radius " << radius << " and color " << getColor() << ".\n";
    }

    double calculateArea() override {
        return 3.14159 * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * 3.14159 * radius;
    }
};

// Derived class Rectangle
class rectangle : public shape {
    double width;
    double height;
    Point topLeft;

public:
    rectangle(Point topLeftPos, double w, double h, string c = "Black", double border = 1.0)
        : shape(topLeftPos, c, border), topLeft(topLeftPos), width(w), height(h) {}

    void draw() override {
        cout << "Drawing a Rectangle at (" << topLeft.x << ", " << topLeft.y 
             << ") with width " << width << " and height " << height 
             << " and color " << getColor() << ".\n";
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

// Derived class Triangle
class triangle : public shape {
    double base, height;

public:
    triangle(Point pos, double b, double h, string c = "Black", double border = 1.0)
        : shape(pos, c, border), base(b), height(h) {}

    void draw() override {
        cout << "Drawing a Triangle with base " << base << " and height " << height 
             << " and color " << getColor() << ".\n";
    }

    double calculateArea() override {
        return 0.5 * base * height;
    }

    double calculatePerimeter() override {
        return base + 2 * sqrt((height * height) + (base / 2) * (base / 2)); // Assuming an isosceles triangle
    }
};

// Polygon class (Placeholder)
class polygon : public shape {
public:
    void draw() override {
        cout << "Drawing a Polygon.\n";
    }

    double calculateArea() override {
        return 0;  // Placeholder
    }

    double calculatePerimeter() override {
        return 0;  // Placeholder
    }
};

// Main function to test the classes
int main() {
    // Creating a Circle object
    Point circleCenter(5, 10);
    circle c1(circleCenter, 7, "Red", 2.0);
    c1.draw();
    cout << "Circle Area: " << c1.calculateArea() << endl;
    cout << "Circle Perimeter: " << c1.calculatePerimeter() << endl;

    // Creating a Rectangle object
    Point rectTopLeft(0, 5);
    rectangle r1(rectTopLeft, 4, 6, "Blue", 1.5);
    r1.draw();
    cout << "Rectangle Area: " << r1.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r1.calculatePerimeter() << endl;

    return 0;
}


