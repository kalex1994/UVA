#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <list>
#include <sstream>
using namespace std;

void check(string s)
{
	for (size_t i = 0; i < s.length(); ++i)
		if (s[i] >= 'p' && s[i] <= 'z')
			s[i] = 's';

	while (true)
	{
		string temp = "";

		for (size_t i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'N')
			{
				if (i + 1 < s.length() && s[i + 1] == 's')
				{
					temp += 's';
					i += 1;
				}
				else temp += s[i];
			}
			else if (s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'I')
			{
				if (i + 2 < s.length() && s[i + 1] == 's' && s[i + 2] == 's')
				{
					temp += 's';
					i += 2;
				}
				else temp += s[i];
			}
			else temp += s[i];
		}

		if (s == "s")
		{
			cout << "YES" << endl;
			return;
		}
		else if (s == temp)
		{
			cout << "NO" << endl;
			return;
		}

		s = temp;
	}
}

int main()
{
	string s;

	while (cin >> s)
		check(s);

	return 0;
}
