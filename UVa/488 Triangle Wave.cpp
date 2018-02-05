#include <iostream>
using namespace std;

int main()
{
	int t, n, m, i, l, j, k;
	cin >> t;
	for (l = 0; l < t; l++)
	{
		cin >> n >> m;
		for (i = 0; i < m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				for (k = 0; k < j; k++)
					cout << j;
				cout << endl;
			}
			for (j = n - 1; j >= 1; j--)
			{
				for (k = 0; k < j; k++)
					cout << j;
				cout << endl;
			}
			if (i != m-1)
				cout << endl;
		}
	}
	return 0;
}