#include <iostream>
#include <iomanip>
using namespace std;
int d[26];
char c[26];

int main()
{
	int l, t, i, j, n;
	double s, s1, ans;
	cin >> t;
	for (l = 0; l < t; l++)
	{
		cin >> c;
		n = strlen(c);
		for (i = 0; i < 26; i++)d[i]=0;
		for (i = 0; i < n; i++)
			d[c[i]-'A']++;
		s = s1 = 1;
		for (i = 1; i <= n; i++)s*=i;
		for (i = 0; i < 26; i++)
			for (j = 1; j <= d[i]; j++)
				s1*=j;
		ans = s/s1;
		cout << setiosflags(ios::fixed) << setprecision(0);
		cout <<"Data set " << l+1 << ": "<<ans << '\n';
	}
	return 0;
}