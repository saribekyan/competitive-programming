#include <stdio.h>
#define Max(a, b) ((a)>(b)?(a):(b))

int d[300];
int g[300];
int main()
{
	int m, i;
	char ch;
	while (1)
	{
		ch = getchar();
		if (feof(stdin))
			break;
		if (ch != '\n' && ch != ' ')
		{
			d[ch]++;
			g[ch]++;
		}
	}
	while (1)
	{
		m = 0;
		for (i = 0; i < 300; i++)
			m = Max(m, d[i]);
		if (m == 0)
			break;
		for (i = 0; i < 300; i++)
			if (g[i])
			{
				if (d[i] == m)
				{
					putchar('#');
					d[i]--;
				}
				else
					putchar(' ');
			}
		putchar('\n');
	}
	for (i = 0; i < 300; i++)
		if (g[i])
			putchar(i);
	putchar('\n');
	return 0;
}
