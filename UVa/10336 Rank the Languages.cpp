#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 100
int dx[4] = {-1,  0, 0, 1}, n;
int dy[4] = { 0, -1, 1, 0}, m;
struct lang{int a; char c;} ans[26];
char c[MAX][MAX], q;
void rec(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
		if (x+dx[i]>=0 && y+dy[i]>=0 && x+dx[i]<n && y+dy[i]<m)
			if (c[x+dx[i]][y+dy[i]]==q)
			{
				c[x+dx[i]][y+dy[i]]=c[x][y]='*';
				rec(x+dx[i], y+dy[i]);
			}
}
bool operator < (lang a, lang b){return (a.a>b.a)||(a.a==b.a)&&(a.c<b.c);}
int main()
{
	int t, l, i, j;
	scanf("%d", &t);
	for (l = 0; l < t; l++)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s", c[i]);
		for (i = 0; i < 26; i++)
			ans[i].a = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (c[i][j] != '*')
				{
					q = c[i][j];
					ans[q-'a'].a++;
					ans[q-'a'].c = q;
					rec(i, j);
				}
		sort(ans, ans+26);
		printf("World #%d\n", l+1);
		for (i = 0; i < 26; i++)
			if (ans[i].a)
				printf("%c: %d\n", ans[i].c, ans[i].a);
	}
	return 0;
}