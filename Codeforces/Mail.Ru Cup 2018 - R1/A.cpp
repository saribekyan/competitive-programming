#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    int dxy = (x - y > 0) ? (x - y) : (y - x);
    int dxz = (x - z > 0) ? (x - z) : (z - x);

    int stairs = dxy * t1;
    int elevator = dxz * t2 + t3 + t3 + dxy * t2 + t3;

    if (elevator <= stairs) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}
