#include <cstdio>
#include <vector>
using namespace std;

int d[6][6];
bool side[6];
bool t[6][6][6];
vector<int> rot_up(vector<int> v)
{
	vector<int> s(6);
	s[0] = v[1];
	s[1] = v[2];
	s[2] = v[3];
	s[3] = v[0];
	s[4] = v[4];
	s[5] = v[5];
	return s;
}
vector<int> rot_left(vector<int> v)
{
	vector<int> s(6);
	s[0] = v[5];
	s[1] = v[1];
	s[2] = v[4];
	s[3] = v[3];
	s[4] = v[0];
	s[5] = v[2];
	return s;
}
void dfs(vector<int> v, int p, int q)
{
	int i;
	vector<int> s;
	if (p > 0)
		if (d[p-1][q] && !t[p-1][q][v[3]])
		{
			t[p-1][q][v[3]] = side[v[3]] = 1;
			s = rot_up(v);
			dfs(s, p-1, q);
		}
	if (p < 5)
		if (d[p+1][q] && !t[p+1][q][v[1]])
		{
			t[p+1][q][v[1]] = side[v[1]] = 1;
			s = rot_up(v);
			s = rot_up(s);
			s = rot_up(s);
			dfs(s, p+1, q);
		}
	if (q > 0)
		if (d[p][q-1] && !t[p][q-1][v[4]])
		{
			t[p][q-1][v[4]] = side[v[4]] = 1;
			s = rot_left(v);
			dfs(s, p, q-1);
		}
	if (q < 5)
		if (d[p][q+1] && !t[p][q+1][v[5]])
		{
			t[p][q+1][v[5]] = side[v[5]] = 1;
			s = rot_left(v);
			s = rot_left(s);
			s = rot_left(s);
			dfs(s, p, q+1);
		}
}
int main()
{
	int T, i, j, k;
	vector<int> v(6);
	scanf("%d", &T);
	while (T)
	{
		for (i = 0; i < 6; i++)
			for (j = 0; j < 6; j++)
				scanf("%d", d[i]+j);
		for (i = 0; i < 6; i++)
			for (j = 0; j < 6; j++)
				if (d[i][j])
					goto there;
there:;
		for (k = 0; k < 6; k++)
			v[k] = k;
		memset(t, 0, sizeof(t));
		memset(side, 0, sizeof(side));
		t[i][j][2] = side[2] = 1;
		dfs(v, i, j);
		for (i = 0; i < 6 && side[i]; i++);
		if (i == 6)
			printf("correct\n");
		else
			printf("incorrect\n");
		T--;
		if (T)
			putchar('\n');
	}
	return 0;
}
