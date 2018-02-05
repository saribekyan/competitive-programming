#include <iostream>
using namespace std;

void main()
{
	char str[1000];
	int i;
	while (cin >> str)
	{
		for (i = 0; i < strlen(str); i++)
			cout << (char)((int)str[i] - 7);
		cout << endl;
	}
}