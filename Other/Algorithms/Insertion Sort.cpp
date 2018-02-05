#include <iostream>
using namespace std;
#define MAX 10

int main()
{
	int key, j, i, A[MAX], n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> A[i];
	for (j = 1; j < n; j++)
	{
		key = A[j];
		i = j-1;
		while (i>=0 && A[i]>key)
		{
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
	for (i = 0; i < n; i++)
		cout << A[i] << "\n";
	return 0;
}