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

const int MAXN = 1010;
int dp[MAXN][MAXN];
char s[MAXN];

int solve(int l, int r)
{
	if (l == r) 
		return dp[l][r] = 0;
	if (l + 1 == r)
	{
		if (s[l] == s[r])
			return dp[l][r] = 0;
		else
			return dp[l][r] = 1;
	}
	if (dp[l][r] != -1)
		return dp[l][r];
	if (s[l] == s[r]) 
		return dp[l][r] = solve(l + 1, r - 1);
	else
		return dp[l][r] = 1 + min(solve(l + 1, r), solve(l, r - 1));
}

void print_solution(int l, int r)
{
	if (l == r) 
		putchar(s[l]);
	else if (l + 1 == r)
	{
		if (s[l] == s[r])
		{
			putchar(s[l]);
			putchar(s[r]);
		} else
		{
			putchar(s[r]);
			putchar(s[l]);
			putchar(s[r]);
		}
	} else if (s[l] == s[r])
	{
		putchar(s[l]);
		print_solution(l + 1, r - 1);
		putchar(s[r]);
	} else
	{
		if (dp[l + 1][r] < dp[l][r - 1])
		{
			putchar(s[l]);
			print_solution(l + 1, r);
			putchar(s[l]);
		} else 
		{ 
			putchar(s[r]);
			print_solution(l, r - 1);
			putchar(s[r]);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(scanf("%s", s) != EOF)
	{
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				dp[i][j] = -1;
		printf("%d ", solve(0, n - 1));
		print_solution(0, n - 1);
		putchar('\n');
	}
}

