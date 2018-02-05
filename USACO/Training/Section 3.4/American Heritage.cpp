/*
PROG: heritage
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <string.h>
int n, l;
char in[27], pre[27], post[27];
FILE* fin = fopen("heritage.in", "r");
FILE* fout = fopen("heritage.out", "w");
void rec(int p, int q, int u, int v)
{
	int i;
	for (i = p; i <= q; i++)
		if (in[i] == pre[u])
		{
			post[l--] = pre[u];
			rec(i+1, q, u+i-p+1, v);
			rec(p, i, u+1, u+i-p+1);
		}
}
int main()
{
	fscanf(fin, "%s%s", in, pre);
	n = strlen(in);
	l = n-1;
	post[n] = 0;
	rec(0, l, 0, l);
	fprintf(fout, "%s\n", post);
	return 0;
}