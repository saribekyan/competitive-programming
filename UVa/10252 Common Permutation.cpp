#include <stdio.h>
int a[26],b[26];

int main()
{
	char c;
	int i,j;
	while (1)
	{
		if (feof(stdin))break;
		for (i=0; i<26; i++)a[i]=b[i]=0;
		i = 0;
		while (1)
		{
			if (feof(stdin))break;
			c=getchar();
			if (c=='\n')i++;
			if (i==2)break;
			if (i==0)a[c-'a']++;
			else if (c!='\n')b[c-'a']++;
		}
		for (i=0; i<26; i++)
			for (j=0; j<(a[i]<b[i]?a[i]:b[i]); j++)putchar(i+'a');
		putchar('\n');
	}
	return 0;
}