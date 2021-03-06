#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector< long long > s(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &s[i]);
    }
    sort(s.begin(), s.end());

    vector< long long > diff(n - 1);
    for (int i = 1; i < n; ++i) {
        diff[i - 1] = s[i] - s[i - 1];
    }

    sort(diff.begin(), diff.end());

    vector< long long > ans_for_diff(n - 1);

    if (n > 1) {
        ans_for_diff[0] = diff[0] * n;
        for (int i = 1; i < n - 1; ++i) {
            ans_for_diff[i] = ans_for_diff[i - 1] + (diff[i] - diff[i - 1]) * (n - i);
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        long long d = r - l + 1;
        if (n == 1) {
            printf("%lld", d);
        }
        else {
            if (d <= diff[0]) {
                printf("%lld", d * n);
            }
            else {
                if (d >= diff[n - 2]) {
                    printf("%lld\n", s[n - 1] - s[0] + d);
                }
                else {
                    int p = 0, q = n - 2;
                    while (q - p > 1) {
                        int m = (p + q) / 2;
                        if (diff[m] > d) {
                            q = m;
                        }
                        else {
                            p = m;
                        }
                    }
                    while (diff[p] <= d) {
                        p++;
                    }
                    --p;

                    printf("%lld", ans_for_diff[p] + (d - diff[p]) * (n - p - 1));
                }
            }
        }
        if (q == 0) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
    return 0;
}
/*
2
1 50
2
100 100

*/
