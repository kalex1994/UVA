#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <stack>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <numeric>
#include <deque>
#include <map>
#include <iterator>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
#include <array>
#include <regex>
using namespace std;

bool is_subsequence(const string& sub, const string& seq)
{
	int pos = -1;
	for(char ch : sub)
		if ((pos = seq.find(ch, pos + 1)) == string::npos)
			return false;
	return true;
}

bool is_replacement(string a, string b)
{
	if (a.length() == b.length())
	{
		bool flag = false;
		for(size_t i = 0; i < a.length(); ++i)
			if (a[i] != b[i])
			{
				if (flag)
					return false;
				else
					flag = true;			
			}
		return true;
	}
	else if(abs((int)a.length() - (int)b.length()) == 1)
	{
		if (b.length() < a.length())
			swap(a, b);
		return is_subsequence(a, b);
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	vector<string> dict;
	int tests;
	string s;

	cin >> tests;
	while(tests--)
	{
		dict.clear();
		while(cin >> s && s[0] != '#')
			dict.push_back(s);
		while(cin >> s && s[0] != '#')
		{
			if (find(dict.begin(), dict.end(), s) != dict.end())
				printf("%s is correct\n", s.c_str());
			else
			{
				printf("%s:", s.c_str());
				for(const string& w : dict)
					if (is_replacement(s, w))
						printf(" %s", w.c_str());
				putchar('\n');
			}
		}
		if (tests)
			putchar('\n');
	}
}