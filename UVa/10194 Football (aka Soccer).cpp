#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 30
char s[100], tournament[100], name1[31], s1[31],s2[31];

struct team{int p,win,goalsc,goalag,play,lose; char name[31];}d[MAX];
bool operator <(team a, team b)
{
	if (a.p>b.p)return 1;
	if (a.p<b.p)return 0;
	if (a.win>b.win)return 1;
	if (a.win<b.win)return 0;
	if (a.goalsc-a.goalag>b.goalsc-b.goalag)return 1;
	if (a.goalsc-a.goalag<b.goalsc-b.goalag)return 0;
	if (a.goalsc>b.goalsc)return 1;
	if (a.goalsc<b.goalsc)return 0;
	if (a.play<b.play)return 1;
	if (a.play>b.play)return 0;
	int i,n=strlen(a.name);
	for (i = 0; i < n; i++)
		if (a.name[i]>='A'&&a.name[i]<='Z')s1[i]=a.name[i]-'A'+'a';
		else s1[i]=a.name[i];
	s1[n]=0;
	n = strlen(b.name);
	for (i = 0; i < n; i++)
		if (b.name[i]>='A'&&b.name[i]<='Z')s2[i]=b.name[i]-'A'+'a';
		else s2[i]=b.name[i];
	s2[n]=0;
	if (strcmp(s1, s2)<0)return 1;
	return 0;
}
int main()
{
	int t,n,m,i,j,k,p,q;
	scanf("%d",&t);
	gets(tournament);
	while (t)
	{
		gets(tournament);
		scanf("%d",&n);
		gets(s);
		for (i = 0; i < n; i++)
		{
			gets(d[i].name);
			d[i].p=d[i].win=d[i].goalag=d[i].goalsc=d[i].play=d[i].lose=0;
		}
		scanf("%d",&m);
		gets(s);
		for (i = 0; i < m; i++)
		{
			gets(s);
			for (j = 0; j < 31; j++)name1[j]=0;
			j = 0;
			while (s[j]!='#')
			{
				name1[j]=s[j];
				j++;
			}
			j++;
			p = 0;
			while (s[j]>='0'&&s[j]<='9')
			{
				p = p*10+(s[j]-'0');
				j++;
			}
			j++;
			q = 0;
			while (s[j]>='0'&&s[j]<='9')
			{
				q = q*10+(s[j]-'0');
				j++;
			}
			j++;
			for (k = 0; k < n; k++)
				if (strcmp(d[k].name,name1)==0)
					break;
			d[k].play++;
			d[k].goalsc+= p;
			d[k].goalag+= q;
			if (p>q)
			{
				d[k].win++;
				d[k].p+=3;
			}
			if (p==q)d[k].p++;
			if (p<q)
				d[k].lose++;
			for (k = 0; k < 31; k++)name1[k]=0;
			k = 0;
			while (s[j])
			{
				name1[k]=s[j];
				k++;
				j++;
			}
			for (k = 0; k < n; k++)
				if (strcmp(d[k].name,name1)==0)
					break;
			d[k].play++;
			d[k].goalsc+= q;
			d[k].goalag+= p;
			if (p<q)
			{
				d[k].win++;
				d[k].p+=3;
			}
			if (p==q)d[k].p++;
			if (p>q)
				d[k].lose++;
		}

		sort(d,d+n);
		printf("%s\n",tournament);
		for (i = 0; i < n; i++)
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, d[i].name,d[i].p, d[i].play, d[i].win, d[i].play-d[i].win-d[i].lose, d[i].lose, d[i].goalsc-d[i].goalag, d[i].goalsc, d[i].goalag);
		t--;
		if (t)putchar('\n');
		else return 0;
	}
}