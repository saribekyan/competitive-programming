/*
PROG: starry
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int ngroups, p;
char d[100][101];
bool graph[500][500];
bool vis[500], cl[500];
int di[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dj[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
struct cluster
{
	char form[100][101];
	int i1, j1, i2, j2;
	int number_of_stars;
	int fi, fj;
} c[500];
struct group
{
	int first;
	bool clusters[500];
} groups[30];
bool operator <(cluster a, cluster b){return a.fi < b.fi || (a.fi == b.fi && a.fj < b.fj);}
bool operator <(group a, group b){return c[a.first].fi < c[b.first].fi || (c[a.first].fi == c[b.first].fi && c[a.first].fj < c[b.first].fj);}
void rec(int i, int j)
{
	int k, i1, j1;
	for (k = 0; k < 8; k++)
	{
		i1 = i+di[k];
		j1 = j+dj[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m)
			if (d[i1][j1] == '1')
			{
				d[i1][j1] = '0';
				c[p].number_of_stars++;
				c[p].form[i1][j1] = '1';
				if (c[p].i1 > i1)
					c[p].i1 = i1;
				if (c[p].j1 > j1)
					c[p].j1 = j1;
				if (c[p].i2 < i1)
					c[p].i2 = i1;
				if (c[p].j2 < j1)
					c[p].j2 = j1;
				if (c[p].fi > i)
				{
					c[p].fi = i;
					c[p].fj = j;
				}
				else
					if (c[p].fi == i && c[p].fj > j)
					{
						c[p].fi = i;
						c[p].fj = j;
					}
				rec(i1, j1);
			}
	}
}
void flood(int r)
{
	int i;
	for (i = 0; i < p; i++)
		if (graph[r][i] && !vis[i])
		{
			groups[ngroups].clusters[i] = vis[i] = 1;
			flood(i);
		}
}
bool can(int s, int t)
{
	if (c[s].number_of_stars != c[t].number_of_stars)
		return 0;
	int s1, s2, s3, s4;
	s1 = c[s].i2-c[s].i1+1;
	s2 = c[s].j2-c[s].j1+1;
	s3 = c[t].i2-c[t].i1+1;
	s4 = c[t].j2-c[t].j1+1;
	if (!(s1 == s3 && s2 == s4 || s1 == s4 && s2 == s3))
		return 0;
	int i, j, k, l;
	if (s1 == s3)
	{
		for (i = c[s].i1, k = c[t].i1; i < c[s].i2; i++, k++)
			for (j = c[s].j1, l = c[t].j1; j < c[s].j2; j++, l++)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there1;
		return 1;
there1:;
		for (i = c[s].i1, k = c[t].i1; i < c[s].i2; i++, k++)
			for (j = c[s].j1, l = c[t].j2; j < c[s].j2; j++, l--)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there2;
		return 1;
there2:;
		for (i = c[s].i1, k = c[t].i2; i < c[s].i2; i++, k--)
			for (j = c[s].j1, l = c[t].j2; j < c[s].j2; j++, l--)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there3;
		return 1;
there3:;
		for (i = c[s].i1, k = c[t].i2; i < c[s].i2; i++, k--)
			for (j = c[s].j1, l = c[t].j1; j < c[s].j2; j++, l++)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there4;
		return 1;
there4:;
	}
	if (s2 == s3)
	{
		for (i = c[s].i1, l = c[t].j1; i < c[s].i2; i++, l++)
			for (j = c[s].j1, k = c[t].i2; j < c[s].j2; j++, k--)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there5;
		return 1;
there5:;
		for (i = c[s].i1, l = c[t].j1; i < c[s].i2; i++, l++)
			for (j = c[s].j1, k = c[t].i1; j < c[s].j2; j++, k++)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there6;
		return 1;
there6:;
		for (i = c[s].i1, l = c[t].j2; i < c[s].i2; i++, l--)
			for (j = c[s].j1, k = c[t].i1; j < c[s].j2; j++, k++)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there7;
		return 1;
there7:;
		for (i = c[s].i1, l = c[t].j2; i < c[s].i2; i++, l--)
			for (j = c[s].j1, k = c[t].i2; j < c[s].j2; j++, k--)
				if (c[s].form[i][j] != c[t].form[k][l])
					goto there8;
		return 1;
there8:;
	}
	return 0;
}
FILE* fin = fopen("starry.in", "r");
FILE* fout = fopen("starry.out", "w");
int main()
{
	int i, j, k, l;
	fscanf(fin, "%d%d", &m, &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%s", d[i]);
	p = 0;
	for (i = 0; i < 500; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < m; k++)
				c[i].form[j][k] = '0';
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (d[i][j] == '1')
			{
				d[i][j] = '0';
				c[p].form[i][j] = '1';
				c[p].number_of_stars = 1;
				c[p].fi = c[p].i1 = c[p].i2 = i;
				c[p].fj = c[p].j1 = c[p].j2 = j;
				rec(i, j);
				p++;
			}
	sort(c, c+p);
	for (i = 0; i < p-1; i++)
		for (j = i+1; j < p; j++)
			graph[i][j] = graph[j][i] = can(i, j);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			d[i][j] = '0';
	while (1)
	{
		for (i = 0; i < p; i++)
			if (!vis[i])
				break;
		if (i == p)
			break;
		groups[ngroups].first = i;
		vis[i] = groups[ngroups].clusters[i] = 1;
		flood(i);
		ngroups++;
	}
	sort(groups, groups+ngroups);
	for (k = 0; k < ngroups; k++)
		for (i = 0; i < p; i++)
			if (groups[k].clusters[i])
				for (j = c[i].i1; j <= c[i].i2; j++)
					for (l = c[i].j1; l <= c[i].j2; l++)
						if (c[i].form[j][l] == '1')
							d[j][l] = 'a'+k;
	for (i = 0; i < n; i++)
	{
		d[i][m] = 0;
		fprintf(fout, "%s\n", d[i]);
	}
	return 0;
}