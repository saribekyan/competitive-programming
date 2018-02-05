// 369 Combinations
#include <iostream>
using namespace std;

void main()
{
	int N, M, i, j, hayt[100], ham[100];
	long long s, s1, s2;
	cin >> N >> M;
	while (M || N)
	{
		cout << N << " things taken " << M << " at a time is ";
		s = 1;
		for (i = 0; i < N - M; i++)
		{
			ham[i] = M + i + 1;
			hayt[i] = i + 1;
		}
		for (i = N - M - 1; i >= 0; i--)
			for (j = N - M - 1; j >= 0; j--)
				if (ham[i] != 0 && hayt[j] != 0 && ham[i] % hayt[j] == 0)
				{
					s*= ham[i] / hayt[j];
					ham[i] = hayt[j] = 0;
				}
		s1 = s2 = 1;
		for (i = 0; i < N - M; i++)
		{
			if (ham[i] != 0)
				s1*= ham[i];
			if (hayt[i] != 0)
				s2*= hayt[i];
		}
		s = (s*s1) / s2;
		cout << s << " exactly."<< endl;
		cin >> N >> M;
	}
}