/*
PROG: msquare
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

bool t[40320];
struct square{char d[9], s[1000]; int length;};
queue<square> Q;
int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040};
int number(char *d)
{
	int n, i, j, k;
	n = 0;
	for (i = 0; i < 8; i++)
	{
		k = 0;
		for (j = i; j < 8; j++)
			if (d[j] < d[i])
				k++;
		n += fact[7-i]*k;
	}
	return n;
}
FILE* fin = fopen("msquare.in", "r");
FILE* fout = fopen("msquare.out", "w");
int main()
{
	bool c;
	char a, b;
	int p, q, l, i;
	square d, g, w;
	for (i = 0; i < 8; i++)
		fscanf(fin, "%c ", &d.d[i]);
	p = number(d.d);
	for (i = 0; i < 8; i++)
		d.d[i] = i+1+'0';
	d.d[8] = 0;
	for (i = 0; i < 1000; i++)
		d.s[i] = 0;
	d.length = 0;
	Q.push(d);
	t[0] = 1;
	for (i = 1; i < 40320; i++)
		t[i] = 0;
	while (1)
	{
		g = Q.front();
		if (number(g.d) == p)break;
		Q.pop();
//		A
		w = g;
		reverse(w.d, w.d+8);
		q = number(w.d);
		c = 0;
		if (!t[q])
		{
			w.s[w.length] = 'A';
			w.length++;
			Q.push(w);
			t[q] = 1;
		}
//		B
		w = g;
		a = w.d[3];
		b = w.d[4];
		for (i = 2; i >= 0; i--)
		{
			w.d[i+1] = w.d[i];
			w.d[6-i] = w.d[7-i];
		}
		w.d[0] = a;
		w.d[7] = b;
		q = number(w.d);
		if (!t[q])
		{
			w.s[w.length] = 'B';
			w.length++;
			Q.push(w);
			t[q] = 1;
		}
//		C
		w = g;
		a = w.d[6];
		w.d[6] = w.d[5];
		w.d[5] = w.d[2];
		w.d[2] = w.d[1];
		w.d[1] = a;
		q = number(w.d);
		if (!t[q])
		{
			w.s[w.length] = 'C';
			w.length++;
			Q.push(w);
			t[q] = 1;
		}
	}
	if (g.length > 0)
	{
		fprintf(fout, "%d\n", g.length);
		for (i = 0; i < g.length; i++)
		{
			fputc(g.s[i], fout);
			if ((i+1)%60 == 0)
				fputc('\n', fout);
		}
		if ((i+1)%60)
			fputc('\n', fout);
	}
	else
		fprintf(fout, "0\n\n");
	return 0;
}