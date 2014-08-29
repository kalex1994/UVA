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

	bool square[10000 + 1] = {false};
	for(int i = 0; i <= 100; ++i)
		square[i * i] = true;

	int tests;
	string line;

	cin >> tests; cin.ignore(100, '\n');
	while(tests--)
	{
		getline(cin, line);
		if (!square[line.length()])
			puts("INVALID");
		else
		{
			int k = (int)sqrt(line.length());
			for(size_t i = 0; i < k; ++i)
				for(size_t j = i; j < line.length(); j += k)
					putchar(line[j]);
			putchar('\n');
		}
	}
}