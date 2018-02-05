#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))
#define Min(a, b) ((a)<(b)?(a):(b))

struct node
{
	int val, a, b, s, h;
	node *l, *r;
} *head = new node;
void clear(node *p)
{
	if (p == NULL)
		return;
	clear(p->l);
	clear(p->r);
	delete p;
	p = NULL;
}
void I(node *p, int s, int t, int h)
{
	if (p->a == s && p->b == t)
	{
		p->val = h;
		p->s = p->h = (p->b-p->a+1)*h;
		clear(p->l);
		clear(p->r);
		p->l = p->r = NULL;
		return;
	}
	if (p->l == NULL && p->val == h)
		return;
	if (p->l == NULL)
	{
		p->l = new node;
		p->r = new node;
		p->l->a = p->a;
		p->r->b = p->b;
		p->l->b = p->r->a = ((p->a+p->b)>>1);
		p->l->val = p->r->val = p->val;
		p->l->s = p->r->s = (p->s>>1);
		p->l->h = p->r->h = (p->h>>1);
		p->r->a++;
		p->l->l = p->l->r = p->r->l = p->r->r = NULL;
	}
	if (t <= p->l->b)
		I(p->l, s, t, h);
	else
		if (s >= p->r->a)
			I(p->r, s, t, h);
		else
		{
			I(p->l, s, p->l->b, h);
			I(p->r, p->r->a, t, h);
		}
	p->s = p->l->s+p->r->s;
	p->h = Max(p->l->h, p->l->s+p->r->h);
	if (p->l->l == NULL && p->r->l == NULL && p->l->val == p->r->val)
	{
		p->val = p->l->val;
		delete p->l;
		delete p->r;
		p->l = p->r = NULL;
	}
}
int Q(node *p, int h)
{
	if (p->h <= h)
		return p->b;
	if (p->l == NULL)
		return p->a+h/p->val-1;
	int lf, rg;
	lf = Q(p->l, h);
	if (lf == p->l->b)
	{
		rg = Q(p->r, h-p->l->s);
		if (rg == p->l->b)
			return lf;
		return rg;
	}
	return lf;
}
int main()
{
	char ch;
	int n, a, b, h, t;
	scanf("%d", &n);
	t = 0;
	a = n-1;
	while (a)
	{
		t++;
		a >>= 1;
	}
	head->a = 1;
	head->b = (1<<t);
	head->l = head->r = NULL;
	head->val = head->s = head->h = 0;
	while (scanf("\n%c", &ch) && ch != 'E')
		if (ch == 'I')
		{
			scanf("%d%d%d", &a, &b, &h);
			I(head, a, b, h);
		}
		else
		{
			scanf("%d", &h);
			printf("%d\n", Min(n, Q(head, h)));
		}
	return 0;
}
