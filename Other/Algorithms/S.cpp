#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

struct cor
{
	double x;
	double y;
};

int main()
{
	cor a[MAX];
	int i, n;
	double S;
	S = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	for (i = 0; i < n - 1; i++)
		S += a[i].x * a[i + 1].y - a[i + 1].x * a[i].y;
	S += a[n - 1].x * a[0].y - a[0].x * a[n - 1].y;
	S /= 2;
	cout << fabs(S) << endl;
	return 0;
}