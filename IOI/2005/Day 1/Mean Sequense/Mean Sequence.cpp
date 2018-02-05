#include <stdio.h>
#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

int main()
{
	int n, p, q, s1, s2, a, i;
	scanf("%d", &n);
	s1 = 0;
	p = -2000000000;
	q = 2000000000;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		s2 = 2*a-s1;
		if (i%2)
			p = Max(p, (s1-s2)/2);
		else
			q = Min(q, (s2-s1)/2);
		s1 = s2;
	}
	if (q >= p)
		printf("%d\n", q-p+1);
	else
		printf("0\n");
	return 0;
}
