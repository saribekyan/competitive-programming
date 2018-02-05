#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int num;
int deg[10000];
int *d[10000];
bool t[10000];
int tree[10000];
int number[10000];
int Number[10000];
int low[10000], high[10000];
int st[1000000], end[1000000];
bool A[50][50];
void dfs(int p)
{
	int q, i;
	q = num-1;
	for (i = 0; i < deg[p]; i++)
		if (!t[d[p][i]])
		{
			t[d[p][i]] = 1;
			tree[num] = q;
			number[num] = d[p][i];
			Number[d[p][i]] = num++;
			dfs(d[p][i]);
		}
}
FILE* fin = fopen("bridge.in", "r");
FILE* fout = fopen("bridge.out", "w");
int main()
{
	int n, m, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d%d", st+i, end+i);
		st[i]--;
		end[i]--;
		deg[st[i]]++;
		deg[end[i]]++;
	}
	for (i = 0; i < n; i++)
		d[i] = new int[deg[i]];
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < m; i++)
	{
		d[st[i]][deg[st[i]]++] = end[i];
		d[end[i]][deg[end[i]]++] = st[i];
	}
	t[0] = 1;
	num = 1;
	dfs(0);
	for (i = 0; i < n; i++)
	{
		low[i] = high[i] = i;
		for (j = 0; j < deg[number[i]]; j++)
			if (tree[i] != Number[d[number[i]][j]])
			{
				low[i] = min(low[i], Number[d[number[i]][j]]);
				high[i] = max(high[i], Number[d[number[i]][j]]);
			}
	}
	for (i = n-1; i > 0; i--)
	{
		low[tree[i]] = min(low[tree[i]], low[i]);
		high[tree[i]] = max(high[tree[i]], high[i]);
		for (j = 0; j < deg[number[i]]; j++)
			if (d[number[i]][j] != number[tree[i]])
			{
				low[tree[i]] = min(low[tree[i]], Number[d[number[i]][j]]);
				high[tree[i]] = max(high[tree[i]], Number[d[number[i]][j]]);
			}
	}
	for (i = n-1; i > 0; i--)
		if (tree[i] < low[i] || tree[i] > high[i])
			A[min(number[i], number[tree[i]])][max(number[i], number[tree[i]])] = 1;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (A[i][j])
				fprintf(fout, "%d %d\n", i+1, j+1);
	return 0;
}