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

	int tests;

	cin >> tests;
	while(tests--)
	{
		string name1, name2;
		cin >> name1 >> name2;

		if (name1.length() == name2.length())
		{
			bool same = true;

			for(int i = 0; i < name1.length(); ++i)
			{
				if (is_vowel(name1[i]) && is_vowel(name2[i]))
					continue;
				if (name1[i] != name2[i])
				{
					same = false;
					break;
				}
			}

			if (same)
				puts("Yes");
			else 
				puts("No");
		}
		else
			puts("No");
	}
}