#include <iostream>
#include <math.h>
using namespace std;

double num_of_box[60];

int average(int l)
{
	int s, j;
	s = 0;
	for (j = 0; j < l; j++)
	{
		s += num_of_box[j];
	}
	s /= l;
	return s;
}

void main ()
{
	int n, i, k;
	double s, t;
	cin >> n;
	k = 1;
	while (n)
	{
		for (i = 0; i < n; i++)
			cin >> num_of_box[i];
		t = average(n);
		s = 0;
		for (i = 0; i < n; i++)
			 s += fabs(num_of_box[i] - t);
		s /= 2;
		cout << "Set #" << k++ << endl;
		cout << "The minimum number of moves is " << s << "." << endl;
		cin >> n;
	}
}