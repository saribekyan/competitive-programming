#include <iostream>
using namespace std;

void main()
{	
	int n, s, i, j;
	cout << "PERFECTION OUTPUT"<< endl;
	cin >> n; 
    while (n)
	{
		s = 0;
		if (n % 2 == 0)
			for (i = 1; i <= n / 2; i++)
			{
				if (n % i == 0)
					s+= i;
			}
		else
			for (i = 1; i <= n / 2; i+=2)
				if (n % i == 0)
					s+= i;
		cout<<n;
		if (s == n)
			cout<<"  PERFECT"<<endl;
		if (s > n)
			cout<<"  ABUNDANT"<<endl;
		if (s < n)
			cout<<"  DEFICIENT"<<endl;
		cin >> n;
	}
	cout<<"END OF OUTPUT"<<endl;
}