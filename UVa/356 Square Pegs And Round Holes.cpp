// 356 Square Pegs And Round Holes

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int n, n_ins, n_on, i, j, it;
	bool f1, f2;

	it = 0;	
	while (cin >> n)
	{
		n_ins = 0;
		n_on = 0;
        for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				f1 = pow(i - n, 2) + pow(j - n, 2) <= pow (n - 0.5, 2);
				f2 = pow(i + 1 - n, 2) + pow(j + 1 - n, 2) <= pow(n - 0.5,2);
                if (f1 && f2)
					n_ins++;
				else
                    if (!f1 && f2)
						n_on++;
 			}
		n_on *= 4;
		n_ins *= 4;
		if (it++) cout << '\n';
		cout << "In the case n = "<< n<< ", "<< n_on<< " cells contain segments of the circle."<< endl;
		cout << "There are "<< n_ins<< " cells completely contained in the circle."<< endl;		
	}
	return 0;
}