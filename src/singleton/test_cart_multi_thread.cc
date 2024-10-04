#include "Cart.h"
#include <thread>
#include <sstream>
#include <future>
#include <chrono>

using namespace std;

template <typename S>
void testSingleton() {
    auto task = []{
        this_thread::sleep_for(chrono::seconds(1));
        ostringstream oss;
        oss << "from thread " << this_thread::get_id()
            << ", got " << S::getInstance().toString();
        return oss.str();
    };
    auto ft1 = async(launch::async, task);
    auto ft2 = async(launch::async, task);
    auto ft3 = async(launch::async, task);
    auto ft4 = async(launch::async, task);
    cout << ft1.get() << endl;
    cout << ft2.get() << endl;
    cout << ft3.get() << endl;
    cout << ft4.get() << endl;
}

int main() {
    testSingleton<Cart>();
    testSingleton<Cart2>();
}