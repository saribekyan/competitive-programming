#include <stdio.h>
#include <string.h>
#define MAX 50
char d[MAX+1][MAX+1],w[MAX+1];

int main()
{
	int t,n,m,l,i,j,k,q,len,c;
	scanf("%d",&t);
	while (t)
	{
		scanf("%d%d\n",&n,&m);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				d[i][j]=getchar();
				if (d[i][j]>='A'&&d[i][j]<='Z')d[i][j]=d[i][j]-'A'+'a';
			}
			scanf("\n");
		}
		scanf("%d",&l);
		for (q = 0; q < l; q++)
		{
			scanf("%s",&w);
			len=strlen(w);
			for (i = 0; i < len; i++)
				if (w[i]>='A'&&w[i]<='Z')
					w[i]=w[i]-'A'+'a';
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
				{
					if (j+len-1<m){c=1;
						for (k=0; k < len; k++)
							if (w[k]!=d[i][j+k])
							{
								c=0;
								break;
							}
						if (c)goto there;
					}
					if (j-len+1>=0){c=1;
						for (k = 0; k < len; k++)
							if (w[k]!=d[i][j-k]){c=0;break;}
						if (c)goto there;
					}
 					if (i+len-1<n){c=1;
						for (k=0; k < len; k++)
							if (w[k]!=d[i+k][j]){c=0;break;}
						if (c)goto there;
					}
					if (i-len+1>=0){c=1;
						for (k = 0; k < len; k++)
							if (w[k]!=d[i-k][j]){c=0;break;}
						if (c)goto there;
					}
					if (i-len+1>=0&&j-len+1>=0){c=1;
						for (k = 0; k < len; k++)
							if (w[k]!=d[i-k][j-k])
							{
								c=0;
								break;
							}
						if (c)goto there;
					}
					if (i-len+1>=0&&j+len-1<m){c=1;
						for (k = 0; k < len; k++)
							if (w[k]!=d[i-k][j+k]){c=0;break;}
						if (c)goto there;
					}
					if (i+len-1<n&&j-len+1>=0){c=1;
						for (k = 0; k < len; k++)
							if (w[k]!=d[i+k][j-k]){c=0;break;}
						if (c)goto there;
					}
					if (i+len-1<n&&j+len-1<m){c=1;
						for (k = 0; k < len; k++)
							if (w[k]!=d[i+k][j+k])
							{
								c=0;
								break;
							}
						if (c)goto there;
					}
				}
there:printf("%d %d\n",i+1,j+1);
		}
		t--;
	}
	return 0;
}