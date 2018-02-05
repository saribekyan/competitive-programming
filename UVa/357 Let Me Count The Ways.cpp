#include <iostream>
using namespace std;
#define MAX 30000

unsigned long long D[MAX+1];
int a[5] = {1, 5, 10, 25, 50};

int main()
{
	int i, j, n;	
	for (i = 1; i <= MAX; i++)
		D[i] = 0;
	D[0] = 1;
	for (i = 0; i < 5; i++)
		for (j = a[i]; j <= MAX; j++)
			D[j] += D[j-a[i]];
	while (cin >> n)
		if (D[n] == 1)
			cout << "There is only 1 way to produce " << n << " cents change.\n";
		else
			cout << "There are " << D[n] << " ways to produce " << n << " cents change.\n";
	return 0;
}