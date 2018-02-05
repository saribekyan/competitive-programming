#include <cstdio>
#include <string.h>

int prime[20] = 
{3, 1429, 949967, 5, 1060091, 7, 1277323, 683, 1549, 459353, 29, 844897, 919, 1571,
569579, 38299, 39251, 13, 827, 835847};
char hash_table[1000000][20], a[20], b[20];
int hash_function(char *s)
{
	int n, m, i;
	m = 0;
	n = strlen(s);
	for (i = 0; i < n; i++)
		m = (m+(((int)s[i])*prime[i]))%999983;
	return m;
}
FILE* fin = fopen("dictironary.in", "r");
FILE* fout = fopen("dictionary.out", "w");
int main()
{
	int n, i;
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%s%s", a, b);
		strcpy(hash_table[hash_function(a)], b);
	}
	fscanf(fin, "%s", a);
	fprintf(fout, "%s\n", hash_table[hash_function(a)]);
	return 0;
}