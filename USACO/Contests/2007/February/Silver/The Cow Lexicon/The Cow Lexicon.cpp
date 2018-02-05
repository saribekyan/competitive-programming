#include <fstream>
#include <string>
using namespace std;
#define Min(a, b) ((a)<(b)?(a):(b))

int d[310];
int f[310][26];
int put[310][610];
string words[610];
int main()
{
	ifstream fin("lexicon.in");
	ofstream fout("lexicon.out");
	string s;
	int n, m, i, j, k, l;
	fin >> m >> n >> s;
	for (i = 0; i < m; i++)
		fin >> words[i];
	s.insert(s.begin(), '#');
	memset(f, -1, sizeof(f));
	memset(put, -1, sizeof(put));
	for (i = 1; i <= n; i++)
		for (j = i; j >= 1; j--)
			if (f[i][s[j]-'a'] == -1)
				f[i][s[j]-'a'] = j;
	for (i = 1; i <= n; i++)
		for (j = 0; j < m; j++)
		{
			k = i+1;
			l = (int)(words[j].size())-1;
			while (k > 0 && l != -1)
			{
				k = f[k-1][words[j][l]-'a'];
				l--;
			}
			if (l == -1)
				put[i][j] = k;
		}
	for (i = 0; i <= n; i++)
		d[i] = i;
	for (i = 1; i <= n; i++)
		for (j = 0; j < m; j++)
			if (put[i][j] != -1)
				d[i] = Min(d[i], d[put[i][j]-1]+i-put[i][j]+1-((int)(words[j].size())));
	m = n;
	for (i = 0; i <= n; i++)
		m = Min(m, d[i]+n-i);
	fout << m << '\n';
	return 0;
}
