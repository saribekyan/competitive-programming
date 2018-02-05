#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

set<double> s;
pair<int,int> p[210];
double D(pair<int,int> a, pair<int,int> b)
{
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second)+0.0);
}
int main()
{
	freopen("lines.in", "r", stdin);
	freopen("lines.out", "w", stdout);
	int n, i, j;
	pair<int,int> a, b;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &p[i].first, &p[i].second);
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
		{
			a = min(p[i], p[j]);
			b = max(p[i], p[j]);
			s.insert(asin(1.0*(b.second-a.second)/D(a, b)));
		}
	printf("%d\n", s.size());
	return 0;
}
