#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a)>(b)?(a):(b))

char s[30];
int n, l, m;
char a[1000010];
struct node
{
	int d;
	char ch;
	bool end;
	node *next[26];
} *head;
void add(node *p, int k)
{
	if (s[k] == 0)
	{
		p->end = 1;
		return;
	}
	if (p->next[s[k]-'a'] == NULL)
	{
		int i;
		p->next[s[k]-'a'] = new node;
		p->next[s[k]-'a']->ch = s[k];
		p->next[s[k]-'a']->d = 0;
		p->next[s[k]-'a']->end = 0;
		for (i = 0; i < 26; i++)
			p->next[s[k]-'a']->next[i] = NULL;
	}
	add(p->next[s[k]-'a'], k+1);
	p->d = Max(p->d, l-k);
}
void go(node *p)
{
	if (p->ch != '#')
		a[l++] = p->ch;
	if (p->end)
	{
		a[l++] = 'P';
		m++;
	}
	int k=-1, i;
	for (i = 0; i < 26; i++)
		if (p->next[i] != NULL && (k == -1 || p->next[i]->d > p->next[k]->d))
			k = i;
	if (k == -1)
	{
		if (m < n)
			a[l++] = '-';
		return;
	}
	for (i = 0; i < 26; i++)
		if (i != k && p->next[i] != NULL)
			go(p->next[i]);
	go(p->next[k]);
	if (m < n)
		a[l++] = '-';
}
int main()
{
	int i;
	scanf("%d", &n);
	s[0] = '#';
	head = new node;
	head->d = 0;
	head->ch = s[0];
	for (i = 0; i < 26; i++)
		head->next[i] = NULL;
	head->end = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s", s+1);
		l = strlen(s);
		add(head, 1);
	}
	l = m = 0;
	go(head);
	printf("%d\n", l);
	for (i = 0; i < l; i++)
		printf("%c\n", a[i]);
	return 0;
}
