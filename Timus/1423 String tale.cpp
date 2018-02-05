#include <stdio.h>
#include <string.h>

int t[750010];
char s[750010];
int main()
{
	int n, i, j;
	scanf("%d", &n);
	scanf("%s%s", s+1, s+n+2);
	s[0] = 0;
	s[n+1] = 1;
	memcpy(s+2*n+2, s+n+2, n*sizeof(char));
	t[0] = -1;
	for (i = 1; i <= 3*n+1; i++)
	{
		for (j = t[i-1]; j >= 0 && s[j+1] != s[i]; j = t[j]);
		t[i] = j+1;
		if (t[i] == n)
		{
			printf("%d\n", i-2*n-1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
