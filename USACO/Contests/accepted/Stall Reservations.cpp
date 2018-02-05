#include <cstdio>
#include <algorithm>
using namespace std;

bool t[50000];
int ans[50000];
struct P{int x, i; bool t;}d[100000];
bool operator <(P p, P q){return p.x < q.x || (p.x == q.x && p.t && q.t == 0);}
FILE* fin = fopen("reserve.in", "r");
FILE* fout = fopen("reserve.out", "w");
int main()
{
	int n, p, q, i, j;
	fscanf(fin, "%d", &n);
	for (i = 0; i < 2*n; i+=2)
	{
		fscanf(fin, "%d%d", &p, &q);
		d[i].x = p;
		d[i+1].x = q;
		d[i].i = d[i+1].i = i/2;
		d[i].t = 1;
		d[i+1].t = 0;
	}
	sort(d, d+2*n);
	for (i = 0; i < n; i++)
		t[i] = 0;
	p = q = 0;
	for (i = 0; i < 2*n; i++)
		if (d[i].t)
		{
			if (q)
			{
				for (j = 0; j < p; j++)
					if (t[j] == 0)
						break;
				ans[d[i].i] = j+1;
				t[j] = 1;
				q--;
			}
			else
			{
				p++;
				ans[d[i].i] = p;
				t[p-1] = 1;
			}
		}
		else
		{
			t[ans[d[i].i]-1] = 0;
			q++;
		}
	fprintf(fout, "%d\n", p);
	for (i = 0; i < n; i++)
		fprintf(fout, "%d\n", ans[i]);
	return 0;
}