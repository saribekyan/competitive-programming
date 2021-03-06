#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k > 20) {
        cout << "No\n";
        return 0;
    }
    vector< set < int > > g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    vector< int > depth(n, 0), children(n, 0), done(n, 0);
    int remain = n;
    for (int d = 0; d < k; ++d) {
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1 && depth[i] == d) {
                if (d > 0 && children[i] < 3) {
                    cout << "No\n";
                    return 0;
                }
                int v = *g[i].begin();

                if (depth[v] != 0 && depth[v] != d + 1) {
                    cout << "No\n";
                    return 0;
                }
                depth[v] = d + 1;
                children[v]++;
                g[v].erase(i);
                g[i].erase(v);
                done[i] = 1;
            }
            c += 1;
        }
        if (c < remain / 2) {
            cout << "No\n";
            return 0;
        }
        remain -= c;
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (done[i] == 0) {
            if (children[i] < 3 || c != 0 || depth[i] != k) {
                cout << "No\n";
                return 0;
            }
            c++;
        }
    }
    cout << "Yes\n";
    return 0;
}
/*
15 2
1 4
2 4
3 4
4 13
10 5
11 5
12 5
14 5
5 13
6 7
8 6
13 6
9 6
15 13

*/
