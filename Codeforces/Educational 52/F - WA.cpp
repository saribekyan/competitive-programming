#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector< int > parent(n + k);

    parent[0] = -1;
    for (int i = 1; i <= k; ++i) {
        parent[i] = i - 1;
    }
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        parent[i + k] = p - 1 + k;
    }
    n += k;

    vector< vector< int > > children(n);
    for (int i = 1; i < n; ++i) {
        children[parent[i]].push_back(i);
    }

    vector< int > direct_c(n, 0), d(n, 0);

    vector< pair< int, int > > S(2 * n);
    int s = 0;
    S[s++] = make_pair(0, 0);
    while (s > 0) {
        int p = S[s - 1].first;
        int i = S[s - 1].second;
        if (children[p].size() == 0) { // leaf
            direct_c[S[s - k - 1].first]++;
            d[p] = 0;
        }
        if (i == children[p].size()) {
            for (int j = 0; j < children[p].size(); ++j) {
                d[p] = max(d[p], d[children[p][j]]);
            }
            d[p] += direct_c[p];
            --s;
            continue;
        }
        S[s - 1].second = i + 1;
        S[s++] = make_pair(children[p][i], 0);
    }

    cout << d[0] << '\n';
    return 0;
}
/*
14 2
1 1
2 2 3 3
4 4 5 5 6 6 7
*/