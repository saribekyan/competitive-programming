/*
PROG: flow
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))

int d[60][60];
int way[60], l;
bool t[60], found;
void dfs(int p)
{
	if (p == 25)
	{
		found = 1;
		return;
	}
	int i;
	for (i = 0; i < 52; i++)
		if (!t[i] && d[p][i])
		{
			t[i] = 1;
			way[l++] = i;
			dfs(i);
			if (found)
				return;
			l--;
		}
}
int main()
{
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);
	char p, q;
	int n, w, f, i;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%c %c %d\n", &p, &q, &w);
		if (p >= 'a')
			p += 26-'a';
		else
			p -= 'A';
		if (q >= 'a')
			q += 26-'a';
		else
			q -= 'A';
		d[p][q] = d[q][p] += w;
	}
	f = 0;
	l = 1;
	way[0] = 0;
	while (1)
	{
		l = 1;
		found = 0;
		memset(t, 0, sizeof(t));
		t[0] = 1;
		dfs(0);
		if (!found)
			break;
		w = 1000000000;
		for (i = 0; i+1 < l; i++)
			w = Min(w, d[way[i]][way[i+1]]);
		for (i = 0; i+1 < l; i++)
		{
			d[way[i]][way[i+1]] -= w;
			d[way[i+1]][way[i]] += w;
		}
		f += w;
	}
	printf("%d\n", f);
	return 0;
}
