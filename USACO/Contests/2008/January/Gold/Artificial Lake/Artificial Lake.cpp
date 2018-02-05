#include <fstream>
#include <algorithm>
using namespace std;
#define inf (123456789LL)

struct node
{
	int width;
	int height;
	int number;
	node *next;
	node *prev;
} *head, *curr, *p, *m;
long long ans[100010];
int main()
{
	ifstream fin("alake.in");
	ofstream fout("alake.out");
	int n, i;
	long long add;
	fin >> n;
	m = new node;
	head = new node;
	m->height = inf;
	head->prev = NULL;
	head->height = inf;
	head->number = -1;
	curr = head->next = new node;
	for (p = head, i = 0; i < n; i++, curr = curr->next, p = p->next)
	{
		fin >> curr->width >> curr->height;
		if (m->height > curr->height)
			m = curr;
		curr->number = i;
		curr->prev = p;
		curr->next = new node;
	}
	curr->height = inf;
	curr->prev = p;
	curr->next = NULL;
	curr->number = -1;
	add = 0;
	while (m->height < inf)
	{
		ans[m->number] = add+((long long)(m->width));
		if (m->prev->height == inf && m->next->height == inf)
			break;
		if (m->prev->height < m->next->height)
		{
			add += ((long long)(m->width))*((long long)(m->prev->height-m->height));
			m->prev->width += m->width;
			m->prev->next = m->next;
			m->next->prev = m->prev;
			curr = m;
			m = m->prev;
			delete curr;
			for (curr = m->prev; curr->height < inf; curr = curr->prev)
				if (curr->height > curr->next->height)
					break;
			m = curr->next;
		}
		else
		{
			add += ((long long)(m->width))*((long long)(m->next->height-m->height));
			m->next->width += m->width;
			m->prev->next = m->next;
			m->next->prev = m->prev;
			curr = m;
			m = m->next;
			delete curr;
			for (curr = m->next; curr->height < inf; curr = curr->next)
				if (curr->height > curr->prev->height)
					break;
			m = curr->prev;
		}
	}
	for (i = 0; i < n; i++)
		fout << ans[i] << '\n';
	return 0;
}
