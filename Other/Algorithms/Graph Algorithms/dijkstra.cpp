#include <stdio.h>
#define MAXN 100
#define inf 1000000001
#define Min(a, b) ((a)<(b)?(a):(b))

int d[MAXN+1]; // heravorutyun-neri massivy
int pr[MAXN+1]; // predecessor: verjum i-rd elem-y klini -2 ete hnaravor che hasnel,
			// -1 ete da henc skizbn e. Hakarak depqum klini ayn gagati hamary, vorov petq e gal, vorpeszi chanaparhy lini karchaguyn-y.
bool t[MAXN+1];
int g[MAXN+1][MAXN+1]; // mer graphy
int main()
{
	int n, m, p, q, w, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g[i][j] = inf; // skzbum datark graph e
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &p, &q, &w);
		g[p-1][q-1] = g[q-1][p-1] = Min(g[p-1][q-1], w); // masnavorapes es grel em erkkoghmani graphi hamar
	}
	scanf("%d", &p); // kardum enq skzbnakan gagaty
	for (i = 0; i < n; i++)
	{
		d[i] = inf;
		pr[i] = -2;
	}
	d[p-1] = 0;
	pr[p-1] = -1;
	while (1)
	{
		p = -1; // p-n verjum cuyc e talu minimal-y minchev hima gtacneric.
		for (i = 0; i < n; i++)
			if (!t[i] && (p == -1 || d[p] > d[i])) // pordzen update anel...
				p = i;
		if (p == -1)
			break;
		t[p] = 1; // es gagatic prcanq
		for (i = 0; i < n; i++)
			if (d[i] > d[p]+g[p][i])
			{
				d[i] = d[p]+g[p][i];
				pr[i] = p; // chmorananq predecessor-y update anel
			}
	}
	// hetaqrqir e chisht e ardyoq ashxatel mer cragiry...
	for (i = 0; i < n; i++)
		if (d[i] < inf)
			printf("%d ", d[i]);
		else
			printf("-1 ");
	putchar('\n');
	for (i = 0; i < n; i++)
		printf("%d ", pr[i]+1); // pordzir ogtagorcelov predecessor-y gtnel inch-vor karchaguyn chanaparh!!!
	putchar('\n');
	return 0;
}
/*
5 4
1 2 1
2 3 2
3 4 3
4 5 4
2

*/
// by Hayk Saribekyan
