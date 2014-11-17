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

const int MAXR = 20;
const int MAXC = 20;
const int DR[] = {1, -1, 0, 0};
const int DC[] = {0, 0, 1, -1};

int rows, cols;
char land[MAXR][MAXC], initial[MAXR][MAXC];
char chars[2];
int mr, mc;

int floodfill(int r, int c, char oldcolor, char newcolor)
{
	if (r < 0 || r >= rows) return 0;

	if (c == -1)  c = cols - 1;
	else if (c == cols) c = 0;

	if (land[r][c] != oldcolor)
		return 0;

	land[r][c] = newcolor;
	int answer = 1;
	for(int i = 0; i < 4; ++i)
		answer += floodfill(r + DR[i], c + DC[i], oldcolor, newcolor);
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(cin >> rows >> cols)
	{
		chars[0] = chars[1] = '\0';
		for(int i = 0; i < rows; ++i)
			for(int j = 0; j < cols; ++j)
			{
				cin >> initial[i][j];
				if (chars[0] == '\0') chars[0] = initial[i][j];
				else if (chars[1] == '\0' && initial[i][j] != chars[0]) chars[1] = initial[i][j];
			}
		cin >> mr >> mc;

		char l = initial[mr][mc];
		char w = l == chars[0] ? chars[1] : chars[0];

		int answer = 0;
		if (w != '\0' && l != '\0')
		{
			for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				land[i][j] = initial[i][j];
			floodfill(mr, mc, l, w);

			for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
			if (land[i][j] == l)
				answer = max(answer, floodfill(i, j, l, w));
		}
		cout << answer << endl;
	}
}