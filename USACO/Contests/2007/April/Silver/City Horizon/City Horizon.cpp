#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

struct point
{
	int coord, h;
	bool open;
} p[80010];
multiset<int, greater<int> > s;
bool operator <(point a, point b)
{
	if (a.coord == b.coord && a.open == b.open)
		return 0;
	return a.coord < b.coord || (a.coord == b.coord && !a.open);
}
int main()
{
	ifstream fin("horizon.in");
	ofstream fout("horizon.out");
	int n, i;
	long long m;
	multiset<int, greater<int> >::iterator I;
	fin >> n;
	for (i = 0; i < 2*n; i+=2)
	{
		fin >> p[i].coord >> p[i+1].coord >> p[i].h;
		p[i+1].h = p[i].h;
		p[i].open = 1;
		p[i+1].open = 0;
	}
	m = 0;
	sort(p, p+2*n);
	s.insert(p[0].h);
	for (i = 1; i < 2*n; i++)
	{
		if (s.size())
			m += ((long long)(*s.begin()))*((long long)(p[i].coord-p[i-1].coord));
		if (p[i].open)
			s.insert(p[i].h);
		else
		{
			I = s.find(p[i].h);
			if (I != s.end())
				s.erase(s.find(p[i].h));
		}
	}
	fout << m << '\n';
	return 0;
}
