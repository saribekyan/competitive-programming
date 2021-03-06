#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int i;
    for (i = 0; i < n; ++i) {
        if (a[n - 1] != a[i]) {
            break;
        }
    }
    int j;
    for (j = n - 1; j >= 0; --j) {
        if (a[j] != a[0]) {
            break;
        }
    }
    int ans = max(n - 1 - i, j - 0);
    printf("%d\n", ans);
    return 0;
}
