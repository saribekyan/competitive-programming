#include <stdio.h>
#define n 10
char d[12][12];
int main()
{
	int Ki,Kj,ki,kj,c,i,j,k,l,t=1;
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++)
			d[i][j]='.';
	while (1)
	{
		Ki=ki=-1;
		c = 1;
		for (i = 2; i < n; i++)
		{
			for (j = 2; j < n; j++)
			{
				scanf("%c", &d[i][j]);
				if (d[i][j]=='K')
				{
					Ki=i;
					Kj=j;
				}
				if (d[i][j]=='k')
				{
					ki=i;
					kj=j;
				}
				if (d[i][j]!='.')c=0;
			}
			getchar();
		}
		if (c)return 0;
		getchar();
		if (ki!=-1)
		{
			if (d[ki+1][kj-1]=='P'||d[ki+1][kj+1]=='P'){c=1;goto there;}
			if (d[ki-2][kj-1]=='N'||
				d[ki-2][kj+1]=='N'||
				d[ki-1][kj-2]=='N'||
				d[ki-1][kj+2]=='N'||
				d[ki+1][kj-2]=='N'||
				d[ki+1][kj+2]=='N'||
				d[ki+2][kj-1]=='N'||
				d[ki+2][kj+1]=='N'){c=1;goto there;}
			k = ki;
			while (k<n&&(d[k][kj]=='.'||k==ki))k++;
			if (d[k][kj]=='R'||d[k][kj]=='Q'){c=1;goto there;}
			k = ki;
			while (k>1&&(d[k][kj]=='.'||k==ki))k--;
			if (d[k][kj]=='R'||d[k][kj]=='Q'){c=1;goto there;}
			k = kj;
			while (k<n&&(d[ki][k]=='.'||k==kj))k++;
			if (d[ki][k]=='R'||d[ki][k]=='Q'){c=1;goto there;}
			k = kj;
			while (k>1&&(d[ki][k]=='.'||k==kj))k--;
			if (d[ki][k]=='R'||d[ki][k]=='Q'){c=1;goto there;}

			k=ki;l=kj;
			while (k<n&&l<n&&(d[k][l]=='.'||k==ki)){k++;l++;}
			if (d[k][l]=='B'||d[k][l]=='Q'){c=1;goto there;}
			k=ki;l=kj;
			while (k<n&&l>1&&(d[k][l]=='.'||k==ki)){k++;l--;}
			if (d[k][l]=='B'||d[k][l]=='Q'){c=1;goto there;}
			k=ki;l=kj;
			while (k>1&&l<n&&(d[k][l]=='.'||k==ki)){k--;l++;}
			if (d[k][l]=='B'||d[k][l]=='Q'){c=1;goto there;}
			k=ki;l=kj;
			while (k>1&&l>1&&(d[k][l]=='.'||k==ki)){k--;l--;}
			if (d[k][l]=='B'||d[k][l]=='Q'){c=1;goto there;}
		}

		if (Ki!=-1&&c==0)
		{
			ki = Ki;
			kj = Kj;
			if (d[ki-1][kj-1]=='p'||d[ki-1][kj+1]=='p'){c=2;goto there;}
			if (d[ki-2][kj-1]=='n'||
				d[ki-2][kj+1]=='n'||
				d[ki-1][kj-2]=='n'||
				d[ki-1][kj+2]=='n'||
				d[ki+1][kj-2]=='n'||
				d[ki+1][kj+2]=='n'||
				d[ki+2][kj-1]=='n'||
				d[ki+2][kj+1]=='n'){c=2;goto there;}
			k = ki;
			while (k<n&&(d[k][kj]=='.'||k==ki))k++;
			if (d[k][kj]=='r'||d[k][kj]=='q'){c=2;goto there;}
			k = ki;
			while (k>1&&(d[k][kj]=='.'||k==ki))k--;
			if (d[k][kj]=='r'||d[k][kj]=='q'){c=2;goto there;}
			k = kj;
			while (k<n&&(d[ki][k]=='.'||k==kj))k++;
			if (d[ki][k]=='r'||d[ki][k]=='q'){c=2;goto there;}
			k = kj;
			while (k>1&&(d[ki][k]=='.'||k==kj))k--;
			if (d[ki][k]=='r'||d[ki][k]=='q'){c=2;goto there;}

			k=ki;l=kj;
			while (k<n&&l<n&&(d[k][l]=='.'||k==ki)){k++;l++;}
			if (d[k][l]=='b'||d[k][l]=='q'){c=2;goto there;}
			k=ki;l=kj;
			while (k<n&&l>1&&(d[k][l]=='.'||k==ki)){k++;l--;}
			if (d[k][l]=='b'||d[k][l]=='q'){c=2;goto there;}
			k=ki;l=kj;
			while (k>1&&l<n&&(d[k][l]=='.'||k==ki)){k--;l++;}
			if (d[k][l]=='b'||d[k][l]=='q'){c=2;goto there;}
			k=ki;l=kj;
			while (k>1&&l>1&&(d[k][l]=='.'||k==ki)){k--;l--;}
			if (d[k][l]=='b'||d[k][l]=='q'){c=2;goto there;}
		}
there:;
		printf("Game #%d: ",t);
		if (c==0)printf("no king is in check.\n");
		if (c==1)printf("black king is in check.\n");
		if (c==2)printf("white king is in check.\n");
		t++;
	}
}