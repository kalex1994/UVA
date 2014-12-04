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
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
#endif
using namespace std;

void solve(int numerator, int denominator)
{
	vector<int> answer;

	while(denominator != 1)
	{
		answer.push_back(numerator / denominator);
		numerator = numerator % denominator;
		swap(numerator, denominator);
	}
	answer.push_back(numerator);

	putchar('[');
	for(int i = 0; i < answer.size(); ++i)
	{
		if (i > 0)
		{
			if (i == 1) putchar(';');
			else putchar(',');
		}
		printf("%d", answer[i]);
	}
	puts("]");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int numerator, denominator;

	while(scanf("%d%d", &numerator, &denominator) == 2)
		solve(numerator, denominator);
}