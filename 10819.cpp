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

const int MAX_MONEY = 15000;
const int MAXN = 105;
int price[MAXN], favour[MAXN];
int money, n;
int dp[MAXN][MAX_MONEY];

const int INF = 1e9;

int solve(int pos, int money_spent)
{
	if (money_spent > money && money < 1800)
		return -INF;
	if (money_spent > money + 200)
		return -INF;
	if (pos == n)
	{
		if (money_spent > money && money_spent <= 2000)
			return -INF;
		return 0;
	}
	if (dp[pos][money_spent] != -1)
		return dp[pos][money_spent];
	return dp[pos][money_spent] = max(favour[pos] + solve(pos + 1, money_spent + price[pos]), solve(pos + 1, money_spent));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(scanf("%d%d", &money, &n) == 2)
	{
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &price[i], &favour[i]);

		for(int i = 0; i <= n; ++i)
			for(int j = 0; j < MAX_MONEY; ++j)
				dp[i][j] = -1;

		printf("%d\n", solve(0, 0));
	}
}

