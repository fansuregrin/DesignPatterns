#include <vector>
#include "Shape.h"

int main() {
    vector<shared_ptr<Shape>> shapes {
        shared_ptr<Shape>(new Rect(0, 0, 2 ,3)),
        shared_ptr<Shape>(new Circle(0, 1, 1))
    };
    cout << "traverse shapes:" << endl;
    for (const auto &shape : shapes) {
        cout << *shape << endl;
    }

    // clone
    vector<shared_ptr<Shape>> shapes2;
    for (const auto &shape : shapes) {
        shapes2.emplace_back(shape->clone());
    }
    cout << "traverse shapes2:" << endl;
    for (const auto &shape : shapes2) {
        cout << *shape << endl;
    }
}