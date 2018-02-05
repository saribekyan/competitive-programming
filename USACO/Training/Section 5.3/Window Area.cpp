/*
PROG: window
LANG: C++
ID: hayk.sa1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

char s[30];
bool t[250];
bool op[500];
int m1[500], m2[500];
struct window
{
	int order;
	int x1, y1;
	int x2, y2;
} windows[250];
struct P
{
	int coord;
	bool open;
	int number;
} x[500], y[500];
bool operator <(P a, P b){return a.coord < b.coord || (a.coord == b.coord && a.open < b.open);}
FILE* fin = fopen("window.in", "r");
FILE* fout = fopen("window.out", "w");
int main()
{
	int n, m, p, w, l, k, c, i, j;
	n = 0;
	m = -1;
	while (fscanf(fin, "%s", s) == 1)
	{
		if (s[0] == 'w')
		{
			t[s[2]] = 1;
			windows[s[2]].order = n++;
			i = 4;
			windows[s[2]].x1 = windows[s[2]].y1 = windows[s[2]].x2 = windows[s[2]].y2 = 0;
			while (s[i] != ',')
				windows[s[2]].x1 = windows[s[2]].x1*10+(s[i++]-'0');
			i++;
			while (s[i] != ',')
				windows[s[2]].y1 = windows[s[2]].y1*10+(s[i++]-'0');
			i++;
			while (s[i] != ',')
				windows[s[2]].x2 = windows[s[2]].x2*10+(s[i++]-'0');
			i++;
			while (s[i] != ')')
				windows[s[2]].y2 = windows[s[2]].y2*10+(s[i++]-'0');
			if (windows[s[2]].x1 > windows[s[2]].x2)
			{
				windows[s[2]].x1 ^= windows[s[2]].x2;
				windows[s[2]].x2 ^= windows[s[2]].x1;
				windows[s[2]].x1 ^= windows[s[2]].x2;
			}
			if (windows[s[2]].y1 > windows[s[2]].y2)
			{
				windows[s[2]].y1 ^= windows[s[2]].y2;
				windows[s[2]].y2 ^= windows[s[2]].y1;
				windows[s[2]].y1 ^= windows[s[2]].y2;
			}
		}
		if (s[0] == 't' && t[s[2]])
			windows[s[2]].order = n++;
		if (s[0] == 'b' && t[s[2]])
			windows[s[2]].order = m--;
		if (s[0] == 'd')
			t[s[2]] = 0;
		if (s[0] == 's')
			if (!t[s[2]])
				fprintf(fout, "0.000\n");
			else
			{
				w = (windows[s[2]].x2-windows[s[2]].x1)*(windows[s[2]].y2-windows[s[2]].y1);
				for (i = 0; i < 250; i++)
					op[i] = 0;
				for (i = p = 0; i < 250; i++)
					if (t[i] && windows[i].order >= windows[s[2]].order)
					{
						x[p].coord = windows[i].x1;
						y[p].coord = windows[i].y1;
						x[p+1].coord = windows[i].x2;
						y[p+1].coord = windows[i].y2;
						x[p].open = y[p].open = 1;
						x[p+1].open = y[p+1].open = 0;
						x[p].number = y[p].number = x[p+1].number = y[p+1].number = p/2;
						if (windows[i].order == windows[s[2]].order)
							k = p/2;
						p += 2;
					}
				sort(x, x+p);
				sort(y, y+p);				
				for (i = 0; i < p-1; i++)
				{
					op[x[i].number] = x[i].open;
					if (!op[k])
						continue;
					c = 0;
					l = 0;
					for (j = 0; j < p; j++)
						if (op[y[j].number] && y[j].number != k)
						{
							if (c == 0)
								m1[l] = y[j].coord;
							if (y[j].open)
								c++;
							else
								c--;
							if (c == 0)
								m2[l++] = y[j].coord;
						}
					for (j = 0; j < l; j++)
					{
						if (m1[j] <= windows[s[2]].y1 && m2[j] >= windows[s[2]].y2)
							w -= (x[i+1].coord-x[i].coord)*(windows[s[2]].y2-windows[s[2]].y1);
						else
							if (m1[j] > windows[s[2]].y1 && m2[j] < windows[s[2]].y2)
								w -= (x[i+1].coord-x[i].coord)*(m2[j]-m1[j]);
							else
								if (m1[j] <= windows[s[2]].y1 && m2[j] >= windows[s[2]].y1)
									w -= (x[i+1].coord-x[i].coord)*(m2[j]-windows[s[2]].y1);
								else
									if (m2[j] >= windows[s[2]].y2 && m1[j] <= windows[s[2]].y2)
										w -= (x[i+1].coord-x[i].coord)*(windows[s[2]].y2-m1[j]);
					}
				}
				fprintf(fout, "%.3lf\n", w*100.0/((windows[s[2]].x2-windows[s[2]].x1)*(windows[s[2]].y2-windows[s[2]].y1)));
			}
	}
	return 0;
}