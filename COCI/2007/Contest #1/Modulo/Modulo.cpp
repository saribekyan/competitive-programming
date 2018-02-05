#include <cstdio>
#include <algorithm>
using namespace std;

int d[10];
FILE* fin = fopen("modulo.in", "r");
FILE* fout = fopen("modulo.out", "w");
int main()
{
	int n, i;
	for (i = 0; i < 10; i++)
	{
		fscanf(fin, "%d", &n);
		d[i] = n%42;
	}
	sort(d, d+10);
	i = n = 0;
	while (1)
	{
		while (i < 10 && d[i] == d[i+1])
			i++;
		i++;
		n++;
		if (i == 10)break;
	}
	fprintf(fout, "%d\n", n);
	return 0;
}
