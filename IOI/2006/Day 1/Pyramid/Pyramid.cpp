#include <stdio.h>
#include <string.h>
#define inf 1000000000

int r[4][1010];
int S[1010][1010], D[1010][1010];
int R[1010][1010], C[1010][1010], Rv[1010][1010], Cv[1010][1010];
void solve(int n, int l)
{
	int i, j;
	for (i = n-l+1; i >= 1; i-=l)
	{
		r[1][i] = r[2][i] = i;
		for (j = i+1; j < i+l; j++)
			if (r[0][j] < r[0][r[1][j-1]])
				r[1][j] = j;
			else
				r[1][j] = r[1][j-1];
		for (j = i-1; j >= 1 && j+l > i; j--)
			if (r[0][j] < r[0][r[2][j+1]])
				r[2][j] = j;
			else
				r[2][j] = r[2][j+1];
		for (j = i; j < i+l; j++)
			if (j >= l)
				if (r[0][r[1][j]] < r[0][r[2][j-l+1]])
					r[3][j] = r[1][j];
				else
					r[3][j] = r[2][j-l+1];
			else
				r[3][j] = r[1][j];
	}
}
int main()
{
	freopen("pyramid.in", "r", stdin);
	freopen("pyramid.out", "w", stdout);
	int H;
	short Ma, Mb, Mc, Md; 
	short n, m, a, b, c, d, p, i, j;
	scanf("%hd%hd%hd%hd%hd%hd", &m, &n, &b, &a, &d, &c);
	memset(S, 0, sizeof(S));
	for (i = 0; i <= n; i++)
		for (j = 0; j <= m; j++)
			D[i][j] = Rv[i][j] = Cv[i][j] = inf;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%hd", &p);
			S[i][j] = S[i][j-1]+S[i-1][j]-S[i-1][j-1]+p;
			if (i >= c && j >= d)
				D[i][j] = S[i][j]-S[i][j-d]-S[i-c][j]+S[i-c][j-d];
			else
				D[i][j] = inf;
		}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			r[0][j] = D[i][j];
		solve(m, b-d-1);
		for (j = 1; j <= m; j++)
			if (r[3][j])
			{
				R[i][j] = r[3][j];
				Rv[i][j] = D[i][r[3][j]];
			}
	}
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
			r[0][j] = Rv[j][i];
		solve(n, a-c-1);
		for (j = 1; j <= n; j++)
			if (r[3][j])
			{
				C[j][i] = r[3][j];
				Cv[j][i] = Rv[r[3][j]][i];
			}
	}
	H = -1;
	for (i = a; i <= n; i++)
		for (j = b; j <= m; j++)
			if (H < S[i][j]-S[i-a][j]-S[i][j-b]+S[i-a][j-b]-Cv[i-1][j-1])
			{
				Ma = i;
				Mb = j;
				Mc = C[i-1][j-1];
				Md = R[Mc][j-1];
				H = S[i][j]-S[i-a][j]-S[i][j-b]+S[i-a][j-b]-Cv[i-1][j-1];
			}
	printf("%hd %hd\n%hd %hd\n", Mb-b+1, Ma-a+1, Md-d+1, Mc-c+1);
	return 0;
}
