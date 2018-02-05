// 10176 Ocean Deep! Make it shallow!!
#include <iostream>
using namespace std;
#define m 131071

int main()
{
	char c;
	int k;
	while (cin >> c)
	{
		k = 0;
		while (c != '#')
		{
			k = (2 * k + (c - '0')) % m;
			cin >> c;
		}
		if (k)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}