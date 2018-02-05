/*
PROG: sec
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

struct node
{
	int val;
	int end, p;
	node *n[2];
} *head, *c;
int main()
{
	freopen("sec.in", "r", stdin);
	freopen("sec.out", "w", stdout);
	int ans;
	int n, m, p, t, i, j;
	scanf("%d%d", &n, &m);
	head = new node;
	head->val = 0;
	head->end = head->p = 0;
	head->n[0] = head->n[1] = NULL;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p);
		c = head;
		for (j = 0; j < p; j++)
		{
			scanf("%d", &t);
			if (c->n[t] == NULL)
				{
					c->n[t] = new node;
					c->n[t]->val = t;
					c->n[t]->n[0] = c->n[t]->n[1] = NULL;
					c->n[t]->p = 1;
					if (j+1 == p)
						c->n[t]->end = 1;
					else
						c->n[t]->end = 0;
				}
				else
				{
					c->n[t]->p++;
					if (j+1 == p)
						c->n[t]->end++;
				}
			c = c->n[t];
		}
	}
	for (i = 0; i < m; i++)
	{
		ans = 0;
		scanf("%d", &p);
		c = head;
		for (j = 0; j < p && c; j++)
		{
			scanf("%d", &t);
			if (j+1 != p && c->n[t] != NULL)
				ans += c->n[t]->end;
			if (j+1 == p && c->n[t] != NULL)
				ans += c->n[t]->p;
			c = c->n[t];
		}
		while (j < p)
		{
			scanf("%d", &t);
			j++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
