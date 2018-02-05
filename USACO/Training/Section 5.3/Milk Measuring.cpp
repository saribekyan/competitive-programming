/*
PROG: milk4
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, walk;
int d[20001];
bool found;
int pail[100];
bool t[100], ans[100];
bool used[20001][100];
int pr[20001][100], npr[20001];
int rec(int m)
{
	int &it = d[m];
	if (it != -1)
		return it;
	if (m == 0)
		return (it = 0);
	int w, i, j;
	it = n+1;
	for (i = 0; i < n && m-pail[i] >= 0; i++)
	{
		w = rec(m-pail[i]);
		if (it > w+(int)(used[m-pail[i]][i] == 0))
		{
			npr[m] = 0;
			it = w+(int)(used[m-pail[i]][i] == 0);
			for (j = 0; j < n; j++)
				used[m][j] = used[m-pail[i]][j];
			used[m][i] = 1;
		}
		if (it == w+(int)(used[m-pail[i]][i] == 0))
		{
			bool t = used[m-pail[i]][i];
			used[m-pail[i]][i] = 1;
			pr[m][npr[m]++] = i;
			for (j = 0; j < n && used[m][j] == used[m-pail[i]][j]; j++);
			used[m-pail[i]][i] = t;
			if (j != n && used[m-pail[i]][j])
			{
				for (j = 0; j < n; j++)
					used[m][j] = used[m-pail[i]][j];
				used[m][i] = 1;
			}
		}
	}
	return it;
}
void rec(int m, int l)
{
	if (m < 0)
		return;
	int i;
	if (l == 0 && m == 0)
	{
		found = 1;
		for (i = 0; i < n && t[i] == ans[i]; i++);
		if (i != n && t[i] > ans[i])
			while (i < n)
				ans[i] = t[i++];
	}
	if (m == 0)
		return;
	bool b;
	for (i = 0; i < npr[m]; i++)
	{
		walk++;
		b = t[pr[m][i]];
		t[pr[m][i]] = 1;
		if (walk >= 7500000)
			return;
		rec(m-pail[pr[m][i]], l-(int)(!b));
		t[pr[m][i]] = b;
	}
}
FILE* fin = fopen("milk4.in", "r");
FILE* fout = fopen("milk4.out", "w");
int main()
{
	int m, i;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d", pail+i);
		if (pail[i] > m || d[pail[i]])
		{
			n--;
			i--;
		}
		else
			d[pail[i]] = 1;
	}
	sort(pail, pail+n);
	memset(d, -1, sizeof(d));
	fprintf(fout, "%d", rec(m));
	rec(m, d[m]);
	for (i = 0; i < n; i++)
		if (ans[i])
			fprintf(fout, " %d", pail[i]);
	fputc('\n', fout);
	return 0;
}