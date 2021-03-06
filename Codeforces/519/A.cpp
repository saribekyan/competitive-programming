#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< int > a(n);
    int m = 0;
    int other = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = max(m, a[i]);
        other += a[i];
    }

    for (int k = m; ; k++) {
        if (k * n - other > other) {
            cout << k << '\n';
            return 0;
        }
    }
    return 0;
}
