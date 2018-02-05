#include <stdio.h>
#define MAX 100
char s[MAX+1][MAX+1],l[26],str[]="the quick brown fox jumps over the lazy dog\0";

int main()
{
	int t,n,i,j;
	scanf("%d", &t);
	while (t)
	{
		while (gets(s[0]))
			if (s[0][0])break;
		n = 1;
		while (gets(s[n]))
		{
			if (s[n][0]==0)break;
			n++;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 26; j++)l[j]=0;
			for (j = 0; s[i][j]&& j<43; j++)
			{
				if (str[j]!=' ' && s[i][j]!=' ' && (l[s[i][j]-'a']==0 || str[j]==l[s[i][j]-'a']))
					l[s[i][j]-'a']=str[j];
				else
					if (!(s[i][j]==' ' && str[j]==' '))
						break;
			}
			if (s[i][j]==0 && j==43)
				break;
		}
		if (i!=n)
			for (i = 0; i < n; i++)
			{
				for (j = 0; s[i][j]; j++)
					if (s[i][j]==' ')putchar(' ');
					else putchar(l[s[i][j]-'a']);
				putchar('\n');
			}
		else
			printf("No solution.\n");
		t--;
		if (t)putchar('\n');
	}
	return 0;
}