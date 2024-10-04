#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Frame {
public:
    virtual string toString() const = 0;
    virtual unique_ptr<Frame> clone() const = 0;
    virtual ~Frame() {}
};

class AluminumFrame : public Frame {
public:
    virtual string toString() const {
        return "Aluminum Frame";
    }

    virtual unique_ptr<Frame> clone() const {
        return unique_ptr<Frame>(new AluminumFrame(*this));
    }
};

class CarbonFrame : public Frame {
public:
    virtual string toString() const {
        return "Carbon Frame";
    }

    virtual unique_ptr<Frame> clone() const {
        return unique_ptr<Frame>(new CarbonFrame(*this));
    }
};

class Tire {
public:
    virtual string toString() const = 0;
    virtual unique_ptr<Tire> clone() const = 0;
    virtual ~Tire() {}
};

class KnobbyTire : public Tire {
    virtual string toString() const {
        return "Knobby Tires";
    }

    virtual unique_ptr<Tire> clone() const {
        return unique_ptr<Tire>(new KnobbyTire(*this));
    }
};

class SlimTrie : public Tire {
    virtual string toString() const {
        return "Slim Tires";
    }

    virtual unique_ptr<Tire> clone() const {
        return unique_ptr<Tire>(new SlimTrie(*this));
    }
};

class Bike {
public:
    Bike() {}

    Bike(const Bike &other) {
        if (other.m_frame) {
            m_frame = other.m_frame->clone();
        }
        if (other.m_tire) {
            m_tire = other.m_tire->clone();
        }
    }

    Bike &operator=(const Bike &rhs) {
        if (rhs.m_frame) {
            m_frame = rhs.m_frame->clone();
        }
        if (rhs.m_tire) {
            m_tire = rhs.m_tire->clone();
        }
        return *this;
    }

    string toString() const {
        return m_frame->toString() + ' ' + m_tire->toString();
    }

    void setFrame(unique_ptr<Frame> frame) {
        m_frame.reset(frame.release());
    }

    void setTire(unique_ptr<Tire> tire) {
        m_tire.reset(tire.release());
    }
private:
    unique_ptr<Frame> m_frame;
    unique_ptr<Tire> m_tire;
};

ostream &operator<<(ostream &os, const Frame &frame) {
    return os << frame.toString();
}

ostream &operator<<(ostream &os, const Tire &tire) {
    return os << tire.toString();
}

ostream &operator<<(ostream &os, const Bike &bike) {
    return os << bike.toString();
}

class BikeBuilder {
public:
    virtual void setFrame() = 0;
    virtual void setTire() = 0;
    virtual ~BikeBuilder() {}
};

class MountainBikeBuilder : public BikeBuilder {
public:
    virtual void setFrame() {
        bike.setFrame(unique_ptr<Frame>(new AluminumFrame()));
    }

    virtual void setTire() {
        bike.setTire(unique_ptr<Tire>(new KnobbyTire()));
    }

    Bike getBike() {
        return bike;
    }
private:
    Bike bike;
};

class RoadBikeBuilder : public BikeBuilder {
public:
    virtual void setFrame() {
        bike.setFrame(unique_ptr<Frame>(new CarbonFrame()));
    }

    virtual void setTire() {
        bike.setTire(unique_ptr<Tire>(new SlimTrie()));
    }

    Bike getBike() {
        return bike;
    }
private:
    Bike bike;
};

class Director {
public:
    Director() : m_builder(nullptr) {}
    Director(shared_ptr<BikeBuilder> builder) : m_builder(builder) {}

    void build() {
        m_builder->setFrame();
        m_builder->setTire();
    }

    void setBuilder(shared_ptr<BikeBuilder> builder) {
        m_builder = builder;
    }
private:
    shared_ptr<BikeBuilder> m_builder;
};