#include <iostream>
using namespace std;
const int MAX=130;
char d[MAX*MAX],g[MAX*MAX],s1[MAX][MAX],s2[MAX][MAX];

int main()
{
	int t=1,n,m,i,j,k,p;
	while (cin>>n && n)
	{
		cin.getline(s1[0],MAX);
		for (i=0; i<n; i++)
			cin.getline(s1[i],MAX);
		cin>>m;
		cin.getline(s2[0],MAX);
		for (i=0; i<m; i++)
			cin.getline(s2[i],MAX);
		cout<< "Run #"<<t << ": ";t++;
		if (n==m)
		{
			p=1;
			for (i = 0; i < n; i++)
				if (strcmp(s1[i],s2[i]))
				{
					p=0;
					break;
				}
			if (p)
			{
				cout<< "Accepted\n";
				goto there;
			}
		}
		k=0;
		for (i=0; i<n; i++)
			for (j=0; j<strlen(s1[i]); j++)
				if (s1[i][j]>='0'&&s1[i][j]<='9')
				{
					d[k]=s1[i][j];
					k++;
				}
		d[k]='\0';
		k=0;
		for (i=0; i<m; i++)
			for (j=0; j<strlen(s2[i]); j++)
				if (s2[i][j]>='0'&&s2[i][j]<='9')
				{
					g[k]=s2[i][j];
					k++;
				}
		g[k]='\0';
		if (strcmp(d,g)==0)cout<< "Presentation Error\n";
		else cout<< "Wrong Answer\n";
there:;
	}
	return 0;
}