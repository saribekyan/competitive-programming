/*
PROG: ariprog
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 65000

int d[MAX];
struct sequence{int a, b;}ans[MAX];
bool t[2*MAX];
bool operator <(sequence a, sequence b){return a.b < b.b || a.b==b.b && a.a<b.a;}
FILE* fin = fopen("ariprog.in", "r");
FILE* fout = fopen("ariprog.out", "w");
int main()
{
	int n, m, k, l, a, p, i, j;
	fscanf(fin, "%d%d", &n, &m);
	k = 0;
	for (i = 0; i <= m; i++)
		for (j = i; j <= m; j++)
		{
			a = i*i+j*j;
			if (!t[a])
			{
				d[k++] = a;
				t[a] = 1;
			}
		}
	sort(d, d+k);
	p = 0;
	for (i = 0; i < k-n+2; i++)
		for (j = i+1; j < k-n+2; j++)
		{
			a = d[j]-d[i];
			if (a > d[k-1]/(n-1))
				break;
			for (l = 1; l < n; l++)
				if (t[d[i]+a*l]==0)
					break;
			if (l==n)
			{
				ans[p].a = d[i];
				ans[p].b = a;
				p++;
			}
		}
	sort(ans, ans+p);
	if (p)
		for (i = 0; i < p; i++)
			fprintf(fout, "%d %d\n", ans[i].a, ans[i].b);
	else
		fprintf(fout, "NONE\n");
	return 0;
}