#include <cstdio>
int d[50000];
FILE* fin = fopen("stumps.in", "r");
FILE* fout = fopen("stumps.out", "w");
int main()
{
	int n, i;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fin, "%d", d+i);
	i = 0;
	while (i != n)
	{
		while (i < n-1 && d[i] < d[i+1])
			i++;
		fprintf(fout, "%d\n", i+1);
		while (i < n-1 && d[i] > d[i+1])
			i++;
		i++;
	}
	return 0;
}