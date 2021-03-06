#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(pair< long long, long long > a, pair< long long, long long > b) {
    return a.first - a.second < b.first - b.second;
}

int main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);

    vector< pair < long long, long long > > pts(n), s(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &pts[i].first, &pts[i].second);
        s[i] = pts[i];
    }

    sort(s.begin(), s.end(), cmp);
    vector< pair<long long, long long> > sum(n);
    sum[0] = s[0];
    for (long long i = 1; i < n; ++i) {
        sum[i].first = sum[i - 1].first + s[i].first;
        sum[i].second = sum[i - 1].second + s[i].second;
    }

    vector < long long > ans(n, 0);

    for (long long i = 0; i < n; ++i) {
        long long diff = pts[i].first - pts[i].second;

        int p = 0, q = n - 1;
        while (q - p > 1) {
            int k = (p + q) / 2;
            if (s[k].first - s[k].second >= diff) {
                q = k;
            }
            else {
                p = k;
            }
        }
        int k;
        for (k = p; k <= q; ++k) {
            if (s[k].first - s[k].second >= diff) {
                break;
            }
        }

        ans[i] += (n - 1 - k + 1) * pts[i].first;

        ans[i] += sum[n - 1].second;
        if (k > 0) {
            ans[i] -= sum[k - 1].second;
        }
        ////

        ans[i] += k * pts[i].second;

        if (k > 0) {
            ans[i] += sum[k - 1].first;
        }
    }

    for (int i = 0; i < m; ++i) {
        int p, q;
        scanf("%d%d", &p, &q);

        p--;
        q--;
        long long points = min(pts[p].first + pts[q].second, pts[p].second + pts[q].first);

        ans[p] -= points;
        ans[q] -= points;
    }

    for (int i = 0; i < n; ++i) {
        ans[i] -= pts[i].first + pts[i].second;
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld%c", ans[i], ((i == n - 1) ? '\n' : ' '));
    }
    return 0;
}
