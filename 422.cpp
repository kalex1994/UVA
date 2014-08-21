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
#include <list>
#include <functional>
using namespace std;

const int NUM_DIR = 8;
const int dr[NUM_DIR] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dc[NUM_DIR] = {-1, -1, -1, 0, 0, 1, 1, 1};

const int MAX_SIZE = 100;
int n;
char matrix[MAX_SIZE][MAX_SIZE];

string pattern;
int sr, sc, er, ec;

inline bool valid(int row, int col)
{
	return row >= 0 && row < n && col >= 0 && col < n;
}

bool find_pattern()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if (pattern[0] == matrix[i][j])
				for(int k = 0; k < NUM_DIR; ++k)
				{
					int row = i, col = j; 
					bool matches = true;
					for(size_t p = 1; p < pattern.length(); ++p)
					{
						row += dr[k];
						col += dc[k];
						if (!valid(row, col) || matrix[row][col] != pattern[p])
						{
							matches = false;
							break;
						}
					}
					if (matches)
					{
						sr = i; sc = j; er = row; ec = col;
						return true;
					}
				}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> matrix[i][j];
	while(cin >> pattern && pattern != "0")
	{
		if (find_pattern())
			printf("%d,%d %d,%d\n", sr + 1, sc + 1, er + 1, ec + 1);
		else
			puts("Not found");
	}
}