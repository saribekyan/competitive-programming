#include <stdio.h>
#define MAX 10
int S[MAX+1][MAX+1];
int main()
{
	int n, k, i, j;
	for (i = 0; i <= MAX; i++)S[0][i] = S[i][0] = 0;
	S[0][0] = 1;	
	for (i = 1; i <= MAX; i++)
		for (j = 1; j <= MAX; j++)
			S[i][j] = S[i-1][j-1]+j*S[i-1][j];	
	while (scanf("%d%d", &n, &k)==2)
	{
		if (k>n)printf("0\n");
		else printf("%d\n", S[n][k]);
	}
	return 0;
}