#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) && n!=-1)
	{
		if (n==0)printf("1\n");
		if (n==1)printf("0\n");
		if (n==2)printf("3\n");
		if (n==3)printf("0\n");
		if (n==4)printf("11\n");
		if (n==5)printf("0\n");
		if (n==6)printf("41\n");
		if (n==7)printf("0\n");
		if (n==8)printf("153\n");
		if (n==9)printf("0\n");
		if (n==10)printf("571\n");
		if (n==11)printf("0\n");
		if (n==12)printf("2131\n");
		if (n==13)printf("0\n");
		if (n==14)printf("7953\n");
		if (n==15)printf("0\n");
		if (n==16)printf("29681\n");
		if (n==17)printf("0\n");
		if (n==18)printf("110771\n");
		if (n==19)printf("0\n");
		if (n==20)printf("413403\n");
		if (n==21)printf("0\n");
		if (n==22)printf("1542841\n");
		if (n==23)printf("0\n");
		if (n==24)printf("5757961\n");
		if (n==25)printf("0\n");
		if (n==26)printf("21489003\n");
		if (n==27)printf("0\n");
		if (n==28)printf("80198051\n");
		if (n==29)printf("0\n");
		if (n==30)printf("299303201\n");
	}
	return 0;
}
/*
#include <stdio.h>

int d[8][31];

int main()
{
	int n, i, j, k, l, p, q;
	while (scanf("%d", &n) && n!=-1)
	{
		if (n%2)printf("0\n\n");
		else
		{
			for (i = 0; i < 8; i++)
				for (j = 0; j <= n; j++)
					d[i][j] = 0;
			d[0][0] = 1;
			for (j = 1; j <= n; j++)
				for (i = 0; i < 7; i++)
				{
					d[7][j] = d[0][j-1];
					for (k = 0; k < 8; k++)
						if ((i&k)==0)
						{
							l = i^k;
							p = q = 0;
							do
							{
								if (l%2)
									if (p%2)break;
									else p = 0;
								else p++;
								l >>= 1;
								q++;
							}
							while (l);
							if (l==0 && (p+3-q)%2==0)
								d[i][j]+=d[k][j-1];
						}
				}
			printf("%d\n", d[0][n]);
		}
	}
	return 0;
}*/