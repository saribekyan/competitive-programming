#include <iostream>
using namespace std;

int main()
{
	char S[1000];
	int s[26];
	int i, t, l, j, pos, k;
	cin >> t;
	cin.getline(S, 1000);
	for (l = 0; l < t; l++)
	{
		cin.getline(S, 1000);
		for (i = 0; i < strlen(S); i++)
		{
			if (S[i] >= 'A' && S[i] <= 'Z')
				s[S[i] - 'A']++;
			if (S[i] >= 'a' && S[i] <= 'z')
				s[S[i] - 'a']++;
		}
	}
	for (j = 0; j < 26; j++)
	{
		k = 0;
		for (i = 0; i < 26; i++)
			if (s[i] > k)
				{
					k = s[i];
					pos	= i;
				}
		if (s[pos] != 0)
			cout << (char)(pos + 'A') << " " << s[pos] << endl;
		s[pos] = 0;
	}
	return 0;
}