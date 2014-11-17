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

const int MAXM = 25;
int amount[MAXM], price[MAXM];
int dp[500];
int dollar, cent, m, need;
string line;

int solve()
{
	for(int i = 0; i < 500; ++i)
		dp[i] = INT_MAX;
	dp[0] = 0;
	dp[1] = price[0];

	int max_index = INT_MIN;
	for(int i = 0; i <= need; ++i)
		for(int j = 0; j <= m; ++j)
		{
			max_index = max(max_index, i + amount[j]);
			dp[i + amount[j]] = min(dp[i + amount[j]], dp[i] + price[j]);
		}

	int ans = INT_MAX;
	for(int i = max_index; i >= need; --i)
		ans = min(ans, dp[i]);
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int test = 1;
	while(scanf("%d.%d %d", &dollar, &cent, &m) == 3)
	{
		amount[0] = 1; price[0] = dollar * 100 + cent;
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d %d.%d", &amount[i], &dollar, &cent);
			price[i] = dollar * 100 + cent;
		}

		cin >> ws;
		getline(cin, line);
		istringstream iss(line);

		printf("Case %d:\n", test++);
		while(iss >> need)
		{
			int money = solve();
			printf("Buy %d for $%d.%02d\n", need, money / 100, money % 100);
		}
	}
}

