#include <cstdio>

bool t[52];
int d[52][52];
char s[52], ch1, ch2;
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int n, m, i, j, k, w;
	fscanf(fin, "%d\n", &m);
	n = 0;
	for (i = 0; i < 52; i++)
		for (j = 0; j < 52; j++)
			d[i][j] = 1073741823;
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%c %c%d\n", &ch1, &ch2, &w);
		for (j = 0; j < n; j++)
			if (s[j] == ch1)
				break;
		s[j] = ch1;
		if (j == n)
			n++;
		for (k = 0; k < n; k++)
			if (s[k] == ch2)
				break;
		s[k] = ch2;
		if (k == n)
			n++;
		if (d[j][k] > w)
			d[j][k] = d[k][j] = w;
	}
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (d[i][j] > d[i][k]+d[k][j])
					d[i][j] = d[i][k]+d[k][j];
	for (k = 0; k < n; k++)
		if (s[k] == 'Z')
			break;
	w = 1073741823;
	for (i = 0; i < n; i++)
		if (d[i][k] < w && s[i] >= 'A' && s[i] < 'Z')
		{
			j = i;
			w = d[i][k];
		}
	fprintf(fout, "%c %d\n", s[j], w);
	return 0;
}