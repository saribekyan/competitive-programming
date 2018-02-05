#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 100000;

struct cow{int a, b, i;}d[MAX];
bool operator < (cow a, cow b){return (a.a*b.b<a.b*b.a);}

FILE* fin = fopen("flowers.in", "r");
FILE* fout = fopen("flowers.out", "w");

int main()
{
	int n,i;
	double minut,ans;
	fscanf(fin,"%d",&n);
	for (i = 0; i < n; i++)
	{
		fscanf(fin,"%d%d", &d[i].a, &d[i].b);
		d[i].i = i+1;
	}
	sort(d,d+n);
	minut=2*d[0].a;
	ans = 0;
	for (i = 1; i < n; i++)
	{
		ans+=minut*d[i].b;
		minut=minut+2*d[i].a;
	}
	fprintf(fout,"%.0lf\n", ans);
	return 0;
}