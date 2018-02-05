#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

int main()
{
	ifstream fin("pieface.in");
	int n, m, x1, y1, x2, y2, d;
	fin >> n >> m >> x1 >> y1 >> x2 >> y2;
	while (1)
	{
		d = Min(abs(x1-x2), abs(y1-y2)); 
		x1 = x2-d*(x2-x1)/abs(x2-x1);
		y1 = y2-d*(y2-y1)/abs(y2-y1);
		cout << x1 << ' ' << y1 << '\n' << flush;
		cin >> x2 >> y2;
	}
	return 0;
}
