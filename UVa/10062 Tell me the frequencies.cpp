// 10062 Tell me the frequencies

#include <iostream>
using namespace std;

int main()
{
	char s[1010];
	int count[256];
	int i, m, k, j, n;
	while (cin.getline(s, 1010))
	{
		for (i = 0; i < 256; i++)
			count[i] = 0;
		for (i = 0; s[i]; i++)
			count[(int)s[i]]++;
		for (j = 0; j < 256; j++)
		{
			n = 2000;
			for (i = 0; i < 256; i++)
			{
				if (count[i] <= n && count[i] != 0)
				{
					n = count[i];
					k = i;
				}
			}			
			if (count[k] != 0)
				cout << k << " " << n <<endl;
			count[k] = 0;			
		}
		cout << endl;
	}
	return 0;
}