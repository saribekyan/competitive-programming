#include <cstdio>

char s[3000000], ans[12];
int number[8193], d[100];
FILE* fin = fopen("contact.in", "r");
FILE* fout = fopen("contact.out", "w");
int main()
{
	char c;
	int n, m, bin, a, b, i, j, k, l, w;
	fscanf(fin, "%d%d%d\n", &a, &b, &m);
	n = 0;
	while (fscanf(fin, "%c", s+n) && s[n++] != '2');
	n--;
	k = (1<<(b+1));
	for (i = 0; i <= k; i++)
		number[i] = 0;
	for (i = 0; i < n; i++)
		for (j = a; j <= b; j++)
			if (i+j <= n)
			{
				bin = 1;
				for (l = i; l < i+j; l++)
					bin = (bin<<1)+(s[l]-'0');
				number[bin]++;
			}
	for (i = 0; i < m; i++)
	{
		l = w = 0;
		for (j = 0; j <= k; j++)
		{
			if (w < number[j])
			{
				l = 0;
				w = number[j];
			}
			if (w == number[j])
				d[l++] = j;
		}
		if (w == 0)
			return 0;
		fprintf(fout, "%d", w);
		for (j = l-1; j >= 0; j--)
		{
			a = 0;
			w = d[j];
			while (w)
			{
				ans[a++] = (w%2)+'0';
				w >>= 1;
			}
			a -= 2;
			fputc(' ', fout);
			while (a != -1)
			{
				fputc(ans[a], fout);
				a--;
			}
			number[d[j]] = 0;
		}
		fputc('\n', fout);
	}
	return 0;
}
