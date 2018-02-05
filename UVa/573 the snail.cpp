// 573 the snail
#include <iostream>
using namespace std;

double percent (double a, double b)
{
	double s;
	s = a / 100 * b;
	return s;
}

main()
{
	double S, H, D, F, j;
	double U, i;
	cin >> H >> U >> D >> F;
	while (H || D  || U  || F )
	{
		S = 0;
		j = 0;
		i = percent(U, F);
		while (S >= 0 && S <= H)
		{
			S += U;	
            if (U)
                U -= i;
			j++;
			if (S <= 0 || S > H)
				break;
			S -= D;			
		}
		if (S > H)
            cout << "success on day ";
		else
			cout << "failure on day ";
		cout << j << endl;
		cin >> H >> U >> D >> F;
	}
	return 0;
}