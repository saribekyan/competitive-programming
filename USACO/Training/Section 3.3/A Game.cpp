/*
PROG: game1
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int g[100];
struct score{int player1, player2;}d[100][100];
FILE* fin = fopen("game1.in", "r");
FILE* fout = fopen("game1.out", "w");
int main()
{
	int n, i, j, k;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", g+i);
	for (i = 0; i < n; i++)
	{
		d[i][i].player2 = 0;
		d[i][i].player1 = g[i];
	}
	for (i = 0; i < n; i++)
		for (j = i+1, k = 0; j < n; j++, k++)
			if ((j-k+1)%2)
				if (d[k][j-1].player1+g[j] > d[k+1][j].player1+g[k])
				{
					d[k][j].player1 = d[k][j-1].player1+g[j];
					d[k][j].player2 = d[k][j-1].player2;
				}
				else
				{
					d[k][j].player1 = d[k+1][j].player1+g[k];
					d[k][j].player2 = d[k+1][j].player2;
				}
			else
				if (d[k][j-1].player2+g[j] > d[k+1][j].player2+g[k])
				{
					d[k][j].player2 = d[k][j-1].player2+g[j];
					d[k][j].player1 = d[k][j-1].player1;
				}
				else
				{
					d[k][j].player2 = d[k+1][j].player2+g[k];
					d[k][j].player1 = d[k+1][j].player1;
				}
	if (n%2)
		fprintf(fout, "%d %d\n", d[0][n-1].player1, d[0][n-1].player2);
	else
		fprintf(fout, "%d %d\n", d[0][n-1].player2, d[0][n-1].player1);
	return 0;
}