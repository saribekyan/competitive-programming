#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	int s[52];
	char S[1000];
	int i, k, j;
	while (fin.getline(S, 1000))
	{
		for (i = 0; i < 52; i++)
			s[i] = 0;
		for (i = 0; i < strlen(S); i++)
		{
			if (S[i] >= 'A' && S[i] <= 'Z')
				s[S[i] - 'A']++;
			if (S[i] >= 'a' && S[i] <= 'z')
				s[S[i] - 'a' + 26]++;
		}
        k = *max_element(s, s + 52);			
		for (i = 0; i < 52; i++)
			if (s[i] == k)
			{
				if (i >= 0 && i < 26)
					cout << (char)(i + 'A');
				if (i >= 26 && i < 52)
					cout << (char)(i + 'a' - 26);
			}
		cout << " "<< k<< endl;
	}
	return 0;
}