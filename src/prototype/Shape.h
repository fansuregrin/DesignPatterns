#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include <cmath>

using namespace std;

class Shape {
public:
    Shape() : m_x(0), m_y(0) {}
    Shape(int x, int y) : m_x(x), m_y(y) {}
    virtual ~Shape() {}
    virtual unique_ptr<Shape> clone() const = 0;
    virtual string toString() const = 0;
    virtual double area() const = 0;
protected:
    int m_x, m_y;
};

ostream &operator<<(ostream &os, const Shape &shape) {
    return os << shape.toString();
}

class Rect : public Shape {
public:
    Rect(int x, int y, int width, int height)
        :Shape(x, y), m_width(width), m_height(height) {}

    Rect(const Rect &other)
        : Shape(other.m_x, other.m_y), m_width(other.m_width), m_height(other.m_height) {}

    Rect &operator=(const Rect &rhs) {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        m_height = rhs.m_height;
        m_width = rhs.m_width;
        return *this;
    }

    virtual unique_ptr<Shape> clone() const {
        return unique_ptr<Shape>(new Rect(*this));
    }

    virtual string toString() const {
        char buf[128]{0};
        snprintf(buf, sizeof(buf)-1, "<Rect: (%d, %d, %d, %d)> at %p",
            m_x, m_y, m_width, m_height, this);
        return buf;
    }

    virtual double area() const {
        return m_width * m_height;
    }
private:
    int m_width, m_height;
};

class Circle : public Shape {
public:
    Circle(int x, int y, int radius) : Shape(x, y), m_radius(radius) {}
    
    Circle(const Circle &other) : Shape(other.m_x, other.m_y), m_radius(other.m_radius) {}

    Circle &operator=(const Circle &rhs) {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        m_radius = rhs.m_radius;
        return *this;
    }

    virtual unique_ptr<Shape> clone() const {
        return unique_ptr<Shape>(new Circle(*this));
    }

    virtual string toString() const {
        char buf[128]{0};
        snprintf(buf, sizeof(buf)-1, "<Circle: (%d, %d, %d)> at %p",
            m_x, m_y, m_radius, this);
        return buf;
    }

    virtual double area() const {
        return M_PI * powf64(m_radius, m_radius);
    }
private:
    int m_radius;
};