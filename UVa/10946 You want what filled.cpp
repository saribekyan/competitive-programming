#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 50

char c[MAX+2][MAX+2], q;
struct coord{int x, y;} p;
struct L{int a; char c;} ans[MAX*MAX];
stack<coord> st;
bool operator <(L a, L b){return (a.a>b.a)||(a.a==b.a)&&(a.c<b.c);}
int main()
{
	int n, m, i, j, x, y, k, l=1;
	while (cin >> n >> m &&(n||m))
	{
		for (i = 0; i <= n+1; i++)
			for (j = 0; j <= m+1; j++)
				c[i][j] = '.';
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				cin >> c[i][j];
		for (i = 0; i < MAX*MAX; i++)
			ans[i].a = 0;
		k = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				q = c[i][j];
				if (q!='.')
				{
					ans[k].c = q;
					ans[k].a++;
					c[i][j] = '.';
					p.x = i;
					p.y = j;
					st.push(p);
					x = st.top().x;
					y = st.top().y;
					while (1)
					{
						if (c[x-1][y]==q)
						{
							p.x=x-1;
							p.y=y;
							c[x-1][y] = '.';
							st.push(p);
							ans[k].a++;
						}
						else
						if (c[x][y-1]==q)
						{
							p.x=x;
							p.y=y-1;
							c[x][y-1] = '.';
							st.push(p);
							ans[k].a++;
						}
						else
						if (c[x][y+1]==q)
						{
							p.x=x;
							p.y=y+1;
							c[x][y+1] = '.';
							st.push(p);
							ans[k].a++;
						}
						else
						if (c[x+1][y]==q)
						{
							p.x=x+1;
							p.y=y;
							c[x+1][y] = '.';
							st.push(p);
							ans[k].a++;
						}
						else
							st.pop();
						if (st.empty())
							break;
						else
						{
							x = st.top().x;
							y = st.top().y;
						}
					}
					k++;
				}
			}
			sort(ans, ans+k);
			cout << "Problem " << l << ":\n";
			for (i = 0; i < k; i++)
				cout << ans[i].c << ' ' << ans[i].a << '\n';
			l++;
	}
	return 0;
}