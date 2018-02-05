// 10038 Jolly Jumpers
#include <iostream>
using namespace std;

int main()
{
	bool *flag;
//	int *s;
	bool t;
	int i, j, l, n, m;
	while (cin >> l)
	{
		flag = new bool [l - 1];
//		s = new int [l];
		for (i = 1; i < l; i++)
			flag[i] = false;
		
	//	for (i = 0; i < l; i++)
	//		cin >> s[i];
		cin >> n;
		for (i = 0; i < l - 1; i++)
		{
			cin >> m;
			if (abs(n - m) > 0 && abs(n - m) < l)
				if (flag[abs(n - m) - 1] == false)
					flag[abs(n - m) - 1] = true;
			n = m;
		}
		t = true;
		for (i = 0; i < l - 1; i++)
			if (!flag[i])
			{
				t = false;
				break;
			}
		if (t)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	return 0;
}