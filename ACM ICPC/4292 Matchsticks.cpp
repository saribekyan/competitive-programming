#include <iostream>
#include <string>
using namespace std;

string d[110][2];
int p[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string min(string a, string b)
{
	if (a.size() < b.size())
		return a;
	if (a.size() > b.size())
		return b;
	if (a < b)
		return a;
	return b;
}
string max(string a, string b)
{
	if (a.size() > b.size())
		return a;
	if (a.size() < b.size())
		return b;
	if (a > b)
		return a;
	return b;
}
int main()
{
	string s;
	int t, n, i;
	cin >> t;
	d[0][0] = d[0][1] = "";
	d[1][0] = d[1][1] = "";
	d[2][0] = d[2][1] = "1";
	d[3][0] = d[3][1] = "7";
	d[4][0] = "4";
	d[4][1] = "11";
	d[5][0] = "2";
	d[5][1] = "71";
	d[6][0] = "6";
	d[6][1] = "111";
	d[7][0] = "8";
	d[7][1] = "711";
	d[8][0] = "10";
	d[8][1] = "1111";
	d[9][0] = "7111";
	d[9][1] = "112";
	s.push_back('0');
	for (n = 8; n <= 100; n++)
	{
		d[n][0] = d[n][1] = "";
		for (i = 1; i <= n; i++)
			d[n][0] += "9";
		for (i = 1; i < 10; i++)
		{
			s[0] = i+'0';
			if (n >= p[i])
				if (d[n-p[i]][0] != "")
				{
					d[n][0] = min(d[n][0], min(d[n-p[i]][0]+s, s+d[n-p[i]][0]));
					d[n][1] = max(d[n][1], max(d[n-p[i]][1]+s, s+d[n-p[i]][1]));
				}
		}
		if (n >= p[0])
			if (d[n-p[0]][0] != "")
			{
				d[n][0] = min(d[n][0], d[n-p[0]][0]+"0");
				d[n][1] = max(d[n][1], d[n-p[0]][1]+"0");
			}
	}
	while (t--)
	{
		cin >> n;
		cout << d[n][0] << ' ' << d[n][1] << '\n';
	}
	return 0;
}
