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
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
using namespace std;

int n;
vector<int> height, width;

//maximum sum increasing subsequence
int msis()
{	
	vector<int> dp(width);
	for(int i = 1; i < dp.size(); ++i)
		for(int j = 0; j < i; ++j)
			if (height[j] < height[i] && dp[i] < dp[j] + width[i])
				dp[i] = dp[j] + width[i];
	return *max_element(dp.begin(), dp.end());
}

//maximum sum decreasing subsequence
int msds()
{
	vector<int> dp(width);
	for(int i = 1; i < dp.size(); ++i)
		for(int j = 0; j < i; ++j)
			if (height[j] > height[i] && dp[i] < dp[j] + width[i])
				dp[i] = dp[j] + width[i];
	return *max_element(dp.begin(), dp.end());
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
		cin >> n;
		height.resize(n);
		width.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> height[i];
		for(int i = 0; i < n; ++i)
			cin >> width[i];

		int inc = msis(), dec = msds();
		if (inc >= dec)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", test, inc, dec);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", test, dec, inc);
	}
}