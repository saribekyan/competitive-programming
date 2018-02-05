#include <stdio.h>

int p[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	int d, m, s, i;
	scanf("%d%d", &d, &m);
	s = d;
	for (i = 0; i+1 < m; i++)
		s += p[i];
	if (s%7 == 1)
		printf("Thursday\n");
	if (s%7 == 2)
		printf("Friday\n");
	if (s%7 == 3)
		printf("Saturday\n");
	if (s%7 == 4)
		printf("Sunday\n");
	if (s%7 == 5)
		printf("Monday\n");
	if (s%7 == 6)
		printf("Tuesday\n");
	if (s%7 == 0)
		printf("Wednesday\n");
	return 0;
}
