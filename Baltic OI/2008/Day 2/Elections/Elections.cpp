#include <stdio.h>
#define MAXE 100000

short d[15200000];
int a[310], pos[310];
void print(int p, short n)
{
	if (p == 0)
	{
		printf("%d\n", n);
		return;
	}
	print(p-a[d[p]], n+1);
	printf("%d ", pos[d[p]]+1);
}
int main()
{
	short n, i;
	int s = 0, j;
	scanf("%hd", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", a+i);
		s += a[i];
		pos[i] = i;
	}
	s = (s>>1)+1;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
			if (a[i] < a[j])
			{
				a[i] ^= a[j];
				a[j] ^= a[i];
				a[i] ^= a[j];
				pos[i] ^= pos[j];
				pos[j] ^= pos[i];
				pos[i] ^= pos[j];
			}
	d[0] = -1;
	for (j = 1; j <= s+MAXE; j++)
		d[j] = n;
	for (i = 0; i < n; i++)
		for (j = s-1; j >= 0; j--)
			if (d[j] < n && d[j+a[i]] > i)
				d[j+a[i]] = i;
	for (j = s+MAXE; j >= s && d[j] == n; j--);
	print(j, 0);
	putchar('\n');
	return 0;
}
