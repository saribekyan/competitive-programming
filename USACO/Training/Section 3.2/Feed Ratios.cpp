/*
PROG: ratios
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int d[4][3];
FILE* fin = fopen("ratios.in", "r");
FILE* fout = fopen("ratios.out", "w");
int main()
{
	int i, j, k;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			fscanf(fin, "%d", &d[i][j]);
	for (i = 0; i <= 100; i++)
		for (j = 0; j <= 100; j++)
			for (k = 0; k <= 100; k++)
				if ((d[0][0] == 0 || (d[0][0] && (d[1][0]*i+d[2][0]*j+d[3][0]*k)%d[0][0] == 0)) &&
					(d[0][1] == 0 || (d[0][1] && (d[1][1]*i+d[2][1]*j+d[3][1]*k)%d[0][1] == 0)) &&
					(d[0][2] == 0 || (d[0][2] && (d[1][2]*i+d[2][2]*j+d[3][2]*k)%d[0][2] == 0)) &&
					(d[1][0]*i+d[2][0]*j+d[3][0]*k)*d[0][1] == (d[1][1]*i+d[2][1]*j+d[3][1]*k)*d[0][0] &&
					(d[1][1]*i+d[2][1]*j+d[3][1]*k)*d[0][2] == (d[1][2]*i+d[2][2]*j+d[3][2]*k)*d[0][1] &&
					((d[1][0]*i+d[2][0]*j+d[3][0]*k) ||
					(d[1][1]*i+d[2][1]*j+d[3][1]*k) ||
					(d[1][2]*i+d[2][2]*j+d[3][2]*k)))
					goto there;
there:;
	if (i == 101)
		fprintf(fout, "NONE\n");
	else
		fprintf(fout, "%d %d %d %d\n", i, j, k, (d[1][0]*i+d[2][0]*j+d[3][0]*k)/d[0][0]);
	return 0;
}