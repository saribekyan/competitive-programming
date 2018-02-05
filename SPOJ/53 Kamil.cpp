#include<cstdio>
int main()
{
	int t=1;
	char c;
	while(scanf("%c",&c)==1)
		c==10?printf("%d\n",t),t=1:t=t*(c==84|c==68|c==76|c==70)+t;
	return 0;
}