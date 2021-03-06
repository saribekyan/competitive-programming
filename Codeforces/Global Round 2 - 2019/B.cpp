#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, h;
    scanf("%d%d", &n, &h);
    vector< int > a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int k;
    for (k = 1; k <= n; ++k) {
        sort(a.begin(), a.begin() + k);
        reverse(a.begin(), a.begin() + k);
        int s = 0;
        for (int i = 0; i < k; i += 2) {
            s += a[i];
        }
        if (s > h) {
            break;
        }
    }
    printf("%d\n", k - 1);
    return 0;
}
