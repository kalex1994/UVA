#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
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
	string line, token;

	cin >> tests; cin.ignore(100, '\n'); cin.ignore(100, '\n');
	for(int test = 1; test <= tests; ++test)
	{
		printf("Case #%d:\n", test);
		while(getline(cin, line) && !line.empty())
		{
			istringstream iss(line);
			string message;
			int index = 0;
			while(iss >> token)
			{
				if (index < token.length())
				{
					message += token[index];
					++index;
				}
			}
			puts(message.c_str());
		}
		if (test < tests)
			putchar('\n');
	}
}