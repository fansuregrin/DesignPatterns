#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Prototype {
public:
    virtual unique_ptr<Prototype> clone() const = 0;
    virtual string toString() const = 0;
    virtual ~Prototype() {}
};

class Rect : public Prototype {
public:
    Rect(const string &color, int width, int height)
        : m_color(color), m_width(width), m_height(height) {}

    Rect(const Rect &other) {
        m_color = other.m_color;
        m_width = other.m_width;
        m_height = other.m_height;
    }

    Rect &operator=(const Rect &rhs) {
        m_color = rhs.m_color;
        m_height = rhs.m_height;
        m_width = rhs.m_width;
        return *this;
    }

    virtual unique_ptr<Prototype> clone() const {
        return unique_ptr<Prototype>(new Rect(*this));
    }

    virtual string toString() const {
        return "Color: " + m_color + ", Width: " 
            + to_string(m_width) + ", Height: " + to_string(m_height);
    }
private:
    string m_color;
    int m_width, m_height;
};

ostream &operator<<(ostream &os, const Prototype &prototype) {
    return os << prototype.toString();
}