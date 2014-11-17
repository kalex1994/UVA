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

int solve(int left, int right, int a, int b)
{
	if (left + 1 == right)
		return 1;

	int mid = (left + right) / 2;
	int n = right - left + 1;

	if ((a <= mid && b > mid) || (a > mid && b <= mid))
		return static_cast<int>(log(n) / log(2.0));
	else if (a <= mid)
		return solve(left, mid, a, b);
	else
		return solve(mid, right, a, b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n, i, j;

	while(cin >> n >> i >> j)
		cout << solve(1, 1 << n, i, j) << endl;
}

