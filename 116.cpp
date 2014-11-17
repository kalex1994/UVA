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

const int MAXROWS = 15;
const int MAXCOLS = 105;
int cost[MAXROWS][MAXCOLS], dp[MAXROWS][MAXCOLS], child[MAXROWS][MAXCOLS];
int nrows, ncols;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(scanf("%d%d", &nrows, &ncols) == 2)
	{
		for (int i = 0; i < nrows; ++i)
			for (int j = 0; j < ncols; ++j)
				scanf("%d", &cost[i][j]);
		
		for(int i = 0; i < nrows; ++i)
			dp[i][ncols - 1] = cost[i][ncols - 1];

		for(int j = ncols - 2; j >=  0; --j)
			for(int i = 0; i < nrows; ++i)
			{
				int up = (i - 1 + nrows) % nrows, down = (i + 1) % nrows;

				dp[i][j] = cost[i][j] + dp[up][j + 1];
				child[i][j] = up;

				if (cost[i][j] + dp[i][j + 1] < dp[i][j] || (cost[i][j] + dp[i][j + 1] == dp[i][j] && child[i][j] > i))
					dp[i][j] = cost[i][j] + dp[i][j + 1], child[i][j] = i;

				if (cost[i][j] + dp[down][j + 1] < dp[i][j] || (cost[i][j] + dp[down][j + 1] == dp[i][j] && child[i][j] > down))
					dp[i][j] = cost[i][j] + dp[down][j + 1], child[i][j] = down;
			}

		int minrow = 0;
		for(int i = 1; i < nrows; ++i)
			if (dp[i][0] < dp[minrow][0])
				minrow = i;

		int row = minrow;
		for(int j = 0; j < ncols; ++j)
		{
			if (j > 0) putchar(' ');
			printf("%d", row + 1);
			row = child[row][j];
		}
		printf("\n%d\n", dp[minrow][0]);	
	}
}

