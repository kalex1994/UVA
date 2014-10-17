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
array<int, MAXN> a, b;
int n1, n2;

int lcs(const array<int, MAXN>& a, int n1, const array<int, MAXN>& b, int n2)
{
	int dp[MAXN + 1][MAXN + 1];
	for(int i = 0; i < n1; ++i)
		dp[i][0] = 0;
	for(int j = 0; j < n2; ++j)
		dp[0][j] = 0;

	for(int i = 1; i <= n1; ++i)
		for(int j = 1; j <= n2; ++j)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	return dp[n1][n2];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int test_case = 1;
	while(scanf("%d%d", &n1, &n2) && (n1 || n2))
	{
		for(int i = 0; i < n1; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < n2; ++i)
			scanf("%d", &b[i]);
		printf("Twin Towers #%d\n", test_case++);
		printf("Number of Tiles : %d\n\n", lcs(a, n1, b, n2));
	}
}