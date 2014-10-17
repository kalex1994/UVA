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

const int MAXN = 26;
const int MAXSUM = MAXN * (MAXN + 1) / 2;
int dp[MAXN + 1][MAXSUM + 1];

void solve(int len, char last, int val)
{
	if (last != '\0')
		++dp[len][val];
	if (last == 'z')
		return;
	for(char ch = last == '\0' ? 'a' : last + 1; ch <= 'z'; ++ch)
		solve(len + 1, ch, val + ch - 'a' + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	solve(0, '\0', 0);

	int l, s, ans, test = 1;
	while(cin >> l >> s && (l || s))
	{
		if (l > MAXN || s > MAXSUM)
			ans = 0;
		else
			ans = dp[l][s];
		printf("Case %d: %d\n", test++, ans);
	}
}