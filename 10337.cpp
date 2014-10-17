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

const int MAXHEIGHT = 9;
const int MAXDIST = 1000;
const int CLIMB_COST = 60;
const int HOLD_COST = 30;
const int SINK_COST = 20;
const int INF = numeric_limits<int>::max() / 10;

int dist;
int dp[MAXDIST + 1][MAXHEIGHT + 1];
int w[MAXHEIGHT + 1][MAXDIST];

void init()
{
	for(int i = 0; i < dist; ++i)
		for(int j = 0; j < MAXHEIGHT; ++j)
			dp[i][j] = -1;
}

int solve(int pos, int height)
{
	if (dp[pos][height] > 0)
		return dp[pos][height];

	if (pos == 1)
	{
		if (height == 0)
			return dp[pos][height] = HOLD_COST - w[0][0];
		else if (height == 1)
			return dp[pos][height] = CLIMB_COST - w[0][0]; 
		else
			return dp[pos][height] = INF;
	}

	int cost1 = INF, cost2, cost3 = INF;

	if (height > 0)
		cost1 = CLIMB_COST - w[height - 1][pos - 1] + solve(pos - 1, height - 1);
	cost2 = HOLD_COST - w[height][pos - 1] + solve(pos - 1, height);
	if (height < MAXHEIGHT)
		cost3 = SINK_COST - w[height + 1][pos - 1] + solve(pos - 1, height + 1);

	return dp[pos][height] = min(min(cost1, cost2), cost3);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	cin >> tests;
	while(tests--)
	{
		cin >> dist;
		dist /= 100;
		for (int i = MAXHEIGHT; i >= 0; --i)
			for (int j = 0; j < dist; ++j)
				cin >> w[i][j];

		init();
		cout << solve(dist, 0) << endl << endl;
	}
}