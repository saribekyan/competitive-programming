#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MOD (1000000007LL)

typedef long long LL;
typedef vector<vector<LL> > VLL;
VLL d;
LL n;
VLL mul(VLL a, VLL b)
{
	VLL ret(n);
	LL i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			ret[i].push_back(0);
			for (k = 0; k < n; k++)
				ret[i][j] = (ret[i][j]+a[i][k]*b[k][j])%MOD;
		}
	return ret;
}
VLL pow(LL p)
{
	if (p == 1)
		return d;
	VLL r = pow(p>>1);
	if (p&1)
		return mul(mul(r, r), d);
	return mul(r, r);
}
int main()
{
	string s;
	LL m, p, q, i, j;
	cin >> n;
	d.resize(n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			d[i].push_back(0);
			cin >> d[i][j];
		}
	cin >> m;
	while (m--)
	{
		cin >> s;
		if (s == "T")
		{
			for (i = 0; i < n; i++)
				for (j = i+1; j < n; j++)
					swap(d[i][j], d[j][i]);
			continue;
		}
		if (s == "MUL")
		{
			cin >> p;
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					d[i][j] = (d[i][j]*p)%MOD;
			continue;
		}
		if (s == "POW")
		{
			cin >> p;
			d = pow(p);
			continue;
		}
		cin >> s >> p >> q;
		p--;
		q--;
		if (s == "ROW")
		{
			for (i = 0; i < n; i++)
				swap(d[p][i], d[q][i]);
			continue;
		}
		for (i = 0; i < n; i++)
			swap(d[i][p], d[i][q]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-1; j++)
			cout << d[i][j] << ' ';
		cout << d[i][j] << '\n';
	}
	return 0;
}
