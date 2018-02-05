/*
PROG: elevator
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

bool d[40110];
struct block
{
	int h, a, c;
} p[410];
bool operator < (block a, block b)
{
	return a.a < b.a;
}
int main()
{
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d%d", &p[i].h, &p[i].a, &p[i].c);
	d[0] = 1;
	sort(p, p+n);
	for (i = 0; i < n; i++)
		for (j = 0; j < p[i].c; j++)
			for (k = p[i].a-p[i].h; k >= 0; k--)
				d[k+p[i].h] = d[k+p[i].h]||d[k];
	for (k = 40100; k >= 0 && !d[k]; k--);
	printf("%d\n", k);
	return 0;
}
