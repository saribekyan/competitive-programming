#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string *s;
	int t, l, i, k, Count;
	cin >> t;
	s = new string [t];	
	for (l = 0; l < t; l++)
	{	
		getline(cin, s[l], '\n');		
		cin >> s[l];		
	}
	sort(s, s + t);
	Count = 1;
	for (i = 0; i < t - 1; i++)
		if (s[i] == s[i + 1])
			Count++;
		else
		{
			cout << s[i]<< " "<< Count<< endl;
			Count = 1;
		}
    cout << s[t - 1]<< " "<< Count<< endl;	
	return 0;
}