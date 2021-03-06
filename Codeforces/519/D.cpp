#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector < int > > a(m, vector< int >(n));
    vector< vector <int > > loc(m, vector< int >(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
            loc[i][a[i][j]] = j;
        }
    }

    long long ans = 0;
    for (int l = 0; l < n;) {
        int r;
        for (r = l + 1; r < n; ++r) {
            int prev = a[0][r - 1];
            int curr = a[0][r];
            int i;
            for (i = 0; i < m; ++i) {
                if (loc[i][curr] != loc[i][prev] + 1) {
                    break;
                }
            }
            if (i < m) {
                break;
            }
        }
        long long len = r - l;
        ans += len * (len + 1) / 2;
        l = r;
    }
    cout << ans << '\n';
    return 0;
}
