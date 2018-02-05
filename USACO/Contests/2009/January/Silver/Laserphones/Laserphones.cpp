/*
PROG: lphone
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int d[110][110];
char s[110][110];
struct P
{
	int i, j;
} p[2], q, r;
queue<P> Q;
int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};
int main()
{
	freopen("lphone.in", "r", stdin);
	freopen("lphone.out", "w", stdout);
	int k=0, i, j;
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		for (j = 0; j < m; j++)
			if (s[i][j] == 'C')
			{
				p[k].i = i;
				p[k++].j = j;
			}
	}
	Q.push(p[0]);
	d[p[0].i][p[0].j] = 1;
	while (1)
	{
		q = Q.front();
		if (q.i == p[1].i && q.j == p[1].j)
		{
			printf("%d\n", d[q.i][q.j]-2);
			return 0;
		}
		Q.pop();
		for (k = 0; k < 4; k++)
			for (r.i=q.i+di[k],r.j=q.j+dj[k]; r.i>=0 && r.i<n && r.j>=0 && r.j<m && s[r.i][r.j]!='*'; r.i+=di[k],r.j+=dj[k])
				if (!d[r.i][r.j])
				{
					d[r.i][r.j] = d[q.i][q.j]+1;
					Q.push(r);
				}
	}
	return 0;
}
