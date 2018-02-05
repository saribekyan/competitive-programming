#include <stdio.h>
#define MAX 100
void reverse(int f, int s, int*d)
{
	int i, t;
	for (i = f; i < (s+f)/2; i++){t=d[i];d[i]=d[s-i-1+f];d[s-i-1+f]=t;}
}
bool next_permutation(int n, int *d)
{
	int i, k, m, t;
	for (k=n-2; k>=0; k--)if (d[k]<d[k+1])break;
	if (k==-1&&d[0]>d[1])return 0;
	m = k+1;
	for (i = k+2; i < n; i++)if (d[m]>d[i]&&d[i]>d[k])m = i;
	t = d[k];
	d[k] = d[m];
	d[m] = t;
	reverse(k+1, n, d);
	return 1;
}
bool next_subpermutation1()
{
	int d[MAX], b[MAX], n, m, i, k;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)b[i] = 0;
	for(i = 0; i < m; i++){scanf("%d", &d[i]); b[d[i]-1]=1;}
	k = m;
	for (i = n-1; i >= 0; i--)if (!b[i])d[k++]=i+1;
	if (!next_permutation(n, d))return 0;
	for (i = 0; i < m; i++)printf("%d ", d[i]);
	putchar('\n');
	return 1;
}
bool next_subpermutation2()
{
	bool f;
	int d[MAX], b[MAX], n, m, i, k, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)	b[i] = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &d[i]);
		b[d[i]-1]=1;
	}
	f = 0;
	if (n==m)f = next_permutation(n, d);
	else
	for (i = m-1; i>=0; i--){
		for (j = d[i]; j < n; j++)if (b[j]==0){
				d[i]=j+1;
				f = 1;
				break;
		}
		if (f)break;
	}
	if (f)for (i = 0; i < m; i++)printf("%d ", d[i]);
	putchar('\n');
	return f;
}
int main()
{
//	if (!next_subpermutation1())printf("0\n");
	if (!next_subpermutation2())printf("0\n");
	return 0;
}