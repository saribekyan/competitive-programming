#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool so[10], flag;
	int k, i;
	string s;
	cin >> k;
	while (k)
	{
		flag = false;
		for (i = 0; i < 10; i++)
			so[i] = true;		
		do
		{ 	
//			cin >> s >> s;		
			cin >> s >> s;
			if (s == "high")
				for (i = k - 1; i < 10; i++)
					so[i] = false;
			if (s == "low")
				for (i = 0; i < k; i++)
					so[i] = false;
			if (s != "on")
				cin >> k;
		}
		while (s != "on");
		if (so[k - 1])
			cout << "Stan may be honest" << endl;
		else
			cout << "Stan is dishonest" << endl;
		cin >> k;
	}
	return 0;
}