#include <cstdio>
#include <vector>
using namespace std;

int ans[40];
int p[40], c[40];
vector<vector<int> > d;
void del(int f)
{
	int i, j;
	for (i = 0; i < d.size(); i++)
		for (j = 1; j < d[i].size(); j++)
			if (d[i][j] == f)
				d[i].erase(d[i].begin()+j--);
}
int main()
{
	int n, m, i, j, k;
	scanf("%d", &n);
	d.resize(n);
	for (i = 1; i <= n; i++)
	{
		d[i-1].push_back(i);
		while (scanf("%d", &m) && m)
			d[i-1].push_back(m);
	}
	while (1)
	{
		for (i = 0; i < d.size(); i++)
			if (d[i].size() == 2)
			{
				ans[d[i][0]] = d[i][1];
				del(d[i][1]);
				d.erase(d.begin()+i--);
				break;
			}
		if (i < d.size())
			continue;
		memset(p, 0, sizeof(p));
		memset(c, 0, sizeof(c));
		for (i = 0; i < d.size(); i++)
			for (j = 1; j < d[i].size(); j++)
			{
				c[d[i][j]]++;
				p[d[i][j]] = d[i][0];
			}
		for (i = 1; i <= n; i++)
			if (c[i] == 1)
			{
				ans[p[i]] = i;
				break;
			}
		if (i == n+1)
			break;
		for (j = 0; j < d.size() && d[j][0] != p[i]; j++);
		d.erase(d.begin()+j);
		del(i);
	}
	for (i = 1; i <= n && ans[i] == 0; i++);
	if (i == n+1)
	{
		printf("-1\n");
		return 0;
	}
	while (i <= n)
	{
		if (ans[i])
			printf("%d %d\n", i, ans[i]);
		i++;
	}
	return 0;
}
