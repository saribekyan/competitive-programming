#include <stdio.h>
#include <string.h>
#define inf 123456789
#define Min(a, b) ((a)<(b)?(a):(b))

int n, l;
bool found;
bool t[210];
int way[210];
int ans[110];
int d[210][210];
int X[101], Y[101];
int N[101], M[101];
void dfs(int p)
{
	if (p == 2*n-1)
	{
		found = 1;
		return;
	}
	int i;
	for (i = 0; i+1 <= 2*n; i++)
		if (!t[i] && d[p][i])
		{
			t[i] = 1;
			way[l++] = i;
			dfs(i);
			if (found)
				return;
			l--;
		}
}
int main()
{
	double D;
	int T, F, P, p, m, i, j, k;
	scanf("%d", &T);
	while (T)
	{
		scanf("%d%lf", &n, &D);
		for (P = i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", X+i, Y+i, N+i, M+i);
			P += N[i];
		}
		for (p = i = 0; i < n; i++)
		{
			memset(d, 0, sizeof(d));
			for (j = 0; j < n; j++)
				if (i != j)
				{
					d[0][j+1-(int)(j>i)] = N[j];
					d[j+1-(int)(j>i)][n+j-(int)(j>i)] = M[j];
					if ((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]) <= D*D)
						d[n+j-(int)(j>i)][2*n-1] = inf;
				}
			for (j = 0; j < n; j++)
				if (i != j)
					for (k = j+1; k < n; k++)
						if (i != k)
							if ((X[j]-X[k])*(X[j]-X[k])+(Y[j]-Y[k])*(Y[j]-Y[k]) <= D*D)
								d[n+k-(int)(k>i)][j+1-(int)(j>i)] = d[n+j-(int)(j>i)][k+1-(int)(k>i)] = inf;
			way[0] = 0;
			F = 0;
			while (1)
			{
				l = 1;
				found = 0;
				memset(t, 0, sizeof(t));
				t[0] = 1;
				dfs(0);
				if (!found)
					break;
				m = inf;
				for (j = 0; j < l-1; j++)
					m = Min(m, d[way[j]][way[j+1]]);
				for (j = 0; j < l-1; j++)
				{
					d[way[j]][way[j+1]] -= m;
					d[way[j+1]][way[j]] += m;
				}
				F += m;
			}
			if (F >= P-N[i])
				ans[p++] = i;
		}
		if (p == 0)
			printf("-1\n");
		else
		{
			for (i = 0; i < p-1; i++)
				printf("%d ", ans[i]);
			printf("%d\n", ans[i]);
		}
		T--;
	}
	return 0;
}
