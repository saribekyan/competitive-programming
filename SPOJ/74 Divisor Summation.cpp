#include <stdio.h>
#define N 500000

int s[N+1];
int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	s[1] = 0;
	for (i = 2; i <= N; i++)
		s[i] = 1;
	for (i = 2; i <= N; i++)
		for (j = 2*i; j <= N; j+=i)
			s[j] += i;
	while (t)
	{
		scanf("%d", &n);
		printf("%d\n", s[n]);
		t--;
	}
	return 0;
}
