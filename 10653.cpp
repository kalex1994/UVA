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
#include <queue>
#include <map>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
using namespace std;

const int NUM_DIR = 4;
const int DR[NUM_DIR] = {0, 0, -1, 1};
const int DC[NUM_DIR] = {1, -1, 0, 0};
const int MAXN = 1000;
const int MAXM = 1000;
const int MINE = -2;
const int FREE = -1;

int maze[MAXN][MAXM];
int n, m, k, b, row, col, start_row, start_col, end_row, end_col;

#define valid(r, c) ((r) >= 0 && (r) < (n) && (c) >= 0 && (c) < (m))

void bfs()
{
	queue<int> q;
	q.push(start_row);
	q.push(start_col);
	maze[start_row][start_col] = 0;
	
	while(!q.empty())
	{
		int r = q.front(); q.pop();
		int c = q.front(); q.pop();
		if (r == end_row && c == end_col)
			break;

		for(int dir = 0; dir < NUM_DIR; ++dir)
		{
			int nr = r + DR[dir];
			int nc = c + DC[dir];
			if (valid(nr, nc) && maze[nr][nc] == FREE)
			{
				maze[nr][nc] = maze[r][c] + 1;
				q.push(nr);
				q.push(nc);
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(scanf("%d%d", &n, &m) && (n || m))
	{
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				maze[i][j] = FREE;

		scanf("%d", &k);
		while(k--)
		{
			scanf("%d%d", &row, &b);
			while(b--)
			{
				scanf("%d", &col);
				maze[row][col] = MINE;
			}
		}
		scanf("%d%d%d%d", &start_row, &start_col, &end_row, &end_col);
		bfs();
		printf("%d\n", maze[end_row][end_col]);
	}
}