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

const double MAX_LENGTH = 56.0;
const double MAX_WIDTH = 45.0;
const double MAX_DEPTH = 25.0;
const double MAX_SUM = 125.0;
const double MAX_WEIGHT = 7.0;

double length, width, depth, weight;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, allowed = 0;
	cin >> tests;
	while (tests--)
	{
		cin >> length >> width >> depth >> weight;

		if (weight > MAX_WEIGHT)
			cout << 0 << endl;
		else if (length + width + depth > MAX_SUM && (length > MAX_LENGTH || width > MAX_WIDTH || depth > MAX_DEPTH))
			cout << 0 << endl;
		else 
		{
			cout << 1 << endl;
			++allowed;
		}
	}
	cout << allowed << endl;
}

