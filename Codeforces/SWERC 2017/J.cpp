#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector< long long > a(n), b(n);

    vector< long long > am(3, 0), bm(3, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        am[(i + 1) % 3] += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        bm[(i + 1) % 3] += b[i];
    }

    vector< long long > ans(3, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans[(i + 1 + j) % 3] += a[i] * bm[j];
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    return 0;
}
