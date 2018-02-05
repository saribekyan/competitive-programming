#include <iostream>
using namespace std;

int main()
{
	int i, k, t;
	char S[1000];
	while (cin.getline(S, 1000))
	{
		k = 0;
		for (i = 0; i < strlen(S); i++)
		{
			t = i;
			while ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z') || (int)S[i] == 39)
				i++;
			if (t != i)
				k++;
		}
		cout << k << endl;
	}
	return 0;
}