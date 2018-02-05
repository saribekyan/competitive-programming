#include <stdio.h>
#include <string.h>
//#include <iostream>
//using namespace std;

int d[500];
char s[500];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, l, i, j;
	s[0] = '(';
	scanf("%s", s+1);
	n = strlen(s);
	s[n++] = ')';
	s[n] = 0;
	for (i = 0; i < n; i++)
		if (s[i] == 'C' ||  s[i] == 'O' || s[i] == 'H')
		{
			for (j = n-1; j > i; j--)
				s[j+2] = s[j];
			s[i+1] = s[i];
			s[i] = '(';
			s[i+2] = ')';
			n += 2;
			i += 2;
			s[n] = 0;
		}
	for (i = 0; i < n; i++)
		if (s[i] == ')')
			if (i < n-1 && (s[i+1] < '2' || s[i+1] > '9'))
			{
				for (j= n-1; j > i; j--)
					s[j+1] = s[j];
				s[i+1] = '1';
				n++;
				i++;
				s[n] = 0;
			}
	s[n++] = '1';
	s[n] = 0;
	l = 0;
//	cerr << s << '\n';
	for (i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			d[l] = -1;
			l++;
		}
		if (s[i] == ')')
			if (d[l-1] != -1)
	                        while (l > 1 && d[l-2] != -1)
				{
					d[l-2] += d[l-1];
					l--;
				}
		if (s[i] == 'C' || s[i] == 'O' || s[i] == 'H')
			if (d[l-1] == -1)
			{
				if (s[i] == 'C')
					d[l] = 12;
				if (s[i] == 'O')
					d[l] = 16;
				if (s[i] == 'H')
					d[l] = 1;
				l++;
			}
			else
			{
				if (s[i] == 'C')
					d[l-1] += 12;
				if (s[i] == 'O')
					d[l-1] += 16;
				if (s[i] == 'H')
					d[l-1] += 1;
			}
		if (s[i] >= '1' && s[i] <= '9')
		{
			d[l-1] *= (s[i]-'0');
			d[l-2] = d[l-1];
			l--;
		}

//		cerr << i << ": " << l << "   ";
//		for (j = 0; j < l; j++)
//			cerr << d[j] << ' ';
//		cerr << '\n';
	}
	printf("%d\n", d[0]);
	return 0;
}
