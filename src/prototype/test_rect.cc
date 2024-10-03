#include "Rect.h"

int main() {
    string color;
    int width, height, n;
    cin >> color >> width >> height >> n;
    Rect origin(color, width, height);
    for (int i=0; i<n; ++i) {
        cout << *origin.clone() << endl;
    }
}