#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;
 
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
private:
    Cart() {}
    ~Cart() {}
    vector<pair<string,int>> rcd;
};
 
int main() {
    auto &cart = Cart::getInstance();
    string goods;
    int cnt;
    while (cin >> goods >> cnt) {
        cart.add(goods, cnt);
    }
    cart.show();
}