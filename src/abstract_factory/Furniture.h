#include <string>
#include <memory>
#include <iostream>

using namespace std;
 
class Chair {
public:
    virtual string toString() const  = 0;
};
 
class ModernChair : public Chair {
public:
    virtual string toString() const {
        return "modern chair";
    }
};
 
class ClassicalChair : public Chair {
public:
    virtual string toString() const {
        return "classical chair";
    }
};
 
class Sofa {
public:
    virtual string toString() const = 0;
};
 
class ModernSofa : public Sofa {
public:
    virtual string toString() const {
        return "modern sofa";
    }
};
 
class ClassicalSofa : public Sofa {
public:
    virtual string toString() const {
        return "classical sofa";
    }
};
 
class AbstractFactory {
public:
    virtual shared_ptr<Chair> createChair() = 0;
    virtual shared_ptr<Sofa> createSofa() = 0;
};
 
class ModernFactory : public AbstractFactory {
public:
    virtual shared_ptr<Chair> createChair() {
        return make_shared<ModernChair>();
    }
 
    virtual shared_ptr<Sofa> createSofa() {
        return make_shared<ModernSofa>();
    }
};
 
class ClassicalFactory : public AbstractFactory {
public:
    virtual shared_ptr<Chair> createChair() {
        return make_shared<ClassicalChair>();
    }
 
    virtual shared_ptr<Sofa> createSofa() {
        return make_shared<ClassicalSofa>();
    }
};
 
ostream &operator<<(ostream &os, const Chair &chair) {
    return os << chair.toString();
}
 
ostream &operator<<(ostream &os, const Sofa &sofa) {
    return os << sofa.toString();
}
 
class FurnitureSystem {
public:
    void processOrder(const string &order) {
        shared_ptr<Chair> chair;
        shared_ptr<Sofa> sofa;
        if (order == "modern") {
            chair = modern_factory.createChair();
            sofa = modern_factory.createSofa();
        } else if (order == "classical") {
            chair = classical_factory.createChair();
            sofa = classical_factory.createSofa();
        }
        if (chair && sofa) {
            cout << *chair << '\n' << *sofa << endl;
        }
    }
private:
    ModernFactory modern_factory;
    ClassicalFactory classical_factory;
};