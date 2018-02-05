#include <stdio.h>
#include <string.h>

char s[200010];
int main()
{
	int n, p, i, j;
	scanf("%s", s);
	n = strlen(s);
	s[n] = 0;
	strcpy(s+n+1, s+1);
	s[n] = s[0];
	s[n<<1] = 0;
	p = 0;
	for (i = 1; i < n;)
	{
		for (j = 0; j < n && s[p+j] == s[i+j]; j++);
		if (s[p+j] > s[i+j])
		{
			p = i;
			if (j >= 2)
				i += (j>>1);
			else
				i++;
		}
		else
			i += j+1;
	}
	printf("%d\n", p);
	return 0;
}
