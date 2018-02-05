#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000

int d[MAX+1][MAX+1];
char a[MAX], b[MAX];

int main()
{
	int i, j, n, m;
	while (cin.getline(a, 1001) && cin.getline(b, 1001))
	{
		n = strlen(a);
		m = strlen(b);
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++)
				d[i][j] = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (a[i-1]==b[j-1])
					d[i][j] = d[i-1][j-1]+1;
				else
				{
					if (d[i-1][j]>d[i][j-1])
						d[i][j] = d[i-1][j];
					else
						d[i][j] = d[i][j-1];
				}
		cout << d[n][m] << '\n';
	}
	return 0;
}