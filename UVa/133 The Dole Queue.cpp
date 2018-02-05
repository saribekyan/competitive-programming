#include <stdio.h>
#define MAX 20
int d[MAX];

int main()
{
	int n, k, m, i, p, q, t, l;
	while (scanf("%d%d%d", &n, &k, &m) && n&&k&&m)
	{
		for (i = 0; i < n; i++)d[i]=i+1;
		p = 0;
		q = n-1;
		l = n;
		while (l>0)
		{
			t = 0;
			while (t<k)
			{
				if (p==n)p=0;
				if (d[p]!=0)t++;
				p++;
			}
			p--;
			t = 0;
			while (t<m)
			{
				if (q==-1)q=n-1;
				if (d[q]!=0)t++;
				q--;
			}
			q++;
			d[p]=d[q]=0;
			if (p!=q){printf("%3d%3d", p+1, q+1);l--;}
			else printf("%3d", p+1);
			l--;
			if (l>0)putchar(',');
		}
		putchar('\n');
	}
	return 0;
}