#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 25;
struct P{int r, i; bool f;};
P X[2*MAX], Y[2*MAX];
bool Z[MAX];
bool operator < (P p, P q){return p.r < q.r || p.r==q.r && p.f<q.f;}
int main()
{
	int n, count, i, j, p;
	bool f;
	scanf("%d", &n);
	for (i = 0; i < 2*n;)
	{
		scanf("%d%d", &X[i].r, &Y[i].r);
		X[i].i = Y[i].i = i/2;
		X[i].f = Y[i].f = 1;
		i++;
		scanf("%d%d", &X[i].r, &Y[i].r);
		X[i].i = Y[i].i = i/2;
		X[i].f = Y[i].f = 0;
		i++;
	}
	sort(X, X+2*n);
	sort(Y, Y+2*n);
	for (i = 0; i < n; i++)
		Z[i] = false;
	p = 0;
	f = false;
	for (i = 1; i < 2*n; i++)
	{
		Z[X[i-1].i] = X[i-1].f;
		count = 0;
		for (j = 0; j < 2*n; j++)
		{
			if (Z[Y[j].i])
			{
				if (Y[j].f)
					count++;
				else
					count--;
				f = true;
			}
			if (count==0 && f)
			{
				p += 2*(X[i].r-X[i-1].r);
				f = false;
			}
		}
	}
	for (i = 0; i < n; i++)
		Z[i] = false;
	f = false;
	for (i = 1; i < 2*n; i++)
	{
		Z[Y[i-1].i] = Y[i-1].f;
		count = 0;
		for (j = 0; j < 2*n; j++)
		{
			if (Z[X[j].i])
			{
				if (X[j].f)
					count++;
				else
					count--;
				f = true;
			}
			if (count==0 && f)
			{
				p += 2*(Y[i].r-Y[i-1].r);
				f = false;
			}
		}
	}
	printf("%d\n", p);
	return 0;
}