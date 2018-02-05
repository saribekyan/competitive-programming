#include <stdio.h>
#include <string.h>

int a[55];
char s[3010], S[3000010];
int main()
{
	freopen("writing.in", "r", stdin);
	freopen("writing.out", "w", stdout);
	int n, m, p, i, j;
	scanf("%d%d%s%s", &n, &m, s, S);
	memset(a, 0, sizeof(a));
	for (i = 0; i < n; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			a[s[i]-'a']++;
		else
			a[s[i]-'A'+26]++;
		if (S[i] >= 'a' && S[i] <= 'z')
			a[S[i]-'a']--;
		else
			a[S[i]-'A'+26]--;
	}
	for (j = 0; j < 52 && a[j] == 0; j++);
	p = (int)(j == 52);
	for (i = n; i < m; i++)
	{
		if (S[i] >= 'a'  && S[i] <= 'z')
			a[S[i]-'a']--;
		else
			a[S[i]-'A'+26]--;
		if (S[i-n] >= 'a'  && S[i-n] <= 'z')
			a[S[i-n]-'a']++;
		else
			a[S[i-n]-'A'+26]++;
		for (j = 0; j < 52 && a[j] == 0; j++);
		p += (int)(j == 52);
	}
	printf("%d\n", p);
	return 0;
}
