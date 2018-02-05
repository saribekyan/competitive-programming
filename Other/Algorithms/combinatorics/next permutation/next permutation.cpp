#include <stdio.h>
#define MAX 100
int d[MAX];
void reverse(int f, int s)
{
	int i, t;
	for (i = f; i < (s+f)/2; i++){t=d[i];d[i]=d[s-i-1+f];d[s-i-1+f]=t;}
}
bool next_permutation(int n)
{
	int i, k, m, t;
	for (k=n-2; k>=0; k--)if (d[k]<d[k+1])break;
	if (k==-1&&d[0]>d[1])return 0;
	m = k+1;
	for (i = k+2; i < n; i++)if (d[m]>d[i]&&d[i]>d[k])m = i;
	t = d[k];
	d[k] = d[m];
	d[m] = t;
	reverse(k+1, n);
	return 1;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &d[i]);
	if (next_permutation(n))
	{
		for (i = 0; i < n; i++)printf("%d ", d[i]);
		putchar('\n');
	}
	else printf("0\n");
	return 0;
}