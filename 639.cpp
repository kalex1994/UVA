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
#include <cmath>
#include <set>
using namespace std;

int n;
char board[4][4];

bool is_legal(int row, int col)
{
	for (int r = row; r >= 0 && board[r][col] != 'X'; --r)
		if (board[r][col] == 'o')
			return false;
	for (int r = row; r < n && board[r][col] != 'X'; ++r)
		if (board[r][col] == 'o')
			return false;
	for (int c = col; c >= 0 && board[row][c] != 'X'; --c)
		if (board[row][c] == 'o')
			return false;
	for (int c = col; c < n && board[row][c] != 'X'; ++c)
		if (board[row][c] == 'o')
			return false;
	return true;
}

int max_rooks()
{
	const int LIMIT = (1 << (n * n));
	int answer = -10000;

	for (int mask = 0; mask < LIMIT; ++mask)
	{
		int count = 0;
		for (int i = 0; i < n * n; ++i)
			if (mask & (1 << i))
			{
				int row = i / n;
				int col = i % n;

				if (board[row][col] == '.' && is_legal(row, col))
				{
					board[row][col] = 'o';
					++count;
				}
				else
					break;
			}
		answer = max(answer, count);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (board[i][j] == 'o')
					board[i][j] = '.';
	}
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> board[i][j];
		cout << max_rooks() << endl;
	}
}