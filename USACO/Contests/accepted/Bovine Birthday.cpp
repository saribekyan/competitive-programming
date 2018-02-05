#include <cstdio>

bool nah(int n)
{
	if (n%400 == 0)return 1;
	if (n%100 == 0)return 0;
	if (n%4 == 0)return 1;
	return 0;
}
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
FILE* fin = fopen("bday.in", "r");
FILE* fout = fopen("bday.out", "w");
int main()
{
	int y, m, d, n, i;
	fscanf(fin, "%d%d%d", &y, &m, &d);
	if (y >= 1900)
	{
		n = -1;
		for (i = 1900; i < y; i++)
			if (nah(i))
				n = (n+366)%7;
			else
				n = (n+365)%7;
		if (nah(y))
			month[1]++;
		for (i = 0; i < m-1; i++)
			n = (n+month[i])%7;
		n = (n+d)%7;
	}
	else
	{
		n = 0;
		for (i = y; i < 1900; i++)
			if (nah(i))
				n += 366;
			else
				n += 365;
		if (nah(y))
			month[1]++;
		for (i = 0; i < m-1; i++)
			n -= month[i];
		n = n-d;
		n++;
		n = (7-(n%7))%7;
	}
	if (n == 0)
		fprintf(fout, "monday\n");
	if (n == 1)
		fprintf(fout, "tuesday\n");
	if (n == 2)
		fprintf(fout, "wednesday\n");
	if (n == 3)
		fprintf(fout, "thursday\n");
	if (n == 4)
		fprintf(fout, "friday\n");
	if (n == 5)
		fprintf(fout, "saturday\n");
	if (n == 6)
		fprintf(fout, "sunday\n");
	return 0;
}