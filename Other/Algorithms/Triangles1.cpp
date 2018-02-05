#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
const double EPS = 1e-10;
struct cor
{
	double x;
	double y;
};

double s (double x1, double y1, double x2, double y2, double x3, double y3)
{
	return fabs((x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3)/2);
}

bool is_in(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double s1, s2, s3, s4;
	s1 = s(x1, y1, x2, y2, x4, y4);
	s2 = s(x2, y2, x3, y3, x4, y4);
	s3 = s(x1, y1, x3, y3, x4, y4);
	s4 = s(x1, y1, x2, y2, x3, y3);
	return fabs(s4-(s1 + s2 + s3)) < EPS;
}

int main()
{
	cor t[MAX];
	int n, i, j, k, l;
	double S, S1;
	while (cin >> n)
	{
		
		for (i = 0; i < n; i++)
			cin >> t[i].x >> t[i].y;
		S = 0;
		for (l = 0; l < n; l++)
			for (i = 0; i < n; i++)
				for (j = i + 1; j < n; j++)
					for (k = j + 1; k < n; k++)
					{
						S1 = s(t[i].x, t[i].y, t[j].x, t[j].y, t[k].x, t[k].y);
						if (S < S1 && !is_in(t[i].x, t[i].y, t[j].x, t[j].y, t[k].x, t[k].y, t[l].x, t[l].y))
							S = S1;
					}
		cout << S << "\n";
	}
	return 0;
}