#include <fstream>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

long long a[5010], d[5010];
int main()
{
	ifstream fin("skilift.in");
	ofstream fout("skilift.out");
	long long n, k, p, q, i, j;
	fin >> n >> k;
	for (i = 0; i < n; i++)
		fin >> a[i];
	d[0] = 0;
	for (i = 1; i < n; i++)
	{
		p = 1;
		q = a[i-1]-a[i];
		d[i] = d[i-1]+1;
		for (j = i-1; j >= 0 && i-j <= k; j--)
			if (q*(i-j) <= (a[j]-a[i])*p)
			{
				d[i] = Min(d[i], d[j]+1);
				p = i-j;
				q = a[j]-a[i];
			}
	}
	fout << d[n-1]+1 << '\n';
	return 0;
}
