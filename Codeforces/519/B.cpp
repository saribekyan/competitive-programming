#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< int > a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector< int > ans;
    for (int k = 1; k <= n; ++k) {
        vector< int > x(k);
        for (int i = 0; i < k; ++i) {
            x[i] = a[i + 1] - a[i];
        }

        int b = 0;
        bool found = true;
        for (int i = 0; i <= n; ++i) {
            if (b != a[i]) {
                found = false;
                break;
            }
            b += x[i % k];
        }

        if (found) {
            ans.push_back(k);
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i + 1 < ans.size()) {
            cout << ' ';
        }
    }
    cout << '\n';
    return 0;
}
