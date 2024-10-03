#include "Furniture.h"

int main() {
    FurnitureSystem sys;
    int n = 0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string order;
        cin >> order;
        sys.processOrder(order);
    }
}