#include <iostream>
using namespace std;
#define MAX 1000
int D[MAX];
int prime_numbers[MAX];

bool is_prime(int n)
{
	int i;
	if (n != 2 && n % 2 == 0)
		return false;
	for (i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int i, k, j, n;
	cin >> n;
	k = 0;
	for (i = 2; i <= n; i++)
		if (is_prime(i))
			prime_numbers[k++] = i;
	D[0] = 1;
	for (j = 0; j < k; j++)
		for (i = n; i >= 0; i--)
			if (D[i])
				if (i+prime_numbers[j] <= n)
					D[i+prime_numbers[j]]++;
	cout << D[n] << "\n";
	return 0;
}