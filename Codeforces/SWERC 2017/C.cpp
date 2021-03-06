#include <iostream>
#include <cstring>
using namespace std;

long long MOD = 1000000000;

long long fib[10];
long long a[1 << 8][1 << 8];

long long tile_pair(int m1, int m2, int n) {
    if ((m1 & m2) != 0) {
        return 0;
    }
    int fm1 = (1 << n) - 1 - m1;
    int fm2 = (1 << n) - 1 - m2;

    long long ans = 1;

    int s = 0;
    int right = m1 | m2;

    for (int i = 0; i < n; ++i) {
        if (((right >> i) & 1) == 1) {
            ans = (ans * fib[s]) % MOD;
            s = 0;
        }
        else {
            s++;
        }
    }
    ans = (ans * fib[s]) % MOD;
    return ans;
}

long long d[2][1 << 8][1 << 8];
int main() {

    int n;
    long long m;
    cin >> n >> m;
    
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            a[i][j] = tile_pair(i, j, n);
        }
    }

    for (int i = 0; i < (1 << n); ++i) {
        d[0][i][i] = 1;
    }

    int sw = 0;
    for (int b = 63; b >= 0; --b) {
        if (m < ((1LL) << b)) {
            continue;
        }
        sw ^= 1;
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                d[sw][i][j] = 0;
                for (int k = 0; k < (1 << n); ++k) {
                    d[sw][i][j] = (d[sw][i][j] + d[sw ^ 1][i][k] * d[sw ^ 1][k][j]) % MOD;
                }
            }
        }
        if ((m >> b) & 1) {
            sw ^= 1;
            for (int i = 0; i < (1 << n); ++i) {
                for (int j = 0; j < (1 << n); ++j) {
                    d[sw][i][j] = 0;
                    for (int k = 0; k < (1 << n); ++k) {
                        d[sw][i][j] = (d[sw][i][j] + d[sw ^ 1][i][k] * a[k][j]) % MOD;
                    }
                }
            }
        }
    }

    cout << d[sw][0][0] << '\n';
    return 0;
}
