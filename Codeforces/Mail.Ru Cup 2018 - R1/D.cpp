#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector < long long > d(n+1, 0);

    map< long long, long long > counts;
    counts[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        d[i] = d[i - 1] ^ a;
        if (d[i] & 1) {
            d[i] ^= (1 << k) - 1;
        }
        if (counts.find(d[i]) == counts.end()) {
            counts[d[i]] = 1;
        }
        else {
            counts[d[i]]++;
        }
    }

    long long ans = n * (n + 1) / 2;
    for (auto it : counts) {
        long long rep = it.second;
        if (rep % 2 == 0) {
            rep /= 2;
            ans -= 2 * (rep - 1) * rep / 2;
        }
        else {
            rep /= 2;
            ans -= (rep - 1) * rep / 2 + rep * (rep + 1) / 2;
        }
    }
    cout << ans << '\n';
    return 0;
}
