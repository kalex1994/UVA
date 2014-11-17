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

const int MAXN = 7;
const int MAXM = 18;
const int start_row[2] = {0, MAXN - 1};
const int end_row[2] = {MAXN - 1, 0};
const int start_col[2] = {0, MAXM / 2 + 1};
const int end_col[2] = {MAXM / 2 - 2, MAXM - 1};
const int diff[2] = {1, -1};
enum class Direction {UP, DOWN};
enum class Side {LEFT, RIGHT};
enum class Positon {TOP, MID, BOTTOM};

char m[MAXN][MAXM];

void move(Direction d, Side s)
{
	int row_ind, col_ind, diff_ind;
	row_ind = d == Direction::UP ? 0 : 1;
	col_ind = s == Side::LEFT ? 0 : 1;
	diff_ind = d == Direction::UP ? 0 : 1;
	
	for(int i = start_row[row_ind]; i != end_row[row_ind]; i += diff[diff_ind])
		for(int j = start_col[col_ind]; j <= end_col[col_ind]; ++j)
			m[i][j] = m[i + diff[diff_ind]][j];
	for(int j = start_col[col_ind]; j <= end_col[col_ind]; ++j)
		m[end_row[row_ind]][j] = '.';
}

void move_to(Side s, Positon current, Positon required)
{
	int k = static_cast<int>(required) - static_cast<int>(current);
	if (k == 0) return;
	switch (k)
	{
		case 2:
			move(Direction::DOWN, s);
			move(Direction::DOWN, s);
			break;
		case 1:
			move(Direction::DOWN, s);
			break;
		case -1:
			move(Direction::UP, s);
			break;
		case -2:
			move(Direction::UP, s);
			move(Direction::UP, s);
			break;
	}
}

void read_testcase()
{
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXM; ++j)
			cin >> m[i][j];
	char ch;
	for(int j = 0; j < MAXM; ++j)
		cin >> ch;
}

int weight_of(char ch)
{
	static int _weight[256] = {0};

	if (_weight[ch] != 0) 
		return _weight[ch];

	int w = 0;
	while(ch)
	{
		if (ch & 1) w += 500;
		else w += 250;
		ch >>= 1;
	}
	return _weight[ch] = w;
}

void get_pan_weights(int& left_weight, int& right_weight)
{
	left_weight = right_weight = 0;
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXM; ++j)
			if (m[i][j] >= 'A' && m[i][j] <= 'Z')
			{
				if (j < MAXM / 2)
					left_weight += weight_of(m[i][j]);
				else
					right_weight += weight_of(m[i][j]);
			}
}

void get_pan_positions(Positon& left_pos, Positon& right_pos)
{
	for(int i = 0; i < MAXN; ++i)
		for(int j = 0; j < MAXM; ++j)
			if (m[i][j] == '_')
			{
				if (j < MAXM / 2)
					left_pos = i == MAXN - 1 ? Positon::BOTTOM : i == MAXN - 2 ? Positon::MID : Positon::TOP;
				else
					right_pos = i == MAXN - 1 ? Positon::BOTTOM : i == MAXN - 2 ? Positon::MID : Positon::TOP;
			}
}

void print()
{
	for(int i = 0; i < MAXN; ++i)
	{
		for(int j = 0; j < MAXM; ++j)
			putchar(m[i][j]);
		putchar('\n');
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, left_weight, right_weight;
	Positon left_pos, right_pos, req_left, req_right;

	cin >> tests;
	for(int test = 1; test <= tests; ++test)
	{
		read_testcase();
		get_pan_weights(left_weight, right_weight);
		get_pan_positions(left_pos, right_pos);

		if (left_weight == right_weight)
		{
			req_left = Positon::MID;
			req_right =  Positon::MID;
		} else if (left_weight < right_weight)
		{
			req_left = Positon::TOP; 
			req_right = Positon::BOTTOM;
		} else
		{
			req_left = Positon::BOTTOM; 
			req_right = Positon::TOP;
		}

		printf("Case %d:\n", test);
		if (left_pos == req_left && right_pos == req_right)
			puts("The figure is correct.");
		else
		{
			move_to(Side::LEFT, left_pos, req_left);
			move_to(Side::RIGHT, right_pos, req_right);
			print();
		}
	}
}