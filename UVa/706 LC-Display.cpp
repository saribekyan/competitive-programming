#include <stdio.h>
#include <string.h>
char c[10];
void pr_line(int s,char a, char b, char c)
{
	int i;
	putchar(a);
	for (i = 0; i < s; i++)putchar(b);
	putchar(c);
}
int main()
{
	int s, i, j, n;
	while (scanf("%d%s", &s, c)&&(s||c[0]!='0'))
	{
		n = strlen(c);
		for (i = 0; i < n; i++)
		{
			if (i)putchar(' ');
			if (c[i]!='1'&&c[i]!='4')
				pr_line(s,' ', '-', ' ');
			else pr_line(s, ' ', ' ', ' ');
			
		}
		for (i = 2; i <= s+1; i++)
		{
			putchar('\n');
			for (j = 0; j < n; j++)
			{
				if (j)putchar(' ');
				if (c[j]=='5'||c[j]=='6')pr_line(s,'|',' ',' ');
				if (c[j]=='1'||c[j]=='2'||c[j]=='3'||c[j]=='7')
					pr_line(s,' ', ' ', '|');
				if (c[j]=='4'||c[j]=='8'||c[j]=='9'||c[j]=='0')
					pr_line(s,'|', ' ', '|');
				
			}
		}
		putchar('\n');
		for (i = 0; i < n; i++)
		{
			if (i)putchar(' ');
			if (c[i]=='1'||c[i]=='7'||c[i]=='0')
				pr_line(s,' ',' ',' ');
			else pr_line(s, ' ', '-', ' ');
			
		}
		for (i = s+3; i <= 2*s+2; i++)
		{
			putchar('\n');
			for (j = 0; j < n; j++)
			{
				if (j)putchar(' ');
				if (c[j]=='2')pr_line(s,'|',' ',' ');
				if (c[j]=='6'||c[j]=='8'||c[j]=='0')pr_line(s,'|',' ','|');
				if (c[j]=='1'||c[j]=='3'||c[j]=='4'||c[j]=='5'||c[j]=='7'||c[j]=='9')
					pr_line(s,' ',' ','|');
				
			}
		}
		putchar('\n');
		for (i = 0; i < n; i++)
		{
			if (i)putchar(' ');
			if (c[i]=='1'||c[i]=='4'||c[i]=='7')pr_line(s,' ',' ',' ');
			else pr_line(s,' ','-',' ');
			
		}
		printf("\n\n");
	}
	return 0;
}