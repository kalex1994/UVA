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

const int N = 100;
const int M = 100;
const string directions = "NSLO";
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, 1, -1};

char arena[N][M], command;
int r, c, d, n, m, s, score;

void find_robot()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if ((d = directions.find(arena[i][j])) != string::npos)
			{
				r = i;
				c = j;
				return;
			}
}

void move()
{
	int nr = r + dr[d];
	int nc = c + dc[d];
	if (nr >= 0 && nr < n && nc >= 0 && nc < m && arena[nr][nc] != '#')
	{
		if (arena[nr][nc] == '*')
		{
			arena[nr][nc] = '.';
			++score;
		}
		r = nr; c = nc;
	}
}

void rotate_right()
{
	if (d == 0) d = 2;
	else if (d == 1) d = 3;
	else if (d == 2) d = 1;
	else d = 0;
}

void rotate_left()
{
	if (d == 0) d = 3;
	else if (d == 1) d = 2;
	else if (d == 2) d = 0;
	else d = 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(cin >> n >> m >> s)
	{
		if (n == 0 && m == 0 && s == 0)
			break;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> arena[i][j];
		score = 0;
		find_robot();
		for(int i = 0; i < s; ++i)
		{
			cin >> command;
			if (command == 'D') rotate_right();
			else if (command == 'E') rotate_left();
			else move();
		}
		cout << score << endl;
	}
}