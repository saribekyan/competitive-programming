#include <iostream>
#include <string.h>
using namespace std;
#define NMAX 100
char A[NMAX],B[NMAX], C[NMAX];
int k;

void rec(int a, int b, int p, int q)
{
	int i;
	for (i = a; i <= b; i++)
		if (A[i]==B[p])
		{
			C[k] = A[i];
			k--;
			rec(i+1, b, p+i-a+1, q);
			rec(a, i, p+1, p+i-a+1);
		}
}

int main()
{
	int i;
	while (cin >> B >> A)
	{
		k = strlen(A)-1;
		rec(0, k, 0, k);
		cout << C << '\n';
		for (i = 0; i < NMAX; i++)
			A[i] = B[i] = C[i] = '\0';
	}
	return 0;
}