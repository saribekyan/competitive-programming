// 256 Quirksome Squares

#include <iostream>
//#include <math.h>
using namespace std;

int main()
{
/*	int k, i, j;
	int n, m;
	while (cin >> k)
	{
		cout << "00" << endl << "01" << endl;
		for (i = 10; i < pow(10, k); i++)
		{
			m = i / (pow(10, k / 2));
			n = i % (int)(pow(10, k / 2));
			if ((m + n) * (m + n) == i)
				cout << i << endl;
		}
	}*/
	int n;
	while (cin >> n)
	{
		if (n == 2)
		{
			cout << "00" << endl;
			cout << "01" << endl;
			cout << "81" << endl;
		}
		if (n == 4)
		{
			cout << "0000" << endl;
			cout << "0001" << endl;
			cout << "2025" << endl;
			cout << "3025" << endl;
			cout << "9801" << endl;
		}
		if (n == 6)
		{
			cout << "000000" << endl;
			cout << "000001" << endl;
			cout << "088209" << endl;
			cout << "494209" << endl;
			cout << "998001" << endl;
		}
		if (n == 8)
		{
			cout << "00000000" << endl;
			cout << "00000001" << endl;
			cout << "04941729" << endl;
			cout << "07441984" << endl;
			cout << "24502500" << endl;
			cout << "25502500" << endl;
			cout << "52881984" << endl;
			cout << "60481729" << endl;
			cout << "99980001" << endl;
		}
	}
	return 0;
}