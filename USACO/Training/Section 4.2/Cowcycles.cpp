/*
PROG: cowcycle
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int f, r, f1, f2, r1, r2;
double s[50], mean, m, solve = 987654321.0;
int F[5], R[10], F1[5], R1[10];
void check()
{
	if (F1[f-1]*R1[r-1] < 3*F1[0]*R1[0])
		return;
	int i, j, l = 0;
	for (i = 0; i < f; i++)
		for (j = 0; j < r; j++)
			s[l++] = F1[i]*1.0/R1[j];
	sort(s, s+l);
	mean = (s[l-1]-s[0])/(l-1);
	m = 0;
	for (i = 0; i < l-1; i++)
		m += (mean-s[i+1]+s[i])*(mean-s[i+1]+s[i]);
	if (solve < m)
		return;
	solve = m;
	for (i = 0; i < f; i++)
		F[i] = F1[i];
	for (i = 0; i < r; i++)
		R[i] = R1[i];
}
void solve_f(int st, int number)
{
	if (st == f)
	{
		check();
		return;
	}
	int i;
	for (i = number; i <= f2 && st+f2-i+1 >= f; i++)
	{
		F1[st] = i;
		solve_f(st+1, i+1);
	}
}
void solve_r(int st, int number)
{
	int i;
	if (st == r)
	{
		for (i = f1; i <= f2 && f2*R1[r-1] >= 3*i*R1[0] && f2-i+1 >= f; i++)
		{
			F1[0] = i;
			solve_f(1, i+1);
		}
		return;
	}
	for (i = number; i <= r2 && st+r2-i+1 >= r; i++)
	{
		R1[st] = i;
		solve_r(st+1, i+1);
	}
}
FILE* fin = fopen("cowcycle.in", "r");
FILE* fout = fopen("cowcycle.out", "w");
int main()
{
	int i;
	fscanf(fin, "%d%d%d%d%d%d", &f, &r, &f1, &f2, &r1, &r2);
	solve_r(0, r1);
	for (i = 0; i < f-1; i++)
		fprintf(fout, "%d ", F[i]);
	fprintf(fout, "%d\n", F[f-1]);
	for (i = 0; i < r-1; i++)
		fprintf(fout, "%d ", R[i]);
	fprintf(fout, "%d\n", R[r-1]);
	return 0;
}