#include <cstdio>
#include <queue>
using namespace std;

queue<int> Q;
int d[200001];
bool t[200001];
FILE* fin = fopen("catchcow.in", "r");
FILE* fout = fopen("catchcow.out", "w");
int main()
{
	int n, m, i, j, p, q;
	fscanf(fin, "%d%d", &n, &m);
	if (n == m)
		fprintf(fout, "0\n");
	else
	{
		if (n > m)
			q = n;
		else
			q = m;
		for (i = 0; i < 2*n; i++)
			t[i] = 0;
		t[n] = 1;
		d[n] = 0;
		Q.push(n);
		while (1)
		{
			p = Q.front();
			Q.pop();
			if (p <= q && t[2*p] == 0)
			{
				t[2*p] = 1;
				d[2*p] = d[p]+1;
				if (2*p == m)break;
				Q.push(2*p);
			}
			if (p > 0 && t[p-1] == 0)
			{
				t[p-1] = 1;
				d[p-1] = d[p]+1;
				if (p-1 == m)break;
				Q.push(p-1);
			}
			if (p < 2*q && t[p+1] == 0)
			{
				t[p+1] = 1;
				d[p+1] = d[p]+1;
				if (p+1 == m)break;
				Q.push(p+1);
			}
		}
		fprintf(fout, "%d\n", d[m]);
	}
	return 0;
}