#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
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
#include <cfloat>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
#endif
using namespace std;

int cnt[26];
string s;

void dfs(int l, int r)
{
	if (l + 1 == r)
	{
		cnt[s[l] - 'A'] = 1;
		return;
	}

	int c = 0;
	for(int i = l + 1; i < r; ++i)
	{
		for(int j = i + 1; j < r; ++j)
			if (s[j] == s[i])
			{
				dfs(i, j);
				++c;
				i = j;
				break;
			}
	}
	cnt[s[l] - 'A'] = c + (l == 0 ? 0 : 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;

	cin >> tests;
	for(int test = 1; test <= tests; ++test)
	{
		fill(cnt, cnt + 26, 0);
		cin >> s;

		dfs(0, s.length() - 1);

		printf("Case %d\n", test);
		for(int i = 0; i < 26; ++i)
			if (cnt[i] > 0)
				printf("%c = %d\n", i + 'A', cnt[i]);
	}
}