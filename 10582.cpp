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

const int MAXN = 64;
const int NUMBER_OF_DIRECTIONS = 4;
enum Direction {UP, RIGHT, DOWN, LEFT};
const Direction OPPOSITE[] = {DOWN, LEFT, UP, RIGHT};

struct Tile
{
	array<bool, NUMBER_OF_DIRECTIONS> sides;
	int number_of_rotations;

	Tile(int number_of_rotations = 0) : number_of_rotations(number_of_rotations)
	{
		for (int i = 0; i < sides.size(); ++i)
			sides[i] = false;
	}

	void rotate()
	{
		bool temp = sides[UP];
		sides[UP] = sides[LEFT];
		sides[LEFT] = sides[DOWN];
		sides[DOWN] = sides[RIGHT];
		sides[RIGHT] = temp;
	}
};

int n, m;
Tile grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

inline bool valid(int row, int col)
{
	return row >= 0 && row < n && col >= 0 && col < m;
}

void read_testcase()
{
	string line;

	cin >> n >> m >> ws;
	getline(cin, line);

	for(int i = 0; i < n; ++i)
	{
		getline(cin, line);
		getline(cin, line);

		for(int j = 0, col = 1; j < m; ++j, col += 4)
		{
			if (line[col + 2] == '*')
			{
				grid[i][j] = Tile(2);
				grid[i][j].sides[LEFT] = grid[i][j].sides[RIGHT] = true;
			}
			else if (line[col + 1] == '*')
			{
				grid[i][j] = Tile(4);
				grid[i][j].sides[LEFT] = grid[i][j].sides[DOWN] = true;
			}
			else
				grid[i][j] = Tile(0);
		}

		getline(cin, line);
		getline(cin, line);
	}
}

void move(int row, int col, Direction dir, int& nrow, int& ncol)
{
	nrow = row;
	ncol = col;
	switch (dir)
	{
		case UP:
			nrow = row - 1;
			break;
		case RIGHT:
			ncol = col + 1;
			break;
		case DOWN:
			nrow = row + 1;
			break;
		case LEFT:
			ncol = col - 1;
			break;
	}
}

void solve(int row, int col, Direction dir, int& answer)
{
	if (!valid(row, col))
		return;

	if (row + 1 == n && col + 1 == m && grid[row][col].number_of_rotations > 0)
	{
		++answer;
		return;
	}

	visited[row][col] = true;

	for(int r = 0; r < grid[row][col].number_of_rotations; ++r)
	{
		grid[row][col].rotate();

		if (grid[row][col].sides[dir])
			for(int i = 0; i < NUMBER_OF_DIRECTIONS; ++i)
				if (grid[row][col].sides[i] && i != dir)
				{
					int nrow, ncol;
					move(row, col, (Direction)i, nrow, ncol);
					if (valid(nrow, ncol) && !visited[nrow][ncol])
						solve(nrow, ncol, OPPOSITE[i], answer);
				}
	}

	visited[row][col] = false;
}

int solve()
{
	int ans1 = 0, ans2 = 0;
	solve(0, 0, LEFT, ans1);
	solve(0, 0, UP, ans2);
	return ans1 + ans2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	cin >> tests;
	while(tests--)
	{
		read_testcase();
		cout << "Number of solutions: " << solve() << endl;
	}
}