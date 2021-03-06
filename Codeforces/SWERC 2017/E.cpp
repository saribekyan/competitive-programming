#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long P = 1993;
char result[100], base[100], ing[100];

vector< vector< int > > g(10000);
vector< vector< int > > cost(10000);
vector< vector< int > > prestige(10000);

vector< pair<int, int > > f(10000, make_pair(-1, -1));

pair<int, int> get_final(int p) {
    if (f[p].first != -1) {
        return f[p];
    }

    if (g[p].size() == 0) {
        return f[p] = make_pair(0, 0);
    }

    f[p] = make_pair(1000000000, 1000000000);
    for (int i = 0; i < g[p].size(); ++i) {
        auto cand = get_final(g[p][i]);
        cand.first += cost[p][i];
        cand.second += prestige[p][i];
        if (f[p].first > cand.first || f[p].first == cand.first && f[p].second < cand.second) {
            f[p] = cand;
        }
    }
    return f[p];
}

int d[10010];
int main() {
    map< long long, int > id;


    int n = 0;
    int b, recipes;
    cin >> b >> recipes;
    for (int j = 0; j < recipes; ++j) {
        int c, p;
        cin >> result >> base >> ing >> c >> p;
        // scanf("%s%s%s%d%d", result, base, ing, &c, &p);
        long long h1 = 0;
        int l1 = strlen(result);
        for (int i = 0; i < l1; ++i) {
            h1 = (h1 * P + result[i]);
        }

        long long h2 = 0;
        int l2 = strlen(base);
        for (int i = 0; i < l2; ++i) {
            h2 = (h2 * P + base[i]);
        }

        if (id.find(h1) == id.end()) {
            id[h1] = n++;
        }

        if (id.find(h2) == id.end()) {
            id[h2] = n++;
        }

        g[id[h1]].push_back(id[h2]);
        cost[id[h1]].push_back(c);
        prestige[id[h1]].push_back(p);
    }

    for (int i = 0; i < n; ++i) {
        get_final(i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = b; j >= f[i].first; --j) {
            if (d[j] < d[j - f[i].first] + f[i].second) {
                d[j] = d[j - f[i].first] + f[i].second;
            }
        }
    }

    for (int i = b; i >= 0; --i) {
        if (d[i] != d[b]) {
            cout << d[b] << '\n' << i + 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n' << 0 << '\n';

    return 0;
}
/*
15
6
pizza_tomato pizza_base tomato 1 2
pizza_cheese pizza_base cheese 5 10
pizza_classic pizza_tomato cheese 5 5
pizza_classic pizza_cheese tomato 1 2
pizza_salami pizza_classic salami 7 6
pizza_spicy pizza_tomato chili 3 1

*/
