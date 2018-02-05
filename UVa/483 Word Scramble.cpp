#include <iostream>
using namespace std;
#define MAX 100000

char s[MAX];

int main()
{
	int i, j;
	while (cin.getline(s, MAX))
	{
		i = 0;
		while (i < strlen(s))
		{
			while (s[i] != ' ' && i < strlen(s))
				i++;
			j = i-1;
			while (s[j] != ' ' && j >= 0)
				cout << s[j--];
			while (s[i] == ' ' && i < strlen(s))
			{
				cout << ' ';
				i++;
			}
		}
		cout << "\n";
	}
	return 0;
}