#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;
    vector< int > h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());

    if (h[0] == h[n - 1]) {
        cout << 0 << '\n';
        return 0;
    }

    long long ans = 0, s = 0;
    int H = h[0] - 1, i = 0;
    while (true) {
        while (i < n && H < h[i]) {
            ++i;
        }
        if (s + i > k) {
            ans += 1;
            s = 0;
        }
        if (i == n) {
            if (s > 0) {
                ans += 1;
            }
            cout << ans << '\n';
            return 0;
        }
        s += i;
        H--;
    }
    return 0;
}
/*
14 2
1 1
2 2 3 3
4 4 5 5 6 6 7
*/