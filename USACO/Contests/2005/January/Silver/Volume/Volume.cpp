#include <fstream>
#include <algorithm>
using namespace std;

long long c[10010];
long long d[10010];
int main()
{
	ifstream fin ("volume.in");
	ofstream fout("volume.out");
	int n, i;
	long long m;
	fin >> n;
	for (i = 0; i < n; i++)
		fin >> c[i];
	sort(c, c+n);
	d[0] = 0;
	for (i = 1; i < n; i++)
		d[i] = d[i-1]+((long long)(i))*(c[i]-c[i-1]);
	m = 0;
	for (i = 0; i < n; i++)
		m += d[i];
	fout << 2*m << '\n';
	return 0;
}
