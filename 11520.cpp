#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
using namespace std;

const int dr[] = { -1, 1, 0, 0 };
const int dc[] = { 0, 0, -1, 1 };
vector<string> grid;

bool valid_position(int row, int col)
{
	return row >= 0 && row < (int)grid.size() && col >= 0 && col < (int)grid[0].length();
}

char get_letter(int row, int col)
{
	bool used[26] = { false };

	for (int i = 0; i < 4; ++i)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (valid_position(nr, nc) && grid[nr][nc] != '.')
			used[grid[nr][nc] - 'A'] = true;
	}

	for (int i = 0; i < 26; ++i)
		if (!used[i])
			return i + 'A';
}

void fill_grid()
{
	for (int i = 0; i < (int)grid.size(); ++i)
		for (int j = 0; j < (int)grid[i].length(); ++j)
			if (grid[i][j] == '.')
				grid[i][j] = get_letter(i, j);
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int tests, n;
	string s;

	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		grid.clear();
		cin >> n;
		while (n--)
		{
			cin >> s;
			grid.push_back(s);
		}

		fill_grid();

		printf("Case %d:\n", test);
		for (int i = 0; i < (int)grid.size(); ++i)
			cout << grid[i] << endl;
	}

	return 0;
} 

