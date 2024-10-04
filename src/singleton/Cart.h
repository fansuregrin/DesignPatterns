#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// thread-safe
class Cart {
public:
    static Cart &getInstance() {
        static Cart c;
        return c;
    }
     
    void add(const string &goods, int cnt) {
        rcd.push_back(make_pair(goods, cnt));
    }
     
    void show() const {
        for (const auto &i : rcd) {
            cout << i.first << ' ' << i.second << endl;
        }
    }

    string toString() {
        char buf[64]{0};
        snprintf(buf, sizeof(buf)-1, "<Cart, at %p>", this);
        return buf;
    }
private:
    Cart() {}
    ~Cart() {}
    vector<pair<string,int>> rcd;
};


// not thread-safe
class Cart2 {
public:
    static Cart2 &getInstance() {
        if (p_instance == nullptr) {
            p_instance = new Cart2();
        }
        return *p_instance;
    }
     
    void add(const string &goods, int cnt) {
        rcd.push_back(make_pair(goods, cnt));
    }
     
    void show() const {
        for (const auto &i : rcd) {
            cout << i.first << ' ' << i.second << endl;
        }
    }

    string toString() {
        char buf[64]{0};
        snprintf(buf, sizeof(buf)-1, "<Cart, at %p>", this);
        return buf;
    }
private:
    static Cart2 *p_instance; 
    Cart2() {}
    ~Cart2() {}
    vector<pair<string,int>> rcd;
};

Cart2 * Cart2::p_instance = nullptr;