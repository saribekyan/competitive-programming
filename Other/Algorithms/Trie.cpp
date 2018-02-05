#include <stdio.h>
#include <string.h>

char d[1000][50], s[50];
int tree[50000][26];
bool end[50000][26];
int len[1000];
int main()
{
	int n, m, p, nodes, l, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", d[i]);
	memset(tree, -1, sizeof(tree));
	memset(end, 0, sizeof(end));
	nodes = 1;
	for (i = 0; i < n; i++)
	{
		len[i] = strlen(d[i]);
		p = 0;
		for (j = 0; j < len[i]; j++)
			if (tree[p][d[i][j]-'a'] == -1)
			{
				tree[p][d[i][j]-'a'] = nodes;
				p = nodes++;
			}
			else
				p = tree[p][d[i][j]-'a'];
		end[p][d[i][len[i]-1]] = 1;
	}
	while (m)
	{
		scanf("%s", s);
		l = strlen(s);
		p = 0;
		for (i = 0; i < l; i++)
			if (tree[p][s[i]-'a'] == -1)
			{
				printf("NO\n");
				goto there;
			}
			else
				p = tree[p][s[i]-'a'];
		if (end[p][s[l-1]])
			printf("YES\n");
		else
			printf("NO\n");
there:;
		m--;
	}
	return 0;
}
