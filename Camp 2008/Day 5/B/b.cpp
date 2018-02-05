#include <stdio.h>
#include <string.h>

char s[100010];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, i, j;
	_int64 m, k, l;
	scanf("%s", s);
	n = strlen(s);
	m = k = l = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n && s[j] == s[i]; j++);
		if (j-i > 1)
			m++;
		else
			if (i > 0 && i < n-1)
				if (s[i-1] == s[i+1])
					l++;
		i = j-1;
		k++;
	}
	printf("%I64d\n", k*(k-1)/2+m-l);
	return 0;
}

