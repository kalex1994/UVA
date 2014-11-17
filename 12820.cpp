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

const int MAXN = 30;
char buffer[MAXN + 5];
int occurence[26];
bool was[26];

bool is_cool()
{
	for(int i = 0; i < 26; ++i)
	{
		occurence[i] = 0;
		was[i] = false;
	}

	int n = strlen(buffer);
	if (n <= 2) return false;

	for(int i = 0; i < n; ++i)
		++occurence[buffer[i] - 'a'];

	for(int i = 0; i < 26; ++i)
		if (occurence[i] != 0)
		{
			if (was[occurence[i]]) 
				return false;
			else 
				was[occurence[i]] = true;
		}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n, test = 1;

	while(scanf("%d", &n) == 1)
	{
		int ans = 0;
		while(n--)
		{
			scanf("%s", buffer);
			if (is_cool())
				++ans;
		}
		printf("Case %d: %d\n", test++, ans);
	}
}