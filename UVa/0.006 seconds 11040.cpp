#include <stdio.h>
int
 a1,
 a2,  a3,
 a4,  a5,  a6,
 a7,  a8,  a9, a10,
a11, a12, a13, a14, a15;
int main()
{
	int t;
	scanf("%d", &t);
	while (t)
	{
		scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
			 &a1,

			 &a2,		&a3,

			 &a4,		&a5,		&a6,

			 &a7,		&a8,		&a9,		&a10,

			&a11,		&a12,		&a13,		&a14,		&a15
			);
		printf("%d\n%d %d\n%d %d %d\n%d %d %d %d\n%d %d %d %d %d\n%d %d %d %d %d %d\n%d %d %d %d %d %d %d\n%d %d %d %d %d %d %d %d\n%d %d %d %d %d %d %d %d %d\n",
			a1,
			a2+(a1-a2-a3)/2, (a1-a2-a3)/2+a3,
			a2, (a1-a2-a3)/2, a3,
			a4+(a2-a4-a5)/2, (a2-a4-a5)/2+a5, a5+(a3-a5-a6)/2, (a3-a5-a6)/2+a6,
			a4, (a2-a4-a5)/2, a5, (a3-a5-a6)/2, a6,
			a7+(a4-a7-a8)/2, (a4-a7-a8)/2+a8, a8+(a5-a8-a9)/2, (a5-a8-a9)/2+a9, a9+(a6-a9-a10)/2, (a6-a9-a10)/2+a10,
			a7, (a4-a7-a8)/2, a8, (a5-a8-a9)/2, a9, (a6-a9-a10)/2, a10,
			a11+(a7-a11-a12)/2, (a7-a11-a12)/2+a12, a12+(a8-a12-a13)/2, (a8-a12-a13)/2+a13, a13+(a9-a13-a14)/2, (a9-a13-a14)/2+a14, a14+(a10-a14-a15)/2, (a10-a14-a15)/2+a15,
			a11, (a7-a11-a12)/2, a12, (a8-a12-a13)/2, a13, (a9-a13-a14)/2, a14, (a10-a14-a15)/2, a15
			);
		t--;
	}
	return 0;
}