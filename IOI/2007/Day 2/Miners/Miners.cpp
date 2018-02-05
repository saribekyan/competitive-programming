#include <stdio.h>
#include <string.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int f[100010];
int d[2][4][4][4][4];
int add(int a, int b, int c)
{
	int d;
	d = Min(a, Min(b, c));
	if (a == 3)
		a = d;
	if (b == 3)
		b = d;
	if (c == 3)
		c = d;
	if (a != b && a != c && b != c)
		return 3;
	if (a == b && a != c || a == c && a != b || b == c && b != a)
		return 2;
	return 1;
}
int main()
{
	char ch;
	int n, sw, r, i, j, k, l;
	scanf("%d", &n);
	n += 4;
	getchar();
	for (i = 4; i < n; i++)
	{
		scanf("%c", &ch);
		if (ch == 'B')
			f[i] = 0;
		if (ch == 'F')
			f[i] = 1;
		if (ch == 'M')
			f[i] = 2;
	}
	sw = 0;
	for (i = 0; i < 4; i++)
		f[i] = 3;
	memset(d, -1, sizeof(d));
	d[sw][3][3][3][3] = 0;
	for (r = 4; r < n; r++)
	{
		memset(d[1-sw], -1, sizeof(d[1-sw]));
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				for (k = 0; k < 4; k++)
					for (l = 0; l < 4; l++)
						if (d[sw][i][j][k][l] != -1)
						{
							d[1-sw][i][j][f[r]][k] = Max(d[1-sw][i][j][f[r]][k], d[sw][i][j][k][l]+add(k, l, f[r]));
							d[1-sw][f[r]][i][k][l] = Max(d[1-sw][f[r]][i][k][l], d[sw][i][j][k][l]+add(i, j, f[r]));
						}
		sw = 1-sw;
	}
	r = -1;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				for (l = 0; l < 4; l++)
					r = Max(r, d[sw][i][j][k][l]);
	printf("%d\n", r);
	return 0;
}
