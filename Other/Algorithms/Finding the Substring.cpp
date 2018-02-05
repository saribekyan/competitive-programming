#include <iostream>
#include <string>
using namespace std;

string A, B;
int D[100];

void buildD()
{
	int i = 0, j = 0;
	D[0] = 0;
	for (i = 1; i < B.size(); i++)
	{
		while (A[i] != B[j] && j > 0)
			j = D[j-1];
		if (A[i] == B[j])
			j++;
		D[i] = j;
	}
}

void printLocations()
{
	int i = 0, j = 0;
	for (i = 0; i < A.size(); i++)
	{
		while (A[i] != B[j] && j > 0)
			j = D[j-1];
		if (A[i] == B[j])
			j++;
		if (j == B.size())
		{
			cout << i - j + 1 << '\n';
			j = D[j-1];
		}
	}
}

int main()
{
	cin >> A >> B;
	buildD();
	printLocations();
	return 0;
}