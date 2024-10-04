#include "Cart.h"

int main() {
    auto &cart = Cart::getInstance();
    string goods;
    int cnt;
    while (cin >> goods >> cnt) {
        cart.add(goods, cnt);
    }
    cart.show();
}