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

const int MAXN = 1000;
int dp[MAXN + 1][MAXN + 1];

int edit_distance(const string& a, const string& b)
{
	for(int i = 0; i <= a.length(); ++i)
		dp[i][0] = i;
	for(int j = 0; j <= b.length(); ++j)
		dp[0][j] = j;

	for(int i = 1; i <= (int)a.length(); ++i)
		for(int j = 1; j <= (int)b.length(); ++j)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	return dp[a.length()][b.length()];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int len1, len2;
	string a, b;
	while(cin >> len1 >> a >> len2 >> b)
		cout << edit_distance(a, b) << endl;
}