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

const int MAXN = 100;
int matrix[MAXN + 1][MAXN + 1];
int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			cin >> matrix[i][j];
			matrix[i][j] += matrix[i - 1][j];
			matrix[i][j] += matrix[i][j - 1];
			matrix[i][j] -= matrix[i - 1][j - 1];
		}

	int sum = MAXN * MAXN * -127;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = i; k <= n; ++k)
				for(int m = j; m <= n; ++m)
				{
					int s = matrix[k][m] - matrix[i - 1][m] - matrix[k][j - 1] + matrix[i - 1][j - 1];
					sum = max(sum, s);
				}

	cout << sum << endl;
}