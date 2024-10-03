#include <vector>
#include <string>
#include <memory>
#include <iostream>

using namespace std;
 
class Block {
public:
    virtual string toString() const = 0;
    virtual ~Block() {}
};
 
class CircleBlock : public Block {
public:
    virtual string toString() const {
        return "Circle Block";
    }
};
 
class SquareBlock : public Block {
public:
    virtual string toString() const {
        return "Square Block";
    }
};
 
ostream &operator<<(ostream &os, const Block &blk) {
    return os << blk.toString();
}
 
class Factory {
public:
    virtual shared_ptr<Block> produce() = 0;
    virtual ~Factory() {}
};
 
class CircleFactory : public Factory {
public:
    virtual shared_ptr<Block> produce() {
        return make_shared<CircleBlock>();
    }
};
 
class SquareFactory : public Factory {
public:
    virtual shared_ptr<Block> produce() {
        return make_shared<SquareBlock>();
    }
};
 
class BlockFactorySystem {
public:
    void addBlocks(const string &type_str, int cnt) {
        Factory *pFactory = nullptr;
        if (type_str == "Circle") {
            pFactory = &circle_factory;
        } else if (type_str == "Square") {
            pFactory = &square_factory;
        }
        for (int i=0; pFactory && i<cnt; ++i) {
            blocks.emplace_back(pFactory->produce());
        }
    }
 
    void showBlocks() {
        for (const auto &i : blocks) {
            cout << *i << endl;
        }
    }
private:
    CircleFactory circle_factory;
    SquareFactory square_factory;
    vector<shared_ptr<Block>> blocks;
};
