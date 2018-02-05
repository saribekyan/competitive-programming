#include <stdio.h>

int p[110], a[110];
char f[110], s[110];
int main()
{
	bool army;
	int n, m, w, x, y, z, l, k, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d", p+i);
	army = 1;
	for (l = 0; l < n; l++)
	{
		getchar();
		gets(f);
		scanf("%d", &k);
		for (i = 0; i < k; i++)
		{
			scanf("%d", a+i);
			a[i]--;
		}
		w = 0;
		for (i = 0; i < k; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			if (p[a[i]] < x)
				w += 2;
			if (p[a[i]]>= x && p[a[i]] < y)
				w += 3;
			if (p[a[i]] >= y && p[a[i]] < z)
				w += 4;
			if (p[a[i]] >= z)
				w += 5;
		}
		scanf("%d", &k);
		for (i = 0; i < k; i++)
		{
			getchar();
			gets(s);
			scanf("%d", &x);
			if (x <= w)
			{
				printf("%s %s\n", f, s);
				army = 0;
			}
		}
	}
	if (army)
		printf("Army\n");
	return 0;
}
