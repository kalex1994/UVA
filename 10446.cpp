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
#include <unordered_map>
#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
#endif
using namespace std;

typedef unsigned long long ull;
unordered_map<int, unordered_map<int, ull>> dp;

ull solve(int n, int back)
{
	if (n <= 0 || n == 1) return 1llu;
	if (dp.find(n) != dp.end() && dp[n].find(back) != dp[n].end())
		return dp[n][back];
	ull sum = 0llu;
	for(int i = 1; i <= back; ++i)
		sum += solve(n - i, back);
	return dp[n][back] = 1llu + sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n, back, test = 1;
	while(cin >> n >> back)
	{
		if (n > 60) break;
		cout << "Case " << test++<< ": " << solve(n, back) << endl;
		dp.clear();
	}
}

