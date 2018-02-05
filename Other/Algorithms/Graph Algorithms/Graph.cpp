#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j, k, *g, a, b, max, t;
	while (cin >> n >> m)
	{
		g = new int [n];
		for (i = 0; i < n; i++)
			g[i] = i + 1;
		for (i = 0; i < m; i++)
		{
			cin >> a >> b;
			k = g[b - 1];
			g[b - 1] = g[a - 1];
			for (j = 0; j < n; j++)
				if (g[j] == k)
					g[j] = g[a - 1];
		}
		cout << endl;
		cin >> a >> b;
		cout << endl;
		if (g[a - 1] == g[b - 1])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cout << endl;
		max = 0;
		for (i = 1; i <= n; i++)
		{
			k = 0;
			for (j = 0; j < n; j++)
				if (g[j] == i)
					k++;
			if (k > max)
			{
				max = k;
				t = i;
			}
		}
		cout << max << endl;
		for (i = 0; i < n; i++)
			if (g[i] == t)
				cout << i + 1 << endl;
		cout << endl;
		if (max == n && m == n - 1)
			cout << "This is a tree" << endl;
		else
			cout << "This isn't a tree" << endl;
		cout << endl;
	}
	return 0;
}