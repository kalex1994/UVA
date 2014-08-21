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

const int SIZE = 4;
char board[2][SIZE][SIZE];
set<string> words[2];

inline bool valid(int row, int col)
{
	return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

bool read_input()
{
	string line;
	for(int i = 0; i < 4; ++i)
	{
		getline(cin, line);
		if (line[0] == '#')
			return false;
		for(size_t j = 0; j <= 6; j += 2)
			board[0][i][j / 2] = line[j];
		for(size_t j = 11; j < line.length(); ++j)
			board[1][i][(j - 10) / 2] = line[j];
	}
	getline(cin, line);
	return true;
}

void find_all_word(int board_index, int row, int col, string s, bool visited[SIZE][SIZE])
{
	s += board[board_index][row][col];

	if (s.length() == 4)
	{
		int vowel_count = 0;
		for(char ch : s)
			if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y')
				++vowel_count;
		if (vowel_count == 2)
			words[board_index].insert(s);
		return;
	}

	for(int k = 0; k < NUM_DIR; ++k)
	{
		int new_row = row + DR[k];
		int new_col = col + DC[k];
		
		if (valid(new_row, new_col) && !visited[new_row][new_col])
		{
			visited[new_row][new_col] = true;
			find_all_word(board_index, new_row, new_col, s, visited);
			visited[new_row][new_col] = false;
		}		
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	bool visited[SIZE][SIZE];
	for (int row = 0; row < SIZE; ++row)
		for (int col = 0; col < SIZE; ++col)
			visited[row][col] = false;

	bool first_test = true;
	while(read_input())
	{
		if (first_test) first_test = false;
		else cout << endl;

		words[0].clear();
		words[1].clear();

		for(int k = 0; k < 4; ++k)
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
				{
					visited[i][j] = true;
					find_all_word(k, i, j, "", visited);
					visited[i][j] = false;
				}
		
		string intersection[1000];
		string *endptr = set_intersection(words[0].begin(), words[0].end(), words[1].begin(), words[1].end(), intersection);
		if (endptr == intersection)
			cout << "There are no common words for this pair of boggle boards." << endl;
		else
			for (auto p = intersection; p != endptr; ++p)
				cout << *p << endl;
	}
}