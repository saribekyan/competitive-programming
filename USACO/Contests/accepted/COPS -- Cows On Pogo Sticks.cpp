#include <cstdio>
#include <queue>
using namespace std;

struct s{int jump, place, speed;};
queue<s> d;
bool g[501], t[50][501];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	s r, p;
	int n, m, i, j;
	fscanf(fin, "%d%d", &n, &m);
	for (i = 0; i <= n; i++)
	{
		g[i] = 0;
		for (j = 0; j < 50; j++)
			t[j][i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d", &j);
		g[j] = 1;
	}
	r.jump = r.place = r.speed = 0;
	d.push(r);
	t[0][0] = 1;
	while (!d.empty())
	{
		p = d.front();
		if (p.place == n)
		{
			fprintf(fout, "%d\n", p.jump);
			return 0;
		}
		r.speed = p.speed+1;
		r.place = p.place+r.speed;
		r.jump = p.jump+1;
		if (r.place <= n && g[r.place] == 0 && t[r.speed][r.place] == 0)
		{
			d.push(r);
			t[r.speed][r.place] = 1;
		}
		r.speed = p.speed;
		r.place = p.place+r.speed;
		if (r.speed > 0 && r.place > 0 && r.place <= n && g[r.place] == 0 && t[r.speed][r.place] == 0)
		{
			d.push(r);
			t[r.speed][r.place] = 1;
		}
		r.speed = p.speed-1;
		r.place = p.place+r.speed;
		if (r.speed > 0 && r.place > 0 && r.place <= n && g[r.place] == 0 && t[r.speed][r.place] == 0)
		{
			d.push(r);
			t[r.speed][r.place] = 1;
		}
		d.pop();
	}
	fprintf(fout, "-1\n");
	return 0;
}