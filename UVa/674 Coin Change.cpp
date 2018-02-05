#include <iostream>
using namespace std;
#define MAX 7489

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
			cout << D[n] << "\n";
	return 0;
}