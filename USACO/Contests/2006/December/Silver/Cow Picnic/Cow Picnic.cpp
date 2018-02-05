#include <cstdio>
#include <algorithm>
using namespace std;

short p, n, m;
short cows[100];
short deg[1000];
short *G[1000];
short in[10000][2];
short len[100];
short d[100][1000];
short s[1000];
short ns[1000];
bool t[1000];
void read()
{
	short i;
	scanf("%hd%hd%hd", &p, &n, &m);
	for (i = 0; i < p; i++)
	{
		scanf("%hd", cows+i);
		cows[i]--;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%hd%hd", in[i], in[i]+1);
		deg[--in[i][0]]++;
		in[i][1]--;
	}
}
void dfs(short u, short l)
{
	short i;
	for (i = 0; i < deg[u]; i++)
		if (!t[G[u][i]])
		{
			t[G[u][i]] = 1;
			d[l][len[l]++] = G[u][i];
			dfs(G[u][i], l);
		}
}
void build()
{
	short i;
	for (i = 0; i < n; i++)
		G[i] = new short[deg[i]];
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
		G[in[i][0]][deg[in[i][0]]++] = in[i][1];
	for (i = 0; i < p; i++)
	{
		memset(t, 0, sizeof(t));
		t[cows[i]] = 1;
		len[i] = 1;
		d[i][0] = cows[i];
		dfs(cows[i], i);
		sort(d[i], d[i]+len[i]);
	}
}
short solve()
{
	short w, k, l, i, j;
	for (i = 0; i < n; i++)
		s[i] = i;
	w = n;
	for (i = 0; i < p; i++)
	{
		k = l = j = 0;
		while (k < w && l < len[i])
		{
			if (s[k] < d[i][l])
				k++;
			if (s[k] > d[i][l])
				l++;
			if (s[k] == d[i][l])
			{
				ns[j++] = s[k];
				k++;
				l++;
			}
		}
		w = j;
		for (j = 0; j < w; j++)
			s[j] = ns[j];
	}
	return w;
}
int main()
{
	freopen("picnic.in", "r", stdin);
	freopen("picnic.out", "w", stdout);
	read();
	build();
	printf("%hd\n", solve());
	return 0;
}
