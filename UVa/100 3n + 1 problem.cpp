#include <iostream>
using namespace std;

int length(int a)
{
	int k;
	k = 0;
	if (a != 1)
	{
		while (a != 1)
		{
			if (a % 2)
				a = 3 * a + 1;
			else	
				a /= 2;
			k++;
		}
		k++;
		return k;
	}
	else
		return 3;
}

int main()
{
	int n, m, k, i, x, y;
	while (cin >> n >> m)
	{
		x = n;
		y = m;
        if (n > m)
		{
			k = n;
			n = m;
            m = k;
		}
		k = 0;
		for (i = n; i <= m; i++)
		{
			if (k < length(i))
				k = length(i);
		}
		cout << x << " " << y << " " << k << endl;
	}
	return 0;
}