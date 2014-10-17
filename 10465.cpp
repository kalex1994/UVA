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

const int MAXN = 10000;
int dp[MAXN];
int n, m, t;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(cin >> n >> m >> t)
	{
		fill(dp, dp + t + 1, 0);

		dp[n] = dp[m] = 1;
		for(int i = 1; i < t; ++i)
			if (dp[i] != 0)
			{
				if (i + n < MAXN)
					dp[i + n] = max(dp[i + n], 1 + dp[i]);
				if (i + m < MAXN)
					dp[i + m] = max(dp[i + m], 1 + dp[i]);
			}

		if (dp[t] == 0)
		{
			int temp = t;
			while(temp >= 0 && dp[temp] == 0)
				--temp;
			cout << (temp < 0 ? 0 : dp[temp]) << " " <<  (temp < 0 ? t : t - temp) << endl;
		}
		else
			cout << dp[t] << endl;
	}
}