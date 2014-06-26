#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

bool is_vowel(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	map<string, string> irregulars;
	int l, n;

	cin >> l >> n;

	while(l--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		irregulars[s1] = s2;
	}
	while(n--)
	{
		string s;
		cin >> s;

		if(irregulars.find(s) != irregulars.end())
			cout << irregulars[s] << endl;
		else
		{
			if (s.length() >= 2)
			{
				if (s.length() - s.rfind("ch") == 2 || s.length() - s.rfind("sh") == 2)
				{
					cout << s << "es" << endl;
					continue;
				}
				else if (s.back() == 'y' && !is_vowel(s[s.length() - 2]))
				{
					cout << s.substr(0, s.length() - 1) << "ies" << endl;
					continue;
				}
			}

			if (s.back() == 'o' || s.back() == 's' || s.back() == 'x')
				cout << s << "es" << endl;
			else 
				cout << s << "s" << endl;
		}
	}
}