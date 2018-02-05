#include <iostream>
#include <string>
using namespace std;

string d[510];
string sum(string a, string b)
{
	string c;
	int n, s, k, i;
	while (a.size() < b.size())
		a.insert(a.begin(), '0');
	while (b.size() < a.size())
		b.insert(b.begin(), '0');
	k = 0;
	n = a.size();
	for (i = n-1; i >= 0; i--)
	{
		s = (a[i]-'0')+(b[i]-'0');
		c.insert(c.begin(), ((s+k)%10)+'0');
		k = (s+k)/10;
	}
	if (k)
		c.insert(c.begin(), '1');
	return c;
}
int main()
{
	int i, j;
	string a, b;
	d[0] = d[1] = "1";
	for (i = 2; i <= 509; i++)
		d[i] = sum(d[i-1], d[i-2]);
	while (cin >> a >> b && b != "0")
	{
		while (a[0] == '0')
			a.erase(a.begin());
		while (b[0] == '0')
			b.erase(b.begin());
		for (i = 1; d[i].size() < a.size() || d[i].size() == a.size() && d[i] < a; i++);
		for (j = 509; d[j].size() > b.size() || d[j].size() == b.size() && d[j] > b; j--);
		cout << j-i+1 << '\n';
	}
	return 0;
}
