#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int types[20010], st[20010];
vector<int> PB;
vector<vector<int> > ans;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, w, p, i, j, k;
	scanf("%d%d%d", &n, &m, &w);
	for (i = 0; i < n; i++)
	{
		scanf("%d", types+i);
		st[i] = types[i];
	}
	sort(st, st+n);
	k = 0;
	while (k < n && types[k] == st[k])
		k++;
	p = w-1;
	while (1)
	{
		if (k == n)
			break;
		if (types[k] == st[k])
		{
			k = 0;
			while (k < n && types[k] == st[k])
				k++;
			p--;
		}
		if (k == n)
			break;
		if (p)
			for (i = 0; i < n; i++)
				if (types[i] == st[k] && st[i] != types[i])
				{
					swap(types[i], types[k]);
					PB.push_back(k);
					PB.push_back(i);
					k = i;
					p--;
					break;
				}
		if (p == 0)
		{
			ans.push_back(PB);
			PB.clear();
			p = w;
			k = 0;
		}
	}
	if (PB.size() > 1)
		ans.push_back(PB);
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i].size()/2);
		for (j = 0; j < ans[i].size(); j++)
			printf(" %d", ans[i][j]+1);
		putchar('\n');
	}
	return 0;
}
/*
10 4 4
2 3 3 4 4 2 1 1 3 1

1 1 1 2 2 3 3 3 4 4
*/
