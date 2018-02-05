#include <stdio.h>
#include <string.h>
#define P 1993

char a[30010];
int s[30010], t[30010];
int main()
{
	int n, m, mk, k, p, i;
	scanf("%d%s", &m, a);
	k = m/2;
	s[0] = 0;
	n = strlen(a);
	if (m == 1)
	{
		printf("%d\n", n);
		return 0;
	}
	for (mk = i = 1; i < k; i++)
		mk *= P;
	for (i = 0; i < k; i++)
		s[0] = s[0]*P+(int)(a[i]);
	for (i = 1; i+k <= n; i++)
		s[i] = (s[i-1]-((int)(a[i-1]))*mk)*P+(int)(a[i+k-1]);
	t[n-1] = 0;
	for (i = n-1; i+k >= n; i--)
		t[n-1] = t[n-1]*P+(int)(a[i]);
	for (i = n-2; i+1 >= k; i--)
		t[i] = (t[i+1]-((int)(a[i+1]))*mk)*P+a[i-k+1];
	p = 0;
	for (i = 0; i+m <= n; i++)
		p += (int)(s[i] == t[i+m-1]);
	printf("%d\n", p);
	return 0;
}
