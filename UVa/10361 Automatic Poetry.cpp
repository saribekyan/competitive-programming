#include <iostream>
using namespace std;

int main()
{
	int t, l, i, j, k;
	char a[101], b[101], S1[101], S2[101], S3[101], S4[101], S5[101];
	cin >> t;
	cin.getline(a, 101);
	for (l = 0; l < t; l++)
	{
		cin.getline(a, 101);
		cin.getline(b, 101);
		i = 0;
		j = 0;
		while (a[i] != '<')
		{
			S1[j] = a[i];
			i++;
			j++;
		}
		S1[j] = '\0';
		i++;
		j = 0;
		while (a[i] != '>')
		{
			S2[j] = a[i];
			i++;
			j++;
		}
		S2[j] = '\0';
		j = 0;
		i++;
		while (a[i] != '<')
		{
			S3[j] = a[i];
			i++;
			j++;
		}
		S3[j] = '\0';
		j = 0;
		i++;
		while (a[i] != '>')
		{
			S4[j] = a[i];
			j++;
			i++;
		}
		S4[j] = '\0';
		j = 0;
		i++;
		for (k = i; k < strlen(a); k++)
		{
			S5[j] = a[k];
			j++;
		}
		S5[j] = '\0';
		cout << S1 << S2 << S3 << S4 << S5 << endl;
		b[strlen(b) - 3] = '\0';
		cout << b << S4 << S3 << S2 << S5 << endl;
	}
	return 0;
}