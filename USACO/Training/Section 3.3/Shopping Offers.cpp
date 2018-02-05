/*
PROG: shopping
LANG: C++
ID: hayk.sa1
*/
#include<cstdio>

FILE* fin = fopen("shopping.in", "r");
FILE* fout = fopen("shopping.out", "w");
class citem
{
	public:
		int n, id[5], qu[5], pr; bool canuse;
		void input(void)
		{
			fscanf(fin, "%d", &n);
			for( int i=0; i<n; i++ )
				fscanf(fin, "%d%d", &id[i], &qu[i]);
			fscanf(fin, "%d", &pr);
			canuse = true;
		}
}
cheaplist[100];
class titem
{
	public:
		int id, qu, pr;
		void input(void)
		{
			fscanf(fin, "%d%d%d", &id, &qu, &pr);
		}
}
thinglist[5];

int min(int a, int b) { if( a<b ) return a; return b; }
int s, price[6][6][6][6][6];
int mincost(int w[])
{
	int *ptr, i, j, t[5];

	if( w[0]+w[1]+w[2]+w[3]+w[4]==0 ) return 0;
	ptr = &price[w[0]][w[1]][w[2]][w[3]][w[4]];
	if( *ptr != 0 ) return *ptr;
	for( i=0; i<5; i++ ) *ptr += thinglist[i].pr * w[i];

	for( i=0; i<s; i++ )
	{
		for( j=0; j<5; j++ ) t[j] = w[j];

		for( j=0; j<cheaplist[i].n; j++ )
		{
			t[cheaplist[i].id[j]] -= cheaplist[i].qu[j];
			if( t[cheaplist[i].id[j]] < 0 ) break;
		}

		if( j==cheaplist[i].n )
			*ptr = min(*ptr, mincost(t)+cheaplist[i].pr);
	}
	return *ptr;
}

void solve(void)
{
	int i, j, k, a[5];

	for( i=0; i<s; i++ )
	{
		for( j=0; j<cheaplist[i].n; j++ )
		{
			for( k=0; k<5; k++ )
				if( cheaplist[i].id[j]==thinglist[k].id )
				{ cheaplist[i].id[j] = k; break; }
			if( k==5 ) break;
		}
		if( j<cheaplist[i].n ) cheaplist[i].canuse = false;
	}
	for( i=0; i<5; i++ ) a[i] = thinglist[i].qu;
	fprintf(fout, "%d\n", mincost(a));
}

void input(void)
{
	int b, i;
	fscanf(fin, "%d", &s); for( i=0; i<s; i++ ) cheaplist[i].input();
	fscanf(fin, "%d", &b); for( i=5-b; i<5; i++ ) thinglist[i].input();
}

int main(void)
{
	input();
	solve();
	return 0;
}

