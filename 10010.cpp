#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#include <list>
#include <functional>
using namespace std;

const int NUM_DIR = 8;
const int DR[NUM_DIR] = {-1, -1, -1, 0,  0,  1, 1, 1};
const int DC[NUM_DIR] = {-1,  0,  1, -1, 1, -1, 0, 1};

const int MAX_SIZE = 50;
int n, m, k;
char grid[MAX_SIZE][MAX_SIZE];
string word;

inline bool valid(int row, int col)
{
	return row >= 0 && row < n && col >= 0 && col < m;
}

pair<int, int> find_word()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if (word[0] == grid[i][j])
				for(int k = 0; k < NUM_DIR; ++k)
				{
					int row = i, col = j;
					bool matches = true;

					for(size_t pos = 1; pos < word.length() && matches; ++pos)
					{
						row += DR[k];
						col += DC[k];
						if (word[pos] != grid[row][col] || !valid(row, col))
							matches = false;
					}
					if (matches)
						return make_pair(i + 1, j + 1);
				}
	assert(false);
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
		cin >> n >> m;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
			{
				cin >> grid[i][j];
				grid[i][j] = tolower(grid[i][j]);
			}
		cin >> k;
		for(int i = 0; i < k; ++i)
		{
			cin >> word;
			for(char& ch : word)
				ch = tolower(ch);

			pair<int, int> pos = find_word();
			cout << pos.first << " " << pos.second << endl;
		}
		if (tests)
			cout << endl;
	}
}