#include <cstdio>

int d[1000000], s[1000000];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int n, m, p, q, k, i;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		s[i] = 2147483647;
	s[0] = d[0];
	m = 1;
	for (i = 1; i < n; i++)
	{
		p = 0;
		q = m-1;
		if (d[i] <= s[0])
		{
			k = 0;
			s[0] = d[i];
		}
		else
			while (1)
			{
				k = (p+q+1)/2;
				if (d[i] > s[k] && d[i] < s[k+1])
				{
					k++;
					break;
				}
				if (d[i] > s[k])
					p = k+1;
				else
					q = k-1;
			}
		s[k] = d[i];
		if (m < k+1)
			m = k+1;
	}
	fprintf(fout, "%d\n", m);
	for (i = 0; i < m-1; i++)
		fprintf(fout, "%d ", s[i]);
	fprintf(fout, "%d\n", s[m-1]);
	return 0;
}