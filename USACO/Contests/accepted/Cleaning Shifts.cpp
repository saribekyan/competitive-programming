#include <cstdio>
#include <algorithm>
using namespace std;

struct cow{int start, end;}d[25000];
bool operator <(cow a, cow b){return a.start < b.start || (a.start == b.start && a.end > b.end);}
FILE* fin = fopen("cleaning.in", "r");
FILE* fout = fopen("cleaning.out", "w");
int main()
{
	bool t;
	int n, m, p, q, w, r;
	fscanf(fin, "%d%d", &n, &m);
	for (p = 0; p < n; p++)
		fscanf(fin, "%d%d", &d[p].start, &d[p].end);
	sort(d, d+n);
	r = 1;
	w = d[0].end;
	p = 0;
	if (d[0].start != 1)w = m+1;
	while (w < m)
	{
		t = 1;
		p++;
		q = w;
		while (p < n && d[p].start <= q+1)
		{
			if (d[p].end > q && w < d[p].end)
			{
				w = d[p].end;
				t = 0;
			}
			p++;
		}
		p--;
		if (t)break;
		r++;
	}
	if (w == m)
		fprintf(fout, "%d\n", r);
	else
		fprintf(fout, "-1\n");
	return 0;
}