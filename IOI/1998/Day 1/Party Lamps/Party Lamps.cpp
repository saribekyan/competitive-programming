#include <cstdio>
#include <algorithm>
using namespace std;

int on[3], off[3];
char bin[4];
bool cmp(char *a, char *b)
{
	if (strcmp(a, b) == 1)
		return 0;
	return 1;
}
FILE* fin = fopen("party.in", "r");
FILE* fout = fopen("party.out", "w");
int main()
{
	int len, n, m, s, t, p, q, i;
	fscanf(fin, "%d%d", &len, &n);
	p = q = 0;
	while (fscanf(fin, "%d", on+p) && on[p++] != -1);
	while (fscanf(fin, "%d", off+q) && off[q++] != -1);
	p--;
	q--;
	for (m = 0; m < 16; m++)
	{
		s = 0;
		for (i = 3, t = m; i >= 0; i--, t>>=1)
		{
			bin[i] = (t%2)+'0';
			s += t%2;
		}
		if (s <= n && s%2 == n%2)
		{
			for (i = 0; i < p; i++)
			{
				s = bin[0]-'0';
				if (on[i]%3 == 1)
					s += bin[1]-'0';
				if (on[i]%2)
					s += bin[2]-'0';
				else
					s += bin[3]-'0';
				if (s%2)
					break;
			}
			if (i == p)
			{
				for (i = 0; i < q; i++)
				{
					s = bin[0]-'0';
					if (off[i]%3 == 1)
						s += bin[1]-'0';
					if (off[i]%2)
						s += bin[2]-'0';
					else
						s += bin[3]-'0';
					if (s%2 == 0)
						break;
				}
				if (i == q)
				{
					for (i = 1; i <= len; i++)
					{
						s = bin[0]-'0';
						if (i%3 == 1)
							s += bin[1]-'0';
						if (i%2)
							s += bin[2]-'0';
						else
							s += bin[3]-'0';
						fprintf(fout, "%c", ((s+1)%2)+'0');
					}
					fputc('\n', fout);
				}
			}
		}
	}
	return 0;
}