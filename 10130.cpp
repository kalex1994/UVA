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
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
#endif
using namespace std;

const int MAXN = 1010;
const int MAXG = 110;
const int MAXW = 35;
int price[MAXN], weight[MAXN], maxweight[MAXG];
int dp[MAXN][MAXW];
int n, g;

int solve(int pos, int rem_weight)
{
	if (pos == n)
		return dp[pos][rem_weight] = 0;
	if (dp[pos][rem_weight] != -1)
		return dp[pos][rem_weight];
	if (rem_weight - weight[pos] >= 0)
		return dp[pos][rem_weight] = max(price[pos] + solve(pos + 1, rem_weight - weight[pos]), solve(pos + 1, rem_weight));
	else
		return dp[pos][rem_weight] = solve(pos + 1, rem_weight);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;

	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &price[i], &weight[i]);

		for(int i = 0; i <= n; ++i)
			for(int j = 0; j < MAXW; ++j)
				dp[i][j] = -1;

		scanf("%d", &g);
		for(int i = 0; i < g; ++i)
			scanf("%d", &maxweight[i]);

		int ans = 0;
		for(int i = 0; i < g; ++i)
			ans += solve(0, maxweight[i]);

		printf("%d\n", ans);
	}
}

