#include <iostream>
#include <string>
using namespace std;
#define MAX 100000

char tel[MAX];

int main()
{
	int i;
	while (cin.getline(tel, MAX))
	{
		for (i = 0; i < strlen(tel); i++)
		{
			if (tel[i] >= 'A' && tel[i] <= 'C')
				tel[i] = '2';			
			if (tel[i] >= 'D' && tel[i] <= 'F')
				tel[i] = '3';			
			if (tel[i] >= 'G' && tel[i] <= 'I')
				tel[i] = '4';			
			if (tel[i] >= 'J' && tel[i] <= 'L')
				tel[i] = '5';			
			if (tel[i] >= 'M' && tel[i] <= 'O')
				tel[i] = '6';			
			if (tel[i] >= 'P' && tel[i] <= 'S')
				tel[i] = '7';			
			if (tel[i] >= 'T' && tel[i] <= 'V')
				tel[i] = '8';
			if (tel[i] >= 'W' && tel[i] <= 'Z')
				tel[i] = '9';
			cout << tel[i];
		}
		for (i = 0; i < MAX; i++)
			tel[i] = '\0';
		cout << "\n";
	}
	return 0;
}