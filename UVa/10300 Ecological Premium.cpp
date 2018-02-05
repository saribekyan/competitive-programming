#include <iostream>
using namespace std;

int main()
{
	int t, i, l, number_of_farmers, n, m, h, S;
	cin >> t;
	for (l = 0; l < t; l++)
	{
		S = 0;
		cin >> number_of_farmers;
		for (i = 0; i < number_of_farmers; i++)
		{
			cin >> n >> h >> m;
			S += n * m;
		}
		cout << S << endl;
	}
	return 0;
}