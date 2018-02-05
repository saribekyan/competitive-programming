/*
PROG: shuttle
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

map<int, int> s;
vector<pair<int, int> > g[20010];
int main()
{
	freopen("shuttle.in", "r", stdin);
	freopen("shuttle.out", "w", stdout);
	int n, m, c, u, v, p, i, j;
	map<int,int>::iterator I;
	scanf("%d%d%d", &n, &m, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &u, &v, &p);
		g[u].push_back(make_pair(v, p));
	}
	u = 0;
	p = c;
	for (i = 1; i <= m; i++)
	{
		if (s.find(i) != s.end())
		{		
			p += s[i];
			u += s[i];
		}
		for (j = 0; j < g[i].size(); j++)
		{
			s[g[i][j].first] += g[i][j].second;
			p -= g[i][j].second;
		}
		I = s.end();
		if (I != s.begin())
			for (--I; p < 0;)
				if (p+I->second < 0)
				{
					p += I->second;
					s.erase(I--);
				}
				else
				{
					I->second += p;
					if (I->second == 0)
						s.erase(I--);
					p = 0;
				}
	}
	printf("%d\n", u);
	return 0;
}
