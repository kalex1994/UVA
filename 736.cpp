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
using namespace std;

const int NUM_DIR = 8;
const int DR[NUM_DIR] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int DC[NUM_DIR] = { 0,  1, 1, 1, 0, -1, -1, -1};
const char* DNAME[NUM_DIR] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

const int MAXN = 50;

int n;
char grid[MAXN][MAXN + 1];

int word_length;
char word[MAXN + 1];

inline bool valid(int row, int col)
{
	return row >= 0 && row < n && col >= 0 && col < n;
}

bool can_be_found_in_direction(int row, int col, int direction)
{
	int index = 0;
	while(valid(row, col) && index < word_length)
	{
		if (index == 0 && grid[row][col] != word[index])
			return false;
		if (grid[row][col] != ' ' && grid[row][col] != word[index])
			return false;
		else if (grid[row][col] == word[index] || grid[row][col] == ' ')
		{
			index += grid[row][col] == ' ' ? 0 : 1;
			row += DR[direction];
			col += DC[direction];
		}		
	}
	return index == word_length;
}

bool search()
{
	bool found = false;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < NUM_DIR; ++k)
				if (can_be_found_in_direction(i, j, k))
				{
					found = true;
					printf("(%d,%d) - %s\n", i + 1, j + 1, DNAME[k]);		
				}
	return found;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;

	scanf("%d", &tests);
	while(tests--)
	{
		scanf("%d%*c", &n);
		for(int i = 0; i < n; ++i)
			gets(grid[i]);
		while(gets(word) && word[0] != '\0')
		{
			word_length = strlen(word);
			putchar('\n');
			puts(word);
			if (!search())
				puts("not found");
		}
		if (tests)
			putchar('\n');
	}
}