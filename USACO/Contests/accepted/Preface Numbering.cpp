#include <stdio.h>
#include <math.h>

int d[7], ans[7];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int g, n, m, p, q, i;
	fscanf(fin, "%d", &g);
	for (n = 1; n <= g; n++)
	{
		for (i = 0; i < 7; i++)
			d[i] = 0;
		p = n;
		q = 10;
		while (p)
		{
			m = p%q;
			p -= m;
			if (q == 10)
			{
				if (m < 4)
					d[0] += m;
				if (m > 3 && m < 9)
				{
					d[0] += abs(5-m);
					d[1]++;
				}
				if (m == 9)
				{
					d[2]++;
					d[0]++;
				}
			}
			if (q == 100)
			{
				if (m < 40)
					d[2] += m/10;
				if (m > 30 && m < 90)
				{
					d[2] += abs((50-m)/10);
					d[3]++;
				}
				if (m == 90)
				{
					d[4]++;
					d[2]++;
				}
			}
			if (q == 1000)
			{
				if (m < 400)
					d[4] += m/100;
				if (m > 300 && m < 900)
				{
					d[4] += abs((500-m)/100);
					d[5]++;
				}
				if (m == 900)
				{
					d[6]++;
					d[4]++;
				}
			}
			if (q == 10000)
				d[6] += m/1000;
			q *= 10;
		}
		for (i = 0; i < 7; i++)
			ans[i] += d[i];
	}
	i = 6;
	while (ans[i]==0)
		i--;
	if (i == 0)
		fprintf(fout, "I %d\n", ans[0]);
	if (i == 1)
		fprintf(fout, "I %d\nV %d\n", ans[0], ans[1]);
	if (i == 2)
		fprintf(fout, "I %d\nV %d\nX %d\n", ans[0], ans[1], ans[2]);
	if (i == 3)
		fprintf(fout, "I %d\nV %d\nX %d\nL %d\n", ans[0], ans[1], ans[2], ans[3]);
	if (i == 4)
		fprintf(fout, "I %d\nV %d\nX %d\nL %d\nC %d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
	if (i == 5)
		fprintf(fout, "I %d\nV %d\nX %d\nL %d\nC %d\nD %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);
	if (i == 6)
		fprintf(fout, "I %d\nV %d\nX %d\nL %d\nC %d\nD %d\nM %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5], ans[6]);
	return 0;
}