#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long s, a, b, c;
        cin >> s >> a >> b >> c;
        cout << (s / c) + ((s / c) / a) * b << '\n';
    }
    return 0;
}
