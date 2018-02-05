#include <iostream>
using namespace std;

int main()
{
	int S[1000];
	bool *flag;
	int i, j, k, t, l;
	j = 0;
	while (cin >> S[j++]);
	j--;
	flag = new bool [j];
	for (i = 0; i < j; i++)
		flag[i] = false;
	for (i = 0; i < j; i++)
	{
		t = 0;
		k = S[i];
		if (flag[i] == false)
		{
			for (l = i; l < j; l++)
				if (S[l] == k && flag[l] == false)
				{
					t++;
					flag[l] = true;
				}
				cout << k << " " << t << endl;
		}
	}
    return 0;
}