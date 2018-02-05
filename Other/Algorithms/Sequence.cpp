// given the sequence 1121231234...123456789101234567891011...
// find the n_th digit of the sequence
#include <stdio.h>

int main()
{
	int n, m, k, t, d, i;
	while (scanf("%d",  &n)==1)
	{
		k = 1;
		m = 0;
		while (m<n)
		{
			t = k;
			d = 0;
			while (t)
			{
				d++;
				t /= 10;
			}
			for (i = t = 1; i < d; i++, t*=10)
				m += 9*i*t;
			m += (k-t+1)*d;
			k++;
		}
		n = m-n+1;
		i = 1;
		while (n)
		{
			t = i;
			while (t && n)
			{
				n--;
				d = t%10;
				t /= 10;
			}
			i++;
		}
		printf("%d\n", d);
	}
	return 0;
}