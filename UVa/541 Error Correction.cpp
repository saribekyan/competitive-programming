#include <iostream>
using namespace std;

int main()
{
	bool **S;
	int t, i, k, l1, l2, x, y, j, h;
	cin >> t;
	while (t)
	{
		S = new bool *[t];
		for (i = 0; i < t; i++)
			S[i] = new bool [t];
		for (i = 0; i < t; i++)
			for (j = 0; j < t; j++)
				cin >> S[i][j];
		l1 = 0;
		l2 = 0;
		for (i = 0; i < t; i++)
		{
			k = 0;
			h = 0;
			for (j = 0; j < t; j++)
			{
				if (S[i][j])
					k++;
				if (S[j][i])
					h++;
			}
			if (k % 2)
			{
				l1++;
				x = i;
			}
			if (h % 2)
			{
				l2++;
				y = i;
			}
		}
		x++;
		y++;
		if (l1 == 0 && l2 == 0)
			cout << "OK" << endl;
		else
			if (l1 == 1 && l2 == 1)
				cout << "Change bit (" << x << "," << y << ")" << endl;
			else
				cout << "Corrupt" << endl;
		cin >> t;
	}
	return 0;
}