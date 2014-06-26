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
#include <set>
using namespace std;

struct string_compare
{
	bool operator()(const string& lhs, const string& rhs) const
	{
		if (lhs.length() != rhs.length())
			return lhs.length() < rhs.length();
		return lhs < rhs;
	}
};

const int MAX_N = 20;
const int DR[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int DC[] = {-1,  0,  1, -1, 1, -1, 0, 1};

string matrix[MAX_N];
bool visited[MAX_N][MAX_N];
char buffer[MAX_N * MAX_N + 1];
set<string, string_compare> solution;
int n;
int tests;

inline bool is_valid(int row, int col)
{
	return row >= 0 && row < n && col >= 0 && col < n;
}

void solve(int row, int col, int index)
{
	visited[row][col] = true;
	buffer[index] = matrix[row][col];

	if (index >= 2)
	{
		buffer[index + 1] = '\0';
		solution.insert(buffer);
	}

	for(int i = 0; i < 8; ++i)
	{
		int new_row = row + DR[i];
		int new_col = col + DC[i];

		if (is_valid(new_row, new_col) && !visited[new_row][new_col] && matrix[new_row][new_col] > matrix[row][col])
			solve(new_row, new_col, index + 1);	
	}

	visited[row][col] = false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	for(int i = 0; i < MAX_N; ++i)
		for(int j = 0; j < MAX_N; ++j)
			visited[i][j] = false;

	cin >> tests;
	while(tests--)
	{
		solution.clear();

		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> matrix[i];

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				solve(i, j, 0);

		for(set<string, string_compare>::iterator it = solution.begin(); it != solution.end(); ++it)
			cout << *it << endl;
		if (tests) cout << endl;
	}
}