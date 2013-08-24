#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<limits>
#include<sstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<list>
#include<iomanip>
#include<queue>

using namespace std;

int N,M;
int grid[20][50];
vector< pair<int,int> > commands;

bool valid(int row, int col)
{
	if (row < 0 || row >= N || col < 0 || col >= M) return false;
	if (grid[row][col] == -1) return false;

	int color = grid[row][col];
	if (row - 1 >= 0) if (grid[row - 1][col] == color) return true;
	if (row + 1 < N) if (grid[row + 1][col] == color) return true;
	if (col - 1 >= 0) if (grid[row][col - 1] == color) return true;
	if (col + 1 < M) if (grid[row][col + 1] == color) return true;
	return false;
}

void floodFill(int row, int col, int color)
{
	grid[row][col] = -1;
	if (row - 1 >= 0 && grid[row - 1][col] == color) floodFill(row - 1, col, color);
	if (row + 1 < N && grid[row + 1][col] == color) floodFill(row + 1, col, color);
	if (col - 1 >= 0 && grid[row][col - 1] == color) floodFill(row,col - 1, color);
	if (col + 1 < M && grid[row][col + 1] == color) floodFill(row, col + 1, color);
}

void removeRows()
{
	for(int j = 0; j < M; ++j)
		for(int i = 0; i < N; ++i)
			if (grid[i][j] != -1)
			{
				int k = i;
				while(k - 1 >= 0 && grid[k-1][j] == -1)
				{
					swap(grid[k-1][j],grid[k][j]);
					--k;
				}
			}
}

bool isEmptyColumn(int j)
{
	for(int i = 0; i < N; ++i)
		if (grid[i][j] != -1) return false;
	return true;
}

void removeCols()
{
	for(int j = 0; j < M; ++j)
	{
		if (!isEmptyColumn(j))
		{
			int k = j;
			while(k - 1 >= 0 && isEmptyColumn(k-1))
			{
				for(int i = 0; i < N; ++i)
					swap(grid[i][k],grid[i][k-1]);
				--k;
			}
		}
	}
}

bool isWonGame()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (grid[i][j] != -1) return false;
	return true;
}

void ReverseGrid()
{
	for(int j = 0; j < M; ++j)
		for(int i = 0, k = N - 1; i < k; ++i, --k)
			swap(grid[i][j],grid[k][j]);
}

void printGrid()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if (j == 0) cout << "    ";
			if(grid[i][j] == -1) cout << "  ";
			else cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	int gridCount = 1;
	bool isFirst = true;

	while(cin >> N >> M, N)
	{
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				cin >> grid[i][j];

		int r, c;
		commands.clear();
		while(cin >> r >> c && (r || c) )
			commands.push_back(make_pair(r,c));

		bool hasWinner = false;
		for(int i = 0; i < commands.size(); ++i)
			if (valid(commands[i].first - 1, commands[i].second - 1))
			{
				floodFill(commands[i].first - 1, commands[i].second - 1, grid[commands[i].first - 1][commands[i].second - 1]);
				removeRows();
				removeCols();
				if (isWonGame())
				{
					hasWinner = true;
					break;
				}
			}

		if (isFirst) isFirst = false;
		else cout << endl;
		printf("Grid %d.\n",gridCount++);
		if (hasWinner)
			cout << "    Game Won" << endl;
		else
		{
			ReverseGrid();
			printGrid();
		}
	}
	return 0;
}


