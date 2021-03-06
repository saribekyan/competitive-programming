#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< vector< int > > a(n);

    vector< int > loc(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            x--;
            a[i].push_back(x);
            loc[x] = i * n + j;
        }
    }

    vector< vector< int > > di(3), dj(3);
    di[0] = vector<int>{-1, 1, -2, 2, -2, 2, -1, 1};
    dj[0] = vector<int>{-2, -2, -1, -1, 1, 1, 2, 2};
    for (int i = -n; i <= n; ++i) {
        if (i != 0) {
            di[1].push_back(i);
            dj[1].push_back(i);
            di[1].push_back(i);
            dj[1].push_back(-i);
            di[2].push_back(i);
            dj[2].push_back(0);
            di[2].push_back(0);
            dj[2].push_back(i);
        }
    }

    vector< vector< int> > g(3 * n * n, vector< int >(3 * n * n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int p = 0; p < 3; ++p) {
                for (int k = 0; k < di[p].size(); ++k) {
                    int u = i + di[p][k];
                    int v = j + dj[p][k];
                    if (u >= 0 && u < n && v >= 0 && v < n) {
                        g[(i * n + j) * 3 + p][(u * n + v) * 3 + p] = 1000;
                    }
                }
                for (int q = 0; q < 3; ++q) {
                    if (q != p) {
                        g[(i * n + j) * 3 + p][(i * n + j) * 3 + q] = 1001;
                    }
                    else {
                        g[(i * n + j) * 3 + p][(i * n + j) * 3 + q] = 0;
                    }
                }
            }
        }
    }

    for (int k = 0; k < n * n * 3; ++k) {
        for (int i = 0; i < n * n * 3; ++i) {
            for (int j = 0; j < n * n * 3; ++j) {
                if (g[i][k] >= 0 && g[k][j] >= 0 && (g[i][j] < 0 || g[i][j] > g[i][k] + g[k][j])) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    vector< vector < int > > d(n * n, vector< int > (3, -1));
    for (int p = 0; p < 3; ++p) {
        d[0][p] = 0;
    }
    for (int i = 1; i < n * n; ++i) {
        for (int p = 0; p < 3; ++p) {
            for (int q = 0; q < 3; ++q) {
                if (g[loc[i - 1] * 3 + q][loc[i] * 3 + p] >= 0 && (
                    d[i][p] < 0 ||
                    d[i][p] > d[i - 1][q] + g[loc[i - 1] * 3 + q][loc[i] * 3 + p])) {

                    d[i][p] = d[i - 1][q] + g[loc[i - 1] * 3 + q][loc[i] * 3 + p];
                }
            }
        }
    }

    int ans = d[n * n - 1][0];
    for (int p = 1; p < 3; ++p) {
        ans = min(ans, d[n * n - 1][p]);
    }
    cout << ans / 1000 << ' ' << ans % 1000 << '\n';
    return 0;
}
