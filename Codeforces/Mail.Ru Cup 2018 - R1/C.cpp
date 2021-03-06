#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< int > l(n);
    vector< int > r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    vector< int > a(n);
    int set_nums = 0;
    for (int v = n; v >= 1; --v) {
        for (int i = 0; i < n; ++i) {
            if (l[i] == 0 && r[i] == 0 && a[i] == 0) {
                a[i] = v;
                set_nums++;
            }
        }
        if (set_nums == n) {
            break;
        }
        vector< int > counts(n, 0);
        counts[0] = (a[0] == v);
        for (int i = 1; i < n; ++i) {
            counts[i] = counts[i - 1] + (a[i] == v);
        }
        if (counts[n - 1] == 0) {
            cout << "NO\n";
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0 && a[i] == 0) {
                l[i] -= counts[i];
            }
            if (i + 1 < n && a[i] == 0) {
                r[i] -= counts[n - 1] - counts[i];
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ((i == n - 1) ? '\n' : ' ');
    }
    return 0;
}
