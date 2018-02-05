#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
//	ifstream fin("input.txt");
	char S[200];
	int i, c, j, n;
	while (/*f*/cin.getline(S, 200))
	{
		n = strlen(S);
		if (n > 1)
		{
			i = 0;
			while (i < n)
			{
				while (S[i] == '!')
				{
					cout << endl;
					i++;
				}
				c = 0;
				while (S[i] >= '1' && S[i] <= '9')
				{
					c += S[i] - '0';
					i++;
				}
				if (S[i] == 'b')
					for (j = 0; j < c; j++)
						cout << " ";
				else
					for (j = 0; j < c; j++)
						cout << S[i];
				i++;
			}
		}
		cout << endl;
	}
	return 0;
}