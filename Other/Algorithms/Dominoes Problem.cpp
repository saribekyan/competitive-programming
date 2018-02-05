#include <stdio.h>
#include <string.h>
#define NMAX 256
#define MMAX 21

unsigned long long d[NMAX][MMAX];

int main()
{
	int n, m, i, j, k, p, q, l, w;
	while (scanf("%d%d", &n, &m)==2)
	{
		if (n%2 && m%2)printf("0\n");
		else
		{
			if (n > m)
			{
				n ^= m;
				m ^= n;
				n ^= m;
			}
			w = n;
			n = 1<<n;
			memset(d, 0, sizeof(d));
			d[0][0] = 1;
			for (j = 1; j <= m; j++)
			{
				d[n-1][j] = d[0][j-1];
				for (i = 0; i < n-1; i++)
					for (k = 0; k < n; k++)
						if ((i&k)==0)
						{
							p = i^k;
							q = l = 0;
							do
							{
								if (p&1)
									if (q&1)
										break;
									else
										q = 0;
								else
									q++;
								p >>= 1;
								l++;
							}
							while (p);
							if (p == 0 && ((q+w-l)&1) == 0)
								d[i][j] += d[k][j-1];
						}
			}
			printf("%lld\n", d[0][m]);
		}
	}
	return 0;
}
