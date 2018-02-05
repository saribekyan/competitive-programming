#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
const int n=9;
int d[n], BCG[3];
char c[3];

int main()
{
	int i, ans, m, j;
	while (scanf("%d", &d[0])==1)
	{
		for (i = 1; i < n; i++)scanf("%d", &d[i]);
		for (i = 0; i < 3; i++)BCG[i]=i;
		ans = INT_MAX;
		do
		{
			m = 0;
			for (i = 0; i < 3; i++)
			{
				if (BCG[i]==0)m+=d[3*i+1]+d[3*i+2];
				if (BCG[i]==1)m+=d[3*i+0]+d[3*i+1];					
				if (BCG[i]==2)m+=d[3*i+0]+d[3*i+2];
			}
			if (m<ans)
			{
				ans=m;
				for (i = 0; i < 3; i++)
				{
					if (BCG[i]==0)c[i]='B';
					if (BCG[i]==1)c[i]='C';
					if (BCG[i]==2)c[i]='G';
				}
			}
		}
		while (next_permutation(BCG, BCG+3));
		printf("%s %d\n", c, ans);
	}
	return 0;
}