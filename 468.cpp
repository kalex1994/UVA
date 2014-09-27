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
	string a, b;
	int freq1[256], freq2[256];
	vector<pair<int, char>> v1, v2;
	map<char, char> m;

	cin >> tests;
	while(tests--)
	{
		v1.clear(); v2.clear();
		m.clear();
		fill(freq1, freq1 + 256, 0);
		fill(freq2, freq2 + 256, 0);

		cin >> a >> b;
		for(char ch : a)
			++freq1[ch];
		for(char ch : b)
			++freq2[ch];

		for(int i = 0; i < 256; ++i)
		{
			if (freq1[i] != 0)
				v1.push_back(make_pair(freq1[i], (char)i));
			if (freq2[i] != 0)
				v2.push_back(make_pair(freq2[i], (char)i));
		}

		sort(v1.rbegin(), v1.rend());
		sort(v2.rbegin(), v2.rend());
		for(size_t i = 0; i < v1.size(); ++i)
			m[v2[i].second] = v1[i].second;

		for(char ch : b)
			putchar(m[ch]);
		putchar('\n');
		if (tests)
			putchar('\n');
	}	
}