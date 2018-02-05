#include <stdio.h>

int main()
{
	int t, n, m, p, q, a;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		p = q = 0;
		while (n--)
			scanf("%d", &a), p = a>p?a:p;
		while (m--)
			scanf("%d", &a), q = b>q?b:q;
		printf(p>=q?"Godzilla\n":"MechaGodzilla\n");
	}
	return 0;
}
