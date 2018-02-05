#include <stdio.h>
#include <algorithm>
using namespace std;

struct abc{int a, b;}d[50001];
bool operator < (abc a, abc b){return a.a<b.a;}
FILE* fin = fopen("lineup.in","r");
FILE* fout = fopen("lineup.out", "w");
int main()
{
	int n, q, i, j, max, min, a, b;
	fscanf(fin,"%d%d", &n, &q);
	for (i = 0; i < n; i++)
	{
		fscanf(fin,"%d",&d[i].a);
		d[i].b=i+1;
	}
	sort(d,d+n);
	for (i = 0; i < q; i++)
	{
		fscanf(fin,"%d%d",&a,&b);
		for (j = 0; j < n; j++)
			if (d[j].b>=a&&d[j].b<=b)
			{
				min = d[j].a;
				break;
			}
		for (j = n-1; j >= 0; j--)
			if (d[j].b<=b&&d[j].b>=a)
			{
				max = d[j].a;
				break;
			}
		fprintf(fout,"%d\n",max-min);
	}
	return 0;
}