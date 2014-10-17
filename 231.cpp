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

int LIS(const vector<int>& v)
{
	vector<int> L;
	for(size_t i = 0; i < v.size(); ++i)
	{
		auto it = lower_bound(L.begin(), L.end(), v[i]);
		if (it == L.end())
			L.push_back(v[i]);
		else
			*it = v[i];
	}
	return L.size();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	vector<int> v;
	bool first = true;
	int x, test = 1;

	while(cin >> x && x != -1)
	{
		v.clear();
		v.push_back(-x);
		while(cin >> x && x != -1)
			v.push_back(-x);

		if (first) first = false;
		else putchar('\n');
		printf("Test #%d:\n", test++);
		printf("  maximum possible interceptions: %d\n", LIS(v));
	}
}