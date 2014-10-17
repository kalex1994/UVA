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
int dp[MAXN + 1];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	vector<int> squares;
	for(int i = 1; i * i <= MAXN; ++i)
		squares.push_back(i * i);

	for(int square : squares)
		dp[square] = 1;

	for(int i = 1; i <= MAXN; ++i)
	{
		for(int square : squares)
			if (i + square <= MAXN)
				if (dp[i + square] == 0)
					dp[i + square] = 1 + dp[i];
				else
					dp[i + square] = min(dp[i + square], 1 + dp[i]);
	}

	int tests;
	cin >> tests;
	while(tests--)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
}