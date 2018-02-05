#include <iostream>
#include <string>
//#include <fstream>
using namespace std;

int main()
{
//	ifstream fin("input.txt");
	string s, t;
	int i, j, k, d;
	bool flag;
	while (cin >> s >> t)
	{
		flag = true;
		k = 0;
		j = 0;
		if (s.size() <= t.size())
			for (i = 0; i < s.size(); i++)
			{
				if (flag)
					while (t[j] != s[i] && j < t.size())
						j++;
				if (j == t.size())
				{
					flag = false;
					break;
				}
				j++;
			}
		else
			flag = false;
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}