#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 25
struct P{double xy; int i; bool f;};
bool operator <(P a, P b){return a.xy < b.xy;}
P X[2*MAX], Y[2*MAX];
bool Z[MAX];
int main()
{
	int n, i, j, count, k;
	double s;
	scanf("%d", &n);
	for (i = 0; i < 2*n;)
	{
		scanf("%lf%lf", &X[i].xy, &Y[i].xy);
		i++;
		scanf("%lf%lf", &X[i].xy, &Y[i].xy);
		X[i-1].i = Y[i-1].i = X[i].i = Y[i].i = i/2;
		X[i-1].f = Y[i-1].f = 1;
		X[i].f = Y[i].f = 0;
		i++;
	}
	sort(X, X+2*n);
	sort(Y, Y+2*n);
	for (i = 0; i < n; i++)
		Z[i] = 0;
	k = 0;
	s = 0;
	for (i = 1; i < 2*n; i++)
	{
		Z[X[i-1].i] = X[i-1].f;
		if (Z[X[i-1].i])
			k++;
		else
			k--;
		count = 0;
		if (k == n)
		{
			for (j = 0; j < 2*n; j++)
			{
				if (Z[Y[j].i])
					if (Y[j].f)
						count++;
					else
						count--;
				if (count==n)
					s += (Y[j+1].xy-Y[j].xy)*(X[i].xy-X[i-1].xy);
			}
		}
	}
	if (s)
		printf("%lf\n", s);
	else
		printf("There is no a Traversal.\n");
	return 0;
}
/*
test:
3
0 0 10 10
5 5 15 15
-1.5 0 7 8
ans:
6
*/