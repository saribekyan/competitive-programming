#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX 30
int box[MAX][10], D[MAX][MAX], p[MAX][MAX], ans[MAX], l;
void choose_path(int i, int j)
{
	if (i!=j)
		choose_path(i,p[i][j]);
	ans[l--]=j+1;;
}
int main()
{
	int n, d, i, j, k, c, m, u, v;
	while (scanf("%d%d", &n, &d)==2)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < d; j++)
				scanf("%d", &box[i][j]);
			sort(box[i], box[i]+d);
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (i!=j)
				{
					c = 0;
					for (k = 0; k < d; k++)
						if (box[i][k]<=box[j][k])
						{
							c = 1;
							break;
						}
					if (c)D[i][j]=INT_MIN/2;
					else D[i][j]=1;
				}
				p[i][j] = i;
			}
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (D[i][j]<D[i][k]+D[k][j])
					{
						D[i][j] = D[i][k]+D[k][j];
						p[i][j] = p[k][j];
					}
		m = INT_MIN;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (m<D[i][j])
				{
					m = D[i][j];
					u = i;
					v = j;
				}
		l = m;
		choose_path(u, v);
		printf("%d\n", m+1);
		for (i = 0; i < m; i++)printf("%d ", ans[i]);
		printf("%d\n", ans[m]);
	}
	return 0;
}