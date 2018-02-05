#include <iostream>
//#include <fstream>
#include <math.h>
using namespace std;
#define eps 0.0000001

double s (double x1, double y1, double x2, double y2, double x3, double y3)
{
	return fabs((x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3)/2);
}

bool is_in(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double s1, s2, s3, s4;
	s1 = s(x1, y1, x2, y2, x4, y4);
	s2 = s(x2, y2, x3, y3, x4, y4);
	s3 = s(x1, y1, x3, y3, x4, y4);
	s4 = s(x1, y1, x2, y2, x3, y3);
	return fabs(s4-(s1 + s2 + s3)) < eps;
}

int main()
{
//	ifstream cin("input.txt");
	int i, k, t;
	double S[12][6];
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
			if (s[k] == 'c')
				for (i = 0; i < 3; i++)
					cin >> S[k][i];
			else
				for (i = 0; i < 6; i++)
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
					cout << "Point " << t << " is contained in figure " << i + 1<< "\n";
					flag = true;
				}
			if (s[i] == 'c')
				if (pow(x - S[i][0] , 2) + pow(y - S[i][1], 2) < pow(S[i][2], 2))
				{
					cout << "Point " << t << " is contained in figure " << i + 1 << "\n";
					flag = true;
				}
			if (s[i] == 't')
				if (is_in(S[i][0], S[i][1], S[i][2], S[i][3], S[i][4], S[i][5], x, y))
				{
					cout << "Point " << t << " is contained in figure " << i + 1 << "\n";
					flag = true;
				}
		}
		if (!flag)
			cout << "Point " << t << " is not contained in any figure" << endl;
		t++;
		cin >> x >> y;
	}
}