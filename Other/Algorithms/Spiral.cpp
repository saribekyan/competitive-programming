#include <iostream>
using namespace std;

int main()
{
	int n, i, k, j, x, l;
	int **a;
	while (cin >> n)
	{
		a = new int *[n];
		for (i = 0; i < n; i++)
			a[i] = new int [n];
		k = 1;
		x = 0;
		for (l = 0; l < (n + 1) / 2; l++)
		{
			for (i = x; i < n - x; i++)
			{
				a[x][i] = k;
				k++;
			}
			k--;
			for (i = x; i < n - x; i++)
			{
				a[i][n - x - 1] = k;
				k++;
			}
			k--;
			for (i = n - x - 1; i >= x; i--)
			{
				a[n - x - 1][i] = k;
				k++;
			}
			k--;
			for (i = n - x - 1; i > x; i--)
			{
				a[i][x] = k;
				k++;
			}
			x++;
		}
		for (i = 0; i < n; i++)
		{
			for (l = 0; l  < n; l++)
				cout << a[i][l] << " ";
			cout << endl;
		}
		delete a;
	}
	return 0;
}