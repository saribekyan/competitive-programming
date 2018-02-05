#include <cstdio>
char s1[81], s2[81];
FILE* fin = fopen("input.txt", "r");
FILE* fout = fopen("output.txt", "w");
int main()
{
	int n, m, i;
	n = m = 1;
	fscanf(fin, "%s%s", s1, s2);
	i = 0;
	while (s1[i])
	{
		n = (n*(s1[i]-'A'+1))%47;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		m = (m*(s2[i]-'A'+1))%47;
		i++;
	}
	if (n == m)
		fprintf(fout, "GO\n");
	else
		fprintf(fout, "STAY\n");
	return 0;
}