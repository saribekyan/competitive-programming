#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    if (m >= (n + 1) / 2) {
        cout << 0 << ' ';
    }
    else {
        cout << n - 2 * m << ' ';
    }
    for (long long k = 0; k <= n; ++k) {
        if (k * (k - 1) / 2 >= m) {
            cout << n - k << '\n';
            return 0;
        }
    }
    return 0;
}
