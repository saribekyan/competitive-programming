#include <iostream>
//#include <fstream>
#include <math.h>
using namespace std;

int main()
{
//	ifstream cin("input.txt");
	int i, k, t;
	double S[12][4];
	double x, y;
	char s[11];
	bool flag;
	k = 0;
	cin >> s[k];
	while (s[k] != '*')
	{
		if (s[k] == 'r')
			for (i = 0; i < 4; i++)
				cin >> S[k][i];
		else
			for (i = 0; i < 3; i++)
				cin >> S[k][i];
		k++;
		cin >> s[k];
	}
	cin >> x >> y;
	t = 1;
	while (x != 9999.9 || y != 9999.9)
	{
		flag = false;
		for (i = 0; i < k; i++)
		{
			if (s[i] == 'r')
				if (x > S[i][0] && x < S[i][2] && y > S[i][3] && y < S[i][1])
				{
					cout << "Point " << t << " is contained in figure " << i + 1<< endl;
					flag = true;
				}
			if (s[i] == 'c')
				if (pow(x - S[i][0] , 2) + pow(y - S[i][1], 2) < pow(S[i][2], 2))
				{
					cout << "Point " << t << " is contained in figure " << i + 1 << endl;
					flag = true;
				}
		}
		if (!flag)
			cout << "Point " << t << " is not contained in any figure" << endl;
		t++;
		cin >> x >> y;
	}
}