#include <stdio.h>
#include <string.h>
//#include <iostream>
//using namespace std;

int n;
int p[100];
bool t[100];
char s[100], a[100];
int c[100][100], len[100], l;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, w, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", p+i);
		p[i]--;
	}
	getchar();
	for (i = 0; i < n; i++)
		s[i] = getchar();
	s[n] = 0;
	l = 0;
	memset(t, 0, sizeof(t));
	for (i = 0; i < n; i++)
		if (!t[i])
		{
			t[i] = 1;
			len[l] = 1;
			c[l][0] = i;
			for (j = p[i]; j != i; j=p[j])
			{
				t[j] = 1;
				c[l][len[l]++] = j;
			}
			l++;
		}
//////////////////////////////
/*	for (i = 0; i < l; i++)
	{
		cerr << i << ": " << len[i] << "  ";
		for (j = 0; j < len[i]; j++)
			cerr << c[i][j] << ' ';
		cerr << '\n';
	}*/
//////////////////////////////
	memset(a, 0, sizeof(a));
	for (i = 0; i < l; i++)
	{
		w = m%len[i];
		for (j = 0; j < len[i]; j++)
			a[c[i][j]] = s[c[i][(j-w+len[i])%len[i]]];
	}
	printf("%s\n", a);
	return 0;
}

