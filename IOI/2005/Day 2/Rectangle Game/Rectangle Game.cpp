#include "creclib.h"

int main()
{
	int n, m, t, x;
	while (1)
	{
		m = dimension_x();
		n = dimension_y();
		if (m >= n)
		{
			x = 0;
			t = (m+2+n)/(n+1)-1;
			while (t)
			{
				x++;
				t >>= 1;
			}
			cut(vertical, (n+1)*(1<<(x-1))-1);
		}
		else
		{
			x = 0;
			t = (n+2+m)/(m+1);
			while (t)
			{
				x++;
				t >>= 1;
			}
			cut(horizontal, (m+1)*((1<<(x-1))-1));
		}
	}
	return 0;
}
