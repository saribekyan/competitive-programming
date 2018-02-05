/*
PROG: butter
LANG: C++
ID: hayk.sa1
*/
#include<cstdio>

const int inf = 999999999;

struct dist { int v, d; };

int n, p, cows[800], road[800][800], np[800][800], ns[800];
dist heap[801]; int htop; int p2h[800], a = inf; bool did[800];

void heapup(int p)
{
	dist temp = heap[p];

	while( temp.d < heap[p/2].d )
	{
		heap[p] = heap[p/2];
		p2h[heap[p].v] = p;
		p /= 2;
	}
	heap[p] = temp;
	p2h[temp.v] = p;
}

void heapdown(int p)
{
	dist temp = heap[p]; int k;

	while( p+p <= htop )
	{
		k = p+p;

		if( k<htop && heap[k].d > heap[k+1].d ) k++;

		heap[p] = heap[k]; p2h[heap[p].v] = p; p = k;
	}
	heap[p] = temp; p2h[temp.v] = p;
}

void dijkstra(int u)
{
	int at = 0, nc = n, i, j; dist temp;

	while( nc )
	{
		temp = heap[1]; heap[1] = heap[htop--]; heapdown(1);

		at += cows[temp.v] * temp.d;
		if( at >= a ) return;
		nc -= cows[temp.v];
		did[temp.v] = true;

		for( i=0; i<ns[temp.v]; i++ )
		{
			j = np[temp.v][i];

			if( !did[j] && (heap[p2h[j]].d > temp.d + road[temp.v][j]) )
			{
				heap[p2h[j]].d = temp.d + road[temp.v][j];
				heapup(p2h[j]);
			}
		}
	}
	a = at;
}

FILE* fin = fopen("butter.in", "r");
FILE* fout = fopen("butter.out", "w");
void solve(void)
{
	int i, j;

	heap[0].d = -1;
	for( i=0; i<p; i++ )
	{
		htop = 0;
		for( j=0; j<p; j++ )
		{
			htop++;
			heap[htop].v = j;
			heap[htop].d = road[i][j];
			p2h[j] = htop;
			heapup(htop);
			did[j] = false;
		}
		dijkstra(i);
	}
	fprintf(fout, "%d\n", a);
}

void input(void)
{
	int c, i, j, k;

	fscanf(fin, "%d%d%d", &n, &p, &c);

	for( i=0; i<n; i++ )
	{
		fscanf(fin, "%d", &j);
		cows[j-1]++;
	}

	for( i=0; i<p; i++ )
	{
		for( j=0; j<p; j++ )
			road[i][j] = inf;
		road[i][i] = 0;
	}

	while( c-- )
	{
		fscanf(fin, "%d%d%d", &i, &j, &k); i--; j--;

		road[i][j] = k; np[i][ns[i]++] = j;
		road[j][i] = k; np[j][ns[j]++] = i;
	}
}

int main(void)
{
	input(); solve();
	return 0;
}