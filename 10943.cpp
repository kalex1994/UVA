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

const int MAXN = 100;
unsigned long long dp[MAXN + 1][MAXN + 1];
const unsigned long long m = 1000000llu;
int n, k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	for(int i = 1; i <= MAXN; ++i)
		dp[0][i] = dp[i][1] = 1llu;

	for(int i = 1; i <= MAXN; ++i)
		for(int j = 2; j <= MAXN; ++j)
			for(int k = 0; k <= i; ++k)
			{
				dp[i][j] += dp[i - k][j - 1];
				dp[i][j] %= m;
			}

	while(cin >> n >> k && (n || k))
		cout << dp[n][k] << endl;
}