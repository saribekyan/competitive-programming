#define RUN 2

#if RUN == 0
#include <stdio.h>
#include <string.h>
#define MAX 10
#define inf 1000000000

int m, n;
int len[MAX+10];
struct data
{
	int val, pos, t, p, q;
} d[MAX+100][2*MAX+100], s[2*MAX+100];
void init()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		d[i][0].val = -inf;
		for (j = 1; j <= n; j++)
			scanf("%d", &d[i][j].val);
		d[i][j].val = d[i][j+1].val = inf;
	}
}
void precalculate()
{
	int l, p, q, i;
	len[m-1] = n;
	for (i = m-1; i > 0; i--)
	{
		l = p = q = 1;
		s[0].val = -inf;
		while (p <= n || q <= len[i])
			if (d[i-1][p].val < d[i][q].val)
			{
				s[l].val = d[i-1][p].val;
				s[l].t = 0;
				s[l++].pos = p++;
			}
			else
			{
				s[l] = d[i][q];
				s[l].t = 1;
				s[l++].pos = q;
				q += 2;
			}
		s[l].val = s[l+1].val = inf;
		memcpy(d[i-1], s, sizeof(s));
		len[i-1] = l;
	}
	for (l = 0; l < m; l++)
	{
		d[l][1].p = d[l][1].t == 0;
		d[l][1].q = 1-d[l][1].p;
		for (i = 2; i < len[l]; i++)
			if (d[l][i].t == 0)
			{
				d[l][i].p = i;
				d[l][i].q = d[l][i-1].q;
			}
			else
			{
				d[l][i].q = i;
				d[l][i].p = d[l][i-1].p;
			}
	}
}
void solve()
{
	int Q, v, p, q, k;
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d", &v);
		p = 1;
		q = len[0];
		while (q-p > 1)
		{
			k = (p+q)>>1;
			if (d[0][k].val < v)
				p = k;
			else
				q = k;
		}
		for (k = 0; k+1 < m; k++)
		{
			printf("%d ", d[k][d[k][p].p].pos);
			p = d[k][d[k][p].q].pos;
			if (d[k+1][p+1].val < v)
				p++;
		}
		if (d[k][p+1].val < v)
			p++;
		printf("%d\n", p);
	}
}
int main()
{
	init();
	precalculate();
	solve();
	return 0;
}
#endif

#if RUN == 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define MOD 100

int d[1010][1010];
int main()
{
	FILE *fin = fopen("input.txt", "w");
	int n, m, i, j;
	scanf("%d%d", &m, &n);
	fprintf(fin, "%d %d\n", m, n);
	srand(time(0));
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			d[i][j] = rand()%MOD;
		sort(d[i], d[i]+n);
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j+1 < n; j++)
			fprintf(fin, "%d ", d[i][j]);
		fprintf(fin, "%d\n", d[i][j]);
	}
	scanf("%d", &i);
	fprintf(fin, "%d\n", i);
	while (i--)
		fprintf(fin, "%d\n", rand()%MOD);
	return 0;
}
#endif

#if RUN == 2
#include <stdio.h>
#define inf 1000000000

int d[1010][1010];
int main()
{
	FILE *fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "r");
	int m, n, q, v, l, i, j;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		d[i][0] = -inf;
		for (j = 1; j <= n; j++)
			fscanf(fin, "%d", d[i]+j);
		d[i][n+1] = inf;
	}
	fscanf(fin, "%d", &q);
	for (l = 1; l <= q; l++)
	{
		fscanf(fin, "%d", &v);
		for (i = 0; i < m; i++)
		{
			fscanf(fout, "%d", &j);
			if (d[i][j] > v || d[i][j+1] < v)
				break;
		}
		if (i < m)
		{
			printf("FAIL! QUERY %d, LINE %d\n", l, i+1);
			return 0;
		}
	}
	printf("OK!\n");
	return 0;
}
#endif


/*
4 4
1 3 5 7
9 11 13 15
17 19 21 23
25 27 29 31
4
4
8
16
32

*/
