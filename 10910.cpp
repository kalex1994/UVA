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

const int MAXN = 70;
int subjects, score, min_score;
int dp[MAXN + 1][MAXN + 1];

void init()
{
	for(int i = 0; i <= subjects; ++i)
		for(int j = 0; j <= score; ++j)
			dp[i][j] = 0;
	for(int j = min_score; j <= score; ++j)
		dp[1][j] = 1;
}

int solve()
{
	for(int i = 2; i <= subjects; ++i)
		for(int j = min_score; j <= score; ++j)
			for(int p = min_score; p <= score - (subjects - i - 1) * min_score; ++p)
				if (j - p >= 0)
					dp[i][j] += dp[i - 1][j - p];
	return dp[subjects][score];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;

	cin >> tests;
	while (tests--)
	{
		cin >> subjects >> score >> min_score;
		init();
		cout << solve() << endl;
	}
}