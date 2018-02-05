#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
//	ifstream fin("input.txt");
	char S[1000];
	int i;
	bool t;
	t = true;
	while (cin.getline(S, 1000))
	{		
		for (i = 0; i < strlen(S); i++)
			if (S[i] == '"')
				if (t)
				{
					cout << "``";
					t = false;
				}
				else
				{
					cout << "''";
					t = true;
				}
			else
				cout << S[i];
		cout << endl;
	}
	return 0;
}