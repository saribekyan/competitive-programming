#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	int t, i, l;
	cin >> t;
	getline(cin, S);
	for (l = 0; l < t; l++)
	{
		getline(cin, S);
		if (S == "1" || S == "4" || S == "78")
			cout << "+" << endl;
		else
			if ((*(S.end() - 1)) == '5' && (*(S.end() - 2)) == '3')
				cout << "-" << endl;
			else
				if (S[0] == '9' && *(S.end() - 1) == '4')
					cout << "*" << endl;
				else
					cout << "?" << endl;
	}
	return 0;
}