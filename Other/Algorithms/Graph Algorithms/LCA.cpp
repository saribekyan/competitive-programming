#include <cstdio>
#include <algorithm>
using namespace std;

int l;
int E[20001];
int L[20001];
int H[10001];
int in[10001];
int deg[10001];
int *tree[10001];
int R[16][10001];
int P[16];
int HP[10001];
void rec(int p, int depth)
{
	int i;
	for (i = 0; i < deg[p]; i++)
	{
		E[l] = tree[p][i];
		H[l++] = depth;
		rec(tree[p][i], depth+1);
		E[l] = p;
		H[l++] = depth-1;
	}
}
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
int RMQ(int p, int q)
{
	int i;
	if (H[R[HP[q-p+1]][p]] < H[R[HP[q-p+1]][q-P[HP[q-p+1]]+1]])
		return R[HP[q-p+1]][p];
	return R[HP[q-p+1]][q-P[HP[q-p+1]]+1];
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, p, q, u, v, i, j;
	scanf("%d%d", &n, &q);
	for (i = 0; i < n-1; i++)
	{
		scanf("%d", in+i);
		deg[--in[i]]++;
	}
	for (i = 0; i < n; i++)
		tree[i] = new int[deg[i]];
	memset(deg, 0, sizeof(deg));
	for (i = 0; i < n-1; i++)
		tree[in[i]][deg[in[i]]++] = i+1;
	l = 1;
	E[0] = H[0] = 0;
	rec(0, 1);
	for (i = l-1; i >= 0; i--)
		L[E[i]] = i;
	build_RMQ(l);
	while (q)
	{
		scanf("%d%d", &u, &v);
		if (L[u-1] > L[v-1])
			swap(u, v);
		printf("%d\n", E[RMQ(L[u-1], L[v-1])]+1);
		q--;
	}
	for (i = 0; i < n; i++)
		if (deg[i])
			delete []tree[i];
	return 0;
}
/*
5 100
1
1
2
2

7 100
1
1
2
2
3
3

10 100
1
1
1
1
1
1
1
1
1

*/