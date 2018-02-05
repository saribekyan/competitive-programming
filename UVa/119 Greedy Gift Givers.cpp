// 119 Greedy Gift Givers
#include <iostream>
#include <string>
using namespace std;
#define MAX 15

struct people
{
	string name;
	int f_money;
	int l_money;
};

int main()
{
	string name;
	people s[MAX];
	int i, k, number_of_people, j, l, n;
	while (cin >> number_of_people)
	{
		for (i = 0; i < number_of_people; i++)
		{
			cin >> s[i].name;
			s[i].f_money = 0;
			s[i].l_money = 0;
		}
		for (j = 0; j < number_of_people; j++)
		{
			cin >> name;
			for (i = 0; i < number_of_people; i++)
				if (s[i].name == name)
					break;
			n = i;
			cin >> s[n].f_money >> k;
			if (k)
			{
				s[n].l_money += s[n].f_money % k;
				for (i = 0; i < k; i++)
				{
					cin >> name;
					for (l = 0; l < number_of_people; l++)
						if (name == s[l].name)
							break;
					s[l].l_money += s[n].f_money / k;
				}
			}
			else
				s[n].l_money += s[n].f_money;
		}
		for (i = 0; i < number_of_people; i++)
			cout << s[i].name << " " << s[i].l_money - s[i].f_money << "\n";
		cout << "\n";
	}
	return 0;
}