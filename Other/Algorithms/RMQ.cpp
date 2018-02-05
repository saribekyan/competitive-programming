#include <cstdio>
#include <algorithm>
using namespace std;

int P[16];
int HP[10001];
int H[10001];
int R[16][10001];
int build_RMQ(int n)
{
	int logn, m, i, j;
	P[0] = 1;
	for (i = 1; i < 16; i++)
		P[i] = P[i-1]<<1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 16 && P[j] <= i; j++);
		HP[i] = j-1;
	}
	m = n;
	logn = 0;
	while (m)
	{
		logn++;
		m >>= 1;
	}
	for (i = 0; i < n; i++)
		R[0][i] = i;
	for (j = 1; j <= logn; j++)
		for (i = 0; i < n; i++)
			if (H[R[j-1][i]] < H[R[j-1][i+P[j-1]]])
				R[j][i] = R[j-1][i];
			else
				R[j][i] = R[j-1][i+P[j-1]];
}
int RMQ(int p, int q, int n)
{
	int i;
	return min(H[R[HP[q-p+1]][p]], H[R[HP[q-p+1]][q-P[HP[q-p+1]]+1]]);
}
int main()
{
/*	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", H+i);
	build_RMQ(n);
	while (m)
	{
		scanf("%d%d", &i, &j);
		printf("%d\n", RMQ(i-1, j-1, n));
		m--;
	}
	return 0;
}
/*
5 10
1651 121 49844 123 84

*/