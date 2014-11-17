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

const int MAXN = 200;
const int MAXV = 1150;
const int MAXK = 15;
int dp[MAXN][MAXV][MAXK];
vector<int> primes;
int n, k;

bool is_prime(int n)
{
	if (n == 2 || n == 3) return true;
	if (n == 1 || n % 2 == 0) return false;
	for(int i = 3; i <= (int)sqrt(n); i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int solve(int pos, int rem_sum, int k)
{
	if (primes[pos] > n)
	{
		if (rem_sum == 0 && k == 0)
			return dp[pos][rem_sum][k] = 1;
		return 0;
	}
	if (k < 0)
		return 0;
	if (dp[pos][rem_sum][k] != -1)
		return dp[pos][rem_sum][k];
	if (rem_sum - primes[pos] >= 0)
		return dp[pos][rem_sum][k] = solve(pos + 1, rem_sum - primes[pos], k - 1) + solve(pos + 1, rem_sum, k);
	else
		return dp[pos][rem_sum][k] = solve(pos + 1, rem_sum, k);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	for(int a = 0; a < MAXN; ++a)
		for(int b = 0; b < MAXV; ++b)
			for(int c = 0; c < MAXK; ++c)
				dp[a][b][c] = -1;

	for (int i = 2; i < MAXV; ++i)
		if (is_prime(i))
			primes.push_back(i);

	while(scanf("%d%d", &n, &k) && (n || k))
		printf("%d\n", solve(0, n, k));
}