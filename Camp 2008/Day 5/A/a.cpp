#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct pos
{
	int a[3];
} s, p, q;
queue<pos> Q;
int d[61][61][61];
pos pr[61][61][61];
void print(pos p)
{
	if (p.a[0] != s.a[0] || p.a[1] != s.a[1] || p.a[2] != s.a[2])
		print(pr[p.a[0]][p.a[1]][p.a[2]]);
	printf("%4d%4d%4d\n", p.a[0], p.a[1], p.a[2]);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j;
	scanf("%d%d%d", s.a, s.a+1, s.a+2);
	memset(d, -1, sizeof(d));
	d[s.a[0]][s.a[1]][s.a[2]] = 0;
	Q.push(s);
	while (!Q.empty())
	{
		p = Q.front();
		if (p.a[0] == p.a[1] && p.a[1] == p.a[2])
			break;
		Q.pop();
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (i != j && p.a[i] >= p.a[j])
				{
					q = p;
					q.a[i] -= q.a[j];
					q.a[j] *= 2;
					if (d[q.a[0]][q.a[1]][q.a[2]] == -1)
					{
						d[q.a[0]][q.a[1]][q.a[2]] = d[p.a[0]][p.a[1]][p.a[2]]+1;
						pr[q.a[0]][q.a[1]][q.a[2]] = p;
						Q.push(q);
					}
				}
	}
	if (Q.empty())
		printf("%4d%4d%4d\n", s.a[0], s.a[1], s.a[2]);
	else
		print(p);
	return 0;
}
