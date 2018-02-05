#include <stdio.h>
#include <math.h>
#define min(a,b) ((a)<(b)?(a):(b))
int d[50][50];
int pl[2500][2];
int state[50];

int main()
{
	int t, h, l, cari, i, j, ncars, ans;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &h, &l);					
		ncars = 0;
		for (i=0; i<h; i++)
			for (j=0; j<l; j++)
			{
				scanf("%d", &cari);
				if (cari != -1)
				{
					pl[cari-1][0] = i;
					pl[cari-1][1] = j;
					ncars++;					
				}				
			}
		for (i=0; i<h; i++) state[i] = 0;
		ans = 0;		
		for (i=0; i<ncars; i++)
		{			
			ans += pl[i][0]*20;												
			ans += min(l-abs(pl[i][1]-state[pl[i][0]]), abs(pl[i][1]-state[pl[i][0]]))*5;
			state[pl[i][0]] = pl[i][1];
		}		
		printf("%d\n", ans);
	}
	return 0;
}
/*
2
1 5
-1 2 1 -1 3
3 6
-1 5 6 -1 -1 3
-1 -1 7 -1 2 9
-1 10 4 1 8 -1
*/