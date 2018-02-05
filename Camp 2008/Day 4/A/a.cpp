#include <stdio.h>
#include <string.h>
//#include <iostream>
//using namespace std;

char s[100];
bool t[730];
short d[81][81][730], len[81][81];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	short n, l, i, j, k, x, y;
	scanf("%s", s);
	n = strlen(s);
	for (i = 0; i < n; i++)
		if (s[i] == '+' || s[i] == '-')
			len[i][i] = 0;
		else
		{
			d[i][i][0] = s[i]-'0';
			len[i][i] = 1;
		}
	for (l = 2; l <= n; l++)
		for (i = 0; i+l <= n; i++)
		{
			memset(t, 0, sizeof(t));
/////////////////////// infix
			j = i+l-1;
			for (k = i+1; k < j; k++)
			{
				if (s[k] == '+')
					for (x = 0; x < len[i][k-1]; x++)
						for (y = 0; y < len[k+1][j]; y++)
							t[d[i][k-1][x]+d[k+1][j][y]+360] = 1;
				if (s[k] == '-')
					for (x = 0; x < len[i][k-1]; x++)
						for (y = 0; y < len[k+1][j]; y++)
							t[d[i][k-1][x]-d[k+1][j][y]+360] = 1;
			}
/////////////////////// postfix
			if (s[j] == '+')
				for (k = i; k+1 < j; k++)
					for (x = 0; x < len[i][k]; x++)
						for (y = 0; y < len[k+1][j-1]; y++)
							t[d[i][k][x]+d[k+1][j-1][y]+360] = 1;
			if (s[j] == '-')
				for (k = i; k+1 < j; k++)
					for (x = 0; x < len[i][k]; x++)
						for (y = 0; y < len[k+1][j-1]; y++)
							t[d[i][k][x]-d[k+1][j-1][y]+360] = 1;
/////////////////////// prefix
/*			if (l == 3 && i == 0)
	 		{
				cerr << i << ' ' << j << '\n';
				cerr << s[i] << '\n';
			}*/
			if (s[i] == '+')
				for (k = i+1; k < j; k++)
					for (x = 0; x < len[i+1][k]; x++)
						for (y = 0; y < len[k+1][j]; y++)
							t[d[i+1][k][x]+d[k+1][j][y]+360] = 1;
			if (s[i] == '-')
				for (k = i+1; k < j; k++)
					for (x = 0; x < len[i+1][k]; x++)
						for (y = 0; y < len[k+1][j]; y++)
							t[d[i+1][k][x]-d[k+1][j][y]+360] = 1;
/////////////////////// calculate d[i][j]
			len[i][j] = 0;
			for (k = 0; k <= 720; k++)
				if (t[k])
					d[i][j][len[i][j]++] = k-360;
		}
///////////////////////////////
/*	cerr << '\n';
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cerr << len[i][j] << ' ';
		cerr << '\n';
	}*/
///////////////////////////////
	printf("%hd\n", len[0][n-1]);
	return 0;
}
