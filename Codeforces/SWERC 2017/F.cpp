#include <iostream>
using namespace std;

int main() {
    long long w;
    long long n;
    long long area = 0;
    cin >> w >> n;
    while (n--) {
        long long a, b;
        cin >> a >> b;
        area += a * b;
    }
    cout << area / w << '\n';
    return 0;
}
