/*
TASK:frogs
LANG:C
*/
#define PROG 1

#if PROG
#include <stdio.h>
#define inf 2000000000

int h[1000010], j[1000010], s[1000010];
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n, m, p, q, k, i;
	scanf("%d", &n);
	for (i = n-1; i >= 0; i--)
		scanf("%d", h+i);
	for (i = n-1; i >= 0; i--)
		scanf("%d", j+i);
	m = k = 1;
	s[0] = h[0];
	for (i = 1; i < n; i++)
	{
        if(h[i] >= s[0])
		{
			k = 0;
			s[0] = h[i];
        }
        else
		{
			p = 0;
			q = k;
			while (q-p > 1)
			{
				k = (p+q)>>1;
				if (h[i] == s[k])
					break;
				if (h[i] < s[k])
					p = k;
				else
					q = k;
			}
			if (q-p <= 1)
				if (s[p] <= h[i])
					k = p;
				else
					if (s[q] <= h[i])
						k = q;
					else
						k = q+1;
			s[k] = h[i];
		}
		if (m < k+1)
			m = k+1;
		if (k < j[i])
			j[i] = -1;
		else
			j[i] = s[k-j[i]];
	}
	for (i = n-1; i > 0; i--)
		printf("%d ", j[i]);
	printf("-1\n");
	return 0;
}
#endif

#if !PROG
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define inf 2000000000

int h[1000010], j[1000010];
int main()
{
	FILE* fin = fopen("input.txt", "w");
	FILE* fout = fopen("test.txt", "w");
	int n, p, k, i;
	scanf("%d", &n);
	fprintf(fin, "%d\n", n);
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		h[i] = rand();
		fprintf(fin, "%d ", h[i]);
		j[i] = 1+rand()%100;
	}
	fputc('\n', fin);
	for (i = 0; i < n; i++)
		fprintf(fin, "%d ", j[i]);
	fputc('\n', fin);
/*	h[n] = inf;
	for (i = 0; i < n-1; i++)
	{
		p = i;
		for (k = i+1; k <= n && j[i]; k++)
			if (h[k] > h[p])
			{
				j[i]--;
				p = k;
			}
		if (k == n+1)
			fprintf(fout, "-1 ");
		else
			fprintf(fout, "%d ", h[p]);
	}
	fprintf(fout, "-1\n");*/
	return 0;
}
#endif
