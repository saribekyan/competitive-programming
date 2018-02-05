#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
//	ifstream cin("input.txt");
	char c;
	bool flag;
	int i, j, t;
	double S[100][4];
	double x, y;
	cin >> c;
	j = 0;
//	S = new double *[11];
//	for (i = 0; i < 11; i++)
//		S[i] = new double [4];
	while (c != '*')
	{
		for (i = 0; i < 4; i++)
			cin >> S[j][i];
		j++;
		cin >> c;
	}
	cin >> x >> y;
	t = 1;
	while (x != 9999.9 || y != 9999.9)
	{
		flag = false;
		for (i = 0; i < j; i++)
			if (x > S[i][0] && x < S[i][2] && y < S[i][1] && y > S[i][3])
			{
				cout << "Point " << t << " is contained in figure " << i + 1 << endl;
				flag = true;
			}
		if (!flag)
			cout << "Point " << t << " is not contained in any figure" << endl;
		t++;
		cin >> x >> y;
	}
	return 0;
}