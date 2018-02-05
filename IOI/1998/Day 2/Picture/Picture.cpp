#include <cstdio>
#include <algorithm>
using namespace std;

bool t[5010];
struct point
{
	int c, i;
	bool open;
} C[2][10010];
bool operator < (point a, point b)
{
	return a.c < b.c || (a.c == b.c && a.open && !b.open);
}
int main()
{
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	int n, c, p, l, i, j;
	scanf("%d", &n);
	for (i = 0; i < 2*n; i+=2)
	{
		scanf("%d%d%d%d", &C[0][i].c, &C[1][i].c, &C[0][i+1].c, &C[1][i+1].c);
		C[0][i].open = C[1][i].open = 1;
		C[0][i+1].open = C[1][i+1].open = 0;
		C[0][i].i = C[1][i].i = C[0][i+1].i = C[1][i+1].i = i/2;
	}
	sort(C[0], C[0]+2*n);
	sort(C[1], C[1]+2*n);
	for (p = l = 0; l < 2; l++)
	{
		memset(t, 0, sizeof(t));
		for (i = 0; i+1 < 2*n; i++)
		{
			t[C[l][i].i] = C[l][i].open;
			for (c = j = 0; j < 2*n; j++)
				if (t[C[1-l][j].i])
				{
					if (C[1-l][j].open)
						c++;
					else
						c--;
					if (c == 0)
						p += 2*(C[l][i+1].c-C[l][i].c);
				}
		}
	}
	printf("%d\n", p);
	return 0;
}
