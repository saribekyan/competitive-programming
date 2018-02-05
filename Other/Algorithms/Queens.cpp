#include <stdio.h>
int count, c[8], d1[15], d2[15], r[8];

void rec(int v)
{
	int i;
	if (v == 8)
	{
		for (i = 0; i < 8; i++)
			printf("%d ", c[i]);
		putchar('\n');
		count++;
	}
	else
	{
		for (i = 0; i < 8; i++)
			if (r[i] && d1[v-i+7] && d2[v+i])
			{
				c[v] = i+1;
				r[i] = d1[v-i+7] = d2[v+i] = false;
				rec(v+1);
				r[i] = d1[v-i+7] = d2[v+i] = true;
			}
	}
}

int main()
{
	int i;
	for (i = 0; i < 8; i++)
		r[i] = true;
	for (i = 0; i < 15; i++)
		d1[i] = d2[i] = true;
	rec(0);
	printf("%d\n", count);
	return 0;
}