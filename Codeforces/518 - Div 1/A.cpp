#include <iostream>
#include <vector>
using namespace std;

int M = 200;
int MOD = 998244353;

int d[100010][210][3], ds[100010][210][3];
int main() {
    int n;
    cin >> n;
    vector< int > a(n + 2, 0);
    a[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int v = 1; v <= M; ++v) {
        if (v == a[n] || a[n] == -1) {
            d[n][v][0] = 1;
        }
    }
    for (int v = 1; v <= M; ++v) {
        ds[n][v][0] = ds[n][v - 1][0] + d[n][v][0];
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int v = 1; v <= M; ++v) {
            if (v == a[i] || a[i] == -1) {
                d[i][v][0] = ((ds[i + 1][v - 1][0] + ds[i + 1][v - 1][1]) % MOD + ds[i + 1][v - 1][2]) % MOD;
                d[i][v][1] = ((d[i + 1][v][0] + d[i + 1][v][1]) % MOD + d[i + 1][v][2]) % MOD;
                d[i][v][2] = ((ds[i + 1][M][1] - ds[i + 1][v][1] + MOD) % MOD +
                             (ds[i + 1][M][2] - ds[i + 1][v][2] + MOD) % MOD) % MOD;
            }
            for (int k = 0; k < 3; ++k) {
                ds[i][v][k] = (ds[i][v - 1][k] + d[i][v][k]) % MOD;
            }
        }
    }

    cout << (d[0][1][1] + d[0][1][2]) % MOD << '\n';
    return 0;
}
