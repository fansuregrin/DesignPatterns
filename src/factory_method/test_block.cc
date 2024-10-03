#include "Block.h"

int main() {
    BlockFactorySystem sys;
 
    int n = 0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string type;
        int cnt;
        cin >> type >> cnt;
        sys.addBlocks(type, cnt);
    }
     
    sys.showBlocks();
}