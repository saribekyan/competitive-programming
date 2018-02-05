#include <cstdio>
#include <algorithm>
using namespace std;

int m[6];
int a[12];
int main()
{
	char ch;
	int t, s, l, i, j;
	for (t = 0; t < 2; t++)
	{
		memset(m, 0, sizeof(m));
		for (s = i = 0; i < 12;)
		{
			ch = getchar();
			if (ch == ' ' || ch == '\n')
			{
				if (l%2 == 0)
				{
					if (s%3 == 0)
						a[i] = 0;
					if (s%3 == 1)
						a[i] = 4;
					if (s%3 == 2)
						a[i] = 2;
				}
				else
				{
					if (s%3 == 0)
						a[i] = 3;
					if (s%3 == 1)
						a[i] = 1;
					if (s%3 == 2)
						a[i] = 5;
				}
				m[a[i]]++;
				s = 0;
				i++;
				continue;
			}
			l = ch-'0';
			s += l;
		}
		s = 0;
		sort(a, a+12);
		do
		{
			s += !((a[0]+a[1]+a[2]+a[3])%2 || (a[4]+a[5]+a[6]+a[7])%2 || (a[8]+a[9]+a[10]+a[11])%2 ||
				(a[0]+a[4]+a[8])%3 || (a[1]+a[5]+a[9])%3 || (a[2]+a[6]+a[10])%3 || (a[3]+a[7]+a[11])%3);
		}
		while (next_permutation(a, a+12));
		for (i = 0; i < 6; i++)
			for (j = 1; j <= m[i]; j++)
				s *= j;
		printf("%d\n", s/144);
	}
	return 0;
}
