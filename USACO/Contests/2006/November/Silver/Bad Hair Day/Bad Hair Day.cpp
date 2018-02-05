#include <stdio.h>

int n;
_int64 see[80005];
int cows[80005];
void read()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", cows+i);
}
_int64 solve()
{
	int i, j;
	_int64 s;
	for (i = n-2; i >= 0; i--)
	{
		j = i+1;
		while (j < n && cows[i] > cows[j])
		{
			see[i] += see[j]+1;
			j += see[j]+1;
		}
	}
	for (s = i = 0; i < n; i++)
		s += see[i];
	return s;
}
int main()
{
	freopen("badhair.in", "r", stdin);
	freopen("badhair.out", "w", stdout);
	read();
	printf("%I64d\n", solve());
	return 0;
}
