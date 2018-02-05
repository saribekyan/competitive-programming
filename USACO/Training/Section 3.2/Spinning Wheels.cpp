/*
PROG: spin
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>

int speed[5];
bool w[5][360];
FILE* fin = fopen("spin.in", "r");
FILE* fout = fopen("spin.out", "w");
int main()
{
	int n, i, j, k, p, q;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 360; j++)
			w[i][j] = 0;
	for (i = 0; i < 5; i++)
	{
		fscanf(fin, "%d%d", speed+i, &n);
		for (j = 0; j < n; j++)
		{
			fscanf(fin, "%d%d", &p, &q);
			for (k = q; k >= 0; k--)
				w[i][(p+k)%360] = 1;
		}
	}
	for (i = 0; i <= 360; i++)
		for (j = 0; j < 360; j++)
		{
			for (k = 0; k < 5; k++)
				if (!w[k][(3600000+j-i*speed[k])%360])
					break;
			if (k == 5)
			{
				fprintf(fout, "%d\n", i);
				return 0;
			}
		}
	fprintf(fout, "none\n");
	return 0;
}