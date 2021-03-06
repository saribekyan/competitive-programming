#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< int > a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    map< int, int > counts;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] <= b[j]) {
                counts[b[j] - a[i]] ++;
            }
        }
    }

    int mx = 0, t = 0;
    for (auto x : counts) {
        if (mx < x.second || mx == x.second && t > x.first) {
            mx = x.second;
            t = x.first;
        }
    }

    cout << t << '\n';
    return 0;
}
