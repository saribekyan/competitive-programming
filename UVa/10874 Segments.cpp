#include <stdio.h>
#include <math.h>

int l[20000], r[20000], dl[20000], dr[20000];
int main()
{
	int n, i, j;
	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
			scanf("%d%d", l+i, r+i);
		dl[0] = 2*r[0]-l[0];
		dr[0] = r[0]-1;
		for (i = 1; i < n; i++)
		{
			dl[i] = dl[i-1] + abs(l[i-1]-r[i])+r[i]-l[i];
			if (dl[i] > dr[i-1] + abs(r[i-1]-r[i])+r[i]-l[i])
				dl[i] = dr[i-1] + abs(r[i-1]-r[i])+r[i]-l[i];
			dr[i] = dr[i-1] + abs(r[i-1]-l[i])+r[i]-l[i];
			if (dr[i] > dl[i-1] + abs(l[i-1]-l[i])+r[i]-l[i])
				dr[i] = dl[i-1] + abs(l[i-1]-l[i])+r[i]-l[i];
			dl[i]++;
			dr[i]++;
		}
		if (dl[n-1]-l[n-1] < dr[n-1]-r[n-1])
			printf("%d\n", dl[n-1]-l[n-1]+n);
		else
			printf("%d\n", dr[n-1]-r[n-1]+n);
	}
	return 0;
}