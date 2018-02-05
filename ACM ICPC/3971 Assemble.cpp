#include <cstdio>
#include <algorithm>
using namespace std;

bool t[1010];
struct pq
{
	int price;
	int quality;
} d[1010][1010], w[1010];
int deg[1010];
char a[1010][25], b[1010][25];
int main()
{
	int T, B, money, p, n, m, q, l, i, j, k;
	scanf("%d", &T);
	while (T)
	{
		scanf("%d%d", &n, &B);
		memset(t, 0, sizeof(t));
		for (i = 0; i < n; i++)
			scanf("%s%s%d%d", a[i], b[i], &w[i].price, &w[i].quality);
		p = 0;
		for (i = 0; i < n; i++)
			if (!t[i])
			{
				deg[p] = 1;
				d[p][0] = w[i];
				for (j = i+1; j < n; j++)
					if (strcmp(a[i], a[j]) == 0)
					{
						t[j] = 1;
						d[p][deg[p]++] = w[j];
					}
				p++;
			}
		q = -1;
		for (i = 0; i < p; i++)
			for (j = 0; j < deg[i]; j++)
			{
				money = B;
				for (k = 0; k < p; k++)
				{
					m = 10000000;
					for (l = 0; l < deg[k]; l++)
						if (d[k][l].price <= m && d[k][l].quality >= d[i][j].quality)
							m = d[k][l].price;
					if (m == 10000000)
					{
						money = -1;
						break;
					}
					money -= m;
				}
				if (money >= 0 && q < d[i][j].quality)
					q = d[i][j].quality;
			}
		printf("%d\n", q);
		T--;
	}
	return 0;
}
