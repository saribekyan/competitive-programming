/*
PROG: patheads
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#define MAX 1000000

int a[100010];
int d[MAX+10];
int t[MAX+10];
int main()
{
	freopen("patheads.in", "r", stdin);
	freopen("patheads.out", "w", stdout);
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", a+i);
		t[a[i]]++;
	}
	for (i = 0; i < n; i++)
		if (t[a[i]] != -1)
		{
			for (j = a[i]; j <= MAX; j+=a[i])
				d[j] += t[a[i]];
			t[a[i]] = -1;
		}
	for (i = 0; i < n; i++)
		printf("%d\n", d[a[i]]-1);
	return 0;
}
