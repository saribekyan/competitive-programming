#include <stdio.h>
#include <string.h>

long long d[16][1010];

int main()
{
	int t, ts, n, m, i, j, k, p, q, l, w;
	scanf("%d", &t);
	for (ts = 1; ts <= t; ts++)
	{
		n = 4;
		scanf("%d", &m);
		if (n%2 && m%2)
			printf("0\n");
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
			for (i = 0; i < n; i++)
				for (j = 0; j <= m; j++)
					d[i][j] = 0;
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
			printf("%d %lld\n", ts, d[0][m]);
		}
	}
	return 0;
}