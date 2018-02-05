#include <iostream>
using namespace std;

void main()
{
	int a, b, i, j, S, T;
	cin >> T;
	for (j = 1; j <= T; j++)
	{
		S = 0;
		cin >> a >> b; 
		if (a % 2 == 0)
			a++;
		if (b % 2 == 0)
			b--;
		S = ((a + b) * ((b - a + 1) / 2 + 1)) / 2;
		cout << "Case " << j << ": " << S << endl;
	}
}
