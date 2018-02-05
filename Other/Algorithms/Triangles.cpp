#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

struct cor
{
	double x;
	double y;
};

double s (double x1, double y1, double x2, double y2, double x3, double y3)
{
	return fabs((x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3)/2);
}

int main()
{
	cor t[MAX];
	int n, i, j, k;
	double S, S1;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
			cin >> t[i].x >> t[i].y;
		S = 0;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				for (k = j + 1; k < n; k++)
				{
					S1 = s(t[i].x, t[i].y, t[j].x, t[j].y, t[k].x, t[k].y);
					if (S < S1)
						S = S1;
				}
		cout << S << "\n";
	}
	return 0;
}
