#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector< vector< int > > a(n, vector< int >(m));
    vector< vector< int > > b(n, vector< int >(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (a[i][j] != b[i][j]) {
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        a[i + k][j + l] = 1 - a[i + k][j + l];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}
