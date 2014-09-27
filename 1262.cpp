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

vector<char> grid[2][5];
int k;

void read_input()
{
	string s;

	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 5; ++j)
			grid[i][j].clear();

	cin >> k;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 6; ++j)
		{
			cin >> s;
			for(size_t k = 0; k < s.length(); ++k)
				grid[i][k].push_back(s[k]);
		}
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 5; ++j)
			sort(grid[i][j].begin(), grid[i][j].end());
}

vector<int> indexes;
set<string> answer;

void solve(int pos)
{
	if (pos == 5)
	{
		string password;
		for (size_t i = 0; i < indexes.size(); ++i)
			password += grid[0][i][indexes[i]];
		answer.insert(password);
		return;
	}

	for(int j = 0; j < 6; ++j)
	{
		vector<char>& other = grid[1][pos];

		if (find(other.begin(), other.end(), grid[0][pos][j]) != other.end())
		{
			indexes.push_back(j);
			solve(pos + 1);
			indexes.pop_back();
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	
	cin >> tests;
	while (tests--)
	{
		read_input();
		answer.clear();
		solve(0);

		if (k - 1 < (int)answer.size())
		{
			auto it = answer.begin();
			advance(it, k - 1);
			cout << *it << endl;
		}
		else
			cout << "NO" << endl;
	}
}