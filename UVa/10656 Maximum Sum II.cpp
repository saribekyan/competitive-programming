#include <iostream>
using namespace std;

int main()
{
	int t, i;
	bool flag;
	int *s;
	cin >> t;
	while (t)
	{
		s = new int [t];
		flag = false;
		for (i = 0; i < t; i++)
		{
			cin >> s[i];
			if (s[i])
				flag = true;
		}
		if (flag)
		{
			for (i = 0; i < t; i++)
				if (s[i])
					cout << s[i] << " ";
		}
		else
			cout << 0;
		cout << endl;
		cin >> t;
	}
	return 0;
}