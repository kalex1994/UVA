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

const int MAXR = 105;
const int MAXC = 105;

int r, c;
char sky[MAXR][MAXC];

bool is_star(int i, int j)
{
	for (int a = -1; a <= 1; ++a)
		for (int b = -1; b <= 1; ++b)
			if (a || b)
			{
				int ni = i + a;
				int nj = j + b;
				if (ni >= 0 && ni < r && nj >= 0 && nj < c)
					if (sky[ni][nj] == '*')
						return false;
			}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(cin >> r >> c && (r || c))
	{
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				cin >> sky[i][j];

		int ans = 0;

		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				if (sky[i][j] == '*' && is_star(i, j))
					++ans;

		cout << ans << endl;
	}
}