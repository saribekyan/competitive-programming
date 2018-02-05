/*
PROG: prime3
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int w[5][5];
bool pr[100000];
int p1[10][150], p2[10][10][100], np1[10], np2[10][10], **ans[160];
bool is_prime(int n)
{
	if (n%2 == 0)
		return 0;
	int i;
	for (i = 3; i*i <= n; i += 2)
		if (n%i == 0)
			return 0;
	return 1;
}
bool cmp(int **a, int **b)
{
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
		{
			if (a[i][j] < b[i][j])
				return 1;
			if (a[i][j] > b[i][j])
				return 0;
		}
	return 0;
}
FILE* fin = fopen("prime3.in", "r");
FILE* fout = fopen("prime3.out", "w");
int main()
{
	int sum, dig, n, m, digit, d1, d2, i, j, k, l, p, l1, l2;
	fscanf(fin, "%d%d", &sum, &dig);
	w[0][0] = dig;
	n = 0;
	for (i = 1000; i <= 9999; i++)
	{
		m = sum-i%10-(i/10)%10-(i/100)%10-i/1000;
		if (m >= 0 && m < 10)
		{
			m += i*10;
			if (is_prime(m))
			{
				pr[m] = 1;
				p1[m/10000][np1[m/10000]++] = m;
				p2[m/10000][(m/1000)%10][np2[m/10000][(m/1000)%10]++] = m;
			}
		}
	}
	for (i = 0; i < 160; i++)
	{
		ans[i] = new int*[5];
		for (j = 0; j < 5; j++)
			ans[i][j] = new int[5];
	}
	for (i = 0; i < np1[dig]; i++)//1st row
	{
	 for (m = p1[dig][i], p = 4; p > 0; p--, m /= 10)
		 w[0][p] = m%10;
	 if (w[0][1] && w[0][2] && w[0][3])//checking 1st row
	  for (j = 0; j < np1[dig]; j++)//1st col
	  {
	   for (m = p1[dig][j], p = 4; p > 0; p--, m /= 10)
		   w[p][0] = m%10;
	   if (w[1][0] && w[2][0] && w[3][0])//checking 1st col
	   {
	    digit = w[1][0];
	    for (k = 0; k < np1[digit]; k++)//2nd row
		{
		 for (m = p1[digit][k], p = 4; p > 0; p--, m /= 10)
		  w[1][p] = m%10;
		 d1 = w[0][1];
		 d2 = w[1][1];
		 for (l = 0; l < np2[d1][d2]; l++)//2nd col
		 {
		  for (m = p2[d1][d2][l], p = 4; p > 1; p--, m /= 10)
		   w[p][1] = m%10;
		  w[2][2] = sum-w[0][4]-w[1][3]-w[3][1]-w[4][0];
		  m = w[4][0]*10000+w[3][1]*1000+w[2][2]*100+w[1][3]*10+w[0][4];//2nd diag
		  if (pr[m])
		   for (w[2][4] = 1; w[2][4] <= 9; w[2][4] += 2)//w[2][4]
		    if (w[2][4] != 5)//prime never ends on 5
		    {
		     w[2][3] = sum-w[2][0]-w[2][1]-w[2][2]-w[2][4];
	 		 m = w[2][0]*10000+w[2][1]*1000+w[2][2]*100+w[2][3]*10+w[2][4];//3rd row
			 if (pr[m])
			  for (w[4][4] = 1; w[4][4] <= 9; w[4][4] += 2)//w[4][4]
			   if (w[4][4] != 5)
			   {
			    w[3][3] = sum-w[0][0]-w[1][1]-w[2][2]-w[4][4];
				m = w[0][0]*10000+w[1][1]*1000+w[2][2]*100+w[3][3]*10+w[4][4];//1st diag
				if (pr[m])
				{
				 w[3][4] = sum-w[0][4]-w[1][4]-w[2][4]-w[4][4];
				 w[3][2] = sum-w[3][0]-w[3][1]-w[3][3]-w[3][4];
				 w[4][2] = sum-w[0][2]-w[1][2]-w[2][2]-w[3][2];
				 w[4][3] = sum-w[0][3]-w[1][3]-w[2][3]-w[3][3];
				 if (pr[w[0][4]*10000+w[1][4]*1000+w[2][4]*100+w[3][4]*10+w[4][4]] &&//5th col
					 pr[w[3][0]*10000+w[3][1]*1000+w[3][2]*100+w[3][3]*10+w[3][4]] &&//4th row
					 pr[w[0][2]*10000+w[1][2]*1000+w[2][2]*100+w[3][2]*10+w[4][2]] &&//3rd col
					 pr[w[0][3]*10000+w[1][3]*1000+w[2][3]*100+w[3][3]*10+w[4][3]] &&//4th col
					 pr[w[4][0]*10000+w[4][1]*1000+w[4][2]*100+w[4][3]*10+w[4][4]])  //5th row
				 {
					 for (l1 = 0; l1 < 5; l1++)
						 for (l2 = 0; l2 < 5; l2++)
							 ans[n][l1][l2] = w[l1][l2];
					 n++;
				 }
				}
			   }
		   }
		 }
		}
	   }
	  }
	}
	sort(ans, ans+n, cmp);
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < 5; k++)
				fprintf(fout, "%d", ans[i][j][k]);
			fputc('\n', fout);
		}
		fputc('\n', fout);
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			fprintf(fout, "%d", ans[n-1][i][j]);
		fputc('\n', fout);
	}
	return 0;
}