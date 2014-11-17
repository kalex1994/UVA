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

const int INF = -1e9;
const int MAXROW = 1000;
const int MAXCOL = 18500;

string spreadsheet[MAXROW][MAXCOL];
int dp[MAXROW][MAXCOL];
int rows, cols;

vector<string> split(string s)
{
	for(char& ch : s)
		if (ch == '=' || ch == '+')
			ch = ' ';
	istringstream iss(s);
	vector<string> tokens;
	string token;
	while(iss >> token)
		tokens.push_back(token);
	return tokens;
}

pair<int, int> get_coordinates(const string& s)
{
	int row = 0, col = 0;
	for(char ch : s)
	{
		if(ch >= 'A' && ch <= 'Z')
			col = 26 * col + ch - 'A' + 1;
		else
			row = 10 * row + ch - '0';
	}
	return make_pair(row - 1, col - 1);
}

int solve(int row, int col)
{
	if (dp[row][col] != INF)
		return dp[row][col];

	if (isdigit(spreadsheet[row][col][0]))
		return dp[row][col] = stoi(spreadsheet[row][col]);

	vector<string> tokens = split(spreadsheet[row][col]);
	int ans = 0;
	for(const string& token : tokens)
	{
		auto pos = get_coordinates(token);
		ans += solve(pos.first, pos.second);
	}
	return dp[row][col] = ans;
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
		cin >> cols >> rows;
		for(int i = 0; i < rows; ++i)
			for(int j = 0; j < cols; ++j)
			{
				dp[i][j] = INF;
				cin >> spreadsheet[i][j];
			}

		for(int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j)
			{
				if (j > 0) putchar(' ');
				printf("%d", solve(i, j));
			}
			putchar('\n');
		}
	}
}

