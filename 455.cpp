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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	string s;

	cin >> tests;
	while(tests--)
	{
		cin >> s;
		bool found = false;
		for (size_t i = 1; i <= s.length() / 2; ++i)
		{
			regex reg("(" + s.substr(0, i) + ")+");
			if (regex_match(s, reg))
			{
				cout << i << endl;
				found = true;
				break;
			}
		}
		if (!found)
			cout << s.length() << endl;
		if (tests)
			cout << endl;
	}
}