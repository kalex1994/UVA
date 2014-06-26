#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <limits>
#include <set>
using namespace std;

const int DR[] = { -1, 1,  0, 0};
const int DC[] = {  0, 0, -1, 1};

int tests, n, m;
vector< vector<int> > maze;
int exit_column;
bool found;

inline bool is_valid(int row, int col)
{
	return row >= 0 && row < n && col >= 0 && col < m;
}

void solve(int row, int col, int current_elem, int max_elem)
{
	if (current_elem == max_elem && row + 1 == n)
	{
		if (!found)
		{
			found = true;
			exit_column = col;
		}
		if (col < exit_column)
			exit_column = col;
		return;
	}

	for(int i = 0; i < 4; ++i)
	{
		int new_row = row + DR[i];
		int new_col = col + DC[i];
		int new_current_elem = current_elem == max_elem ? 1 : current_elem + 1;
		int new_max_elem = current_elem == max_elem ? max_elem + 1 : max_elem;

		if (is_valid(new_row, new_col) && maze[new_row][new_col] == new_current_elem)
		{
			maze[row][col] = 0;
			solve(new_row, new_col, new_current_elem, new_max_elem);
			maze[row][col] = current_elem;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	cin >> tests;
	while(tests--)
	{
		cin >> n >> m;
		maze.assign(n, vector<int>(m));
		found = false;

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> maze[i][j];

		for(int j = 0; j < m; ++j)
			if (maze[0][j] == 1)
			{
				solve(0, j, 1, 1);

				if (found)
				{
					cout << 1 << " " << j + 1 << endl;
					cout << n << " " << exit_column + 1 << endl;
					if (tests) cout << endl;
					break;
				}
			}
	}
}