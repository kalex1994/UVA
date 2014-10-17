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
int dp[MAXN + 1][MAXN + 1];
int pr[MAXN + 1][MAXN + 1];
enum { EQUAL, LEFT, UP };

vector<string> a, b;

void lcs()
{
	for(size_t i = 0; i < a.size(); ++i)
		dp[i][0] = 0;
	for(size_t j = 0; j < b.size(); ++j)
		dp[0][j] = 0;

	for(size_t i = 1; i <= a.size(); ++i)
		for(size_t j = 1; j <= b.size(); ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				pr[i][j] = EQUAL;
			}
			else
			{
				if (dp[i][j - 1] > dp[i - 1][j])
				{
					dp[i][j] = dp[i][j - 1];
					pr[i][j] = LEFT;
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
					pr[i][j] = UP;
				}
			}
		}
}

void print_lcs()
{
	vector<string> v;

	int i = a.size(), j = b.size(); 
	while (i >= 1 && j >= 1)
	{
		if (pr[i][j] == EQUAL)
		{
			v.push_back(a[i - 1]);
			--i; --j;
		}
		else if (pr[i][j] == LEFT)
			--j;
		else
			--i;
	}

	for(auto it = v.rbegin(); it != v.rend(); ++it)
	{
		if (it != v.rbegin())
			cout << ' ';
		cout << *it;
	}
	cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string s;

	while(true)
	{
		a.clear();
		b.clear();
		if (!(cin >> s))
			break;
		while(s != "#")
		{
			a.push_back(s);
			cin >> s;
		}
		cin >> s;
		while(s != "#")
		{
			b.push_back(s);
			cin >> s;
		}

		lcs();
		print_lcs();
	}
}