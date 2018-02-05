#include <stdio.h>
void hanoi(int l, int m, int r, int n)
{
	if (n==1){printf("%d->%d\n", l, r);return;}
	hanoi(l, r, m, n-1);
	printf("%d->%d\n", l, r);
	hanoi(m, l, r, n-1);
}
int main()
{
	int n;
	scanf("%d", &n);
	hanoi(1, 2, 3, n);
	return 0;
}