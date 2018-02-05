#include <cstdio>
#include <algorithm>
using namespace std;

char s[5000];
int d1[5000], d2[5000];
FILE* fin = fopen("palin.in", "r");
FILE* fout = fopen("palin.out", "w");
int main()
{
	int n, i, j;
	fscanf(fin, "%d%s", &n, s);
	for (i = n-2; i >= 0; i--)
	{
		for (j = i+1; j < n; j++)
			if (s[i] == s[j])
				d1[j] = d2[j-1];
			else
				if (d2[j] < d1[j-1])
					d1[j] = d2[j]+1;
				else
					d1[j] = d1[j-1]+1;
		for (j = 0; j < n; j++)
			d2[j] = d1[j];
	}
	fprintf(fout, "%d\n", d1[n-1]);
	return 0;
}