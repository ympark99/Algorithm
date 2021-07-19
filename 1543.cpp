#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int cnt = 0;
	if (s1.size() < s2.size())
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i <= s1.size()-s2.size();)
	{
		bool check = true;
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i + j] != s2[j])
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			cnt++;
			i += s2.size();
		}
		else
			i++;
	}
	cout << cnt << endl;
}
