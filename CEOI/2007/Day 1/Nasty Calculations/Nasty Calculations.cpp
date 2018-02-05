#include <stdio.h>
#include <string.h>

int val[40];
int s[100010];
int exp[100010];
int main()
{
	char ch;
	int b, m, n, v, l, i;
	scanf("%d%d", &b, &m);
	getchar();
	ch = getchar();
	for (n = 0; ch != '\n'; ch = getchar())
		if (ch == ' ')
			n++;
		else
			if (ch == 'x')
				exp[n] = -4;
			else
				if (ch == '+')
					exp[n] = -1;
				else
					if (ch == '-')
						exp[n] = -2;
					else
						if (ch == '*')
							exp[n] = -3;
						else
							if ('0' <= ch && ch <= '9')
								exp[n] = ch-'0';
							else
								exp[n] = 10+ch-'A';
	for (v = 0; v < b; v++)
	{
		l = 0;
		for (i = 0; i <= n; i++)
			if (exp[i] >= 0)
				s[l++] = exp[i];
			else
				if (exp[i] == -1)
					s[l-2] = (s[l-2]+s[l-1])%b, l--;
				else
					if (exp[i] == -2)
						s[l-2] = (s[l-2]-s[l-1]+b)%b, l--;
					else
						if (exp[i] == -3)
							s[l-2] = (s[l-2]*s[l-1])%b, l--;
						else
							s[l++] = v;
		val[v] = s[0];
	}
	while (m--)
	{
		ch = getchar();
		for (v = 0; ch != '\n'; ch = getchar())
			if ('0' <= ch && ch <= '9')
				v = ch-'0';
			else
				v = 10+ch-'A';
		if (0 <= val[v] && val[v] <= 9)
			printf("%c\n", val[v]+'0');
		else
			printf("%c\n", val[v]-10+'A');
	}
	return 0;
}
