#include <stdio.h>
#include <string.h>
#define NMAX 160
char A[NMAX],B[NMAX], C[NMAX];
int k;

void rec(int a, int b, int p, int q)
{
	int i;
	for (i = a; i <= b; i++)
		if (A[i]==B[p])
		{
			C[k] = A[i];
			k--;
			rec(i+1, b, p+i-a+1, q);
			rec(a, i, p+1, p+i-a+1);
		}
}

int main()
{
	int t, l, i;
	scanf("%d", &t);
	for (l = 0; l < t; l++)
	{
		for (i = 0; i < NMAX; i++)
			A[i] = B[i] = C[i] = 0;
		scanf("%d%s%s", &k, B, A);
		k--;
		rec(0, k, 0, k);
		printf("%s\n", C);
	}
	return 0;
}