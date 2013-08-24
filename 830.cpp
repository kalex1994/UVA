#include<iostream>
#include<cstdio>
#include<cmath>
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

#define valid(row,col) ((row) >= 0 && (row) < N && (col) >= 0 && (col) < M)
enum ANIMAL {SARDINE, MACKEREL, SALMON, GROUPER, TURTLE, DOLPHIN, WHALE, SHARK};
const int d[][2] = 
{
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1},
};

vector<string> grid;
int N, M;
int animalCount[8];
bool visited[70][70];
bool usedDirection[4];
bool canBeShark;

void _isShark(int row, int col, char color)
{
	if(visited[row][col]) return;
	visited[row][col] = true;

	int count = 0;
	for(int i = 0; i < 4; ++i)
	{
		int nrow = row + d[i][0];
		int ncol = col + d[i][1];
		if (valid(nrow,ncol) && grid[nrow][ncol] == color)
		{
			++count;
			usedDirection[i] = true;
			_isShark(nrow,ncol,color);
		}
	}
	if (count == 1) canBeShark = true;
}

bool isShark(int row, int col)
{
	memset(visited,false,sizeof(visited));
	memset(usedDirection,false,sizeof(usedDirection));
	canBeShark = false;

	_isShark(row, col, grid[row][col]);

	int sum = 0;
	for(int i = 0; i < 4; ++i)
		sum += usedDirection[i];
	if (sum <= 2) return false;

	return canBeShark;
}

void FloodFill(int row, int col, char color)
{
	grid[row][col] = '.';
	for(int i = 0; i < 4; ++i)
	{
		int nrow = row + d[i][0];
		int ncol = col + d[i][1];

		if (valid(nrow,ncol) && grid[nrow][ncol] == color)
			FloodFill(nrow,ncol,color);
	}
}

pair<int,int> getParameters(int row, int col)
{
	int width = 0, length = 0;
	char color = grid[row][col];
	for(int j = col; j < M && grid[row][j] == color; ++j) ++width;
	for(int i = row; i < N && grid[i][col] == color; ++i) ++length;
	return make_pair(width,length);
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	int tests;
	string line;

	cin >> tests;
	while(tests--)
	{
		grid.clear();
		memset(animalCount,0,sizeof(animalCount));

		cin >> N >> M;
		for(int i = 0; i < N; ++i)
		{
			cin >> line;
			grid.push_back(line);
		}

		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[i].size(); ++j)
				if (grid[i][j] != '.')
				{
					if (isShark(i,j))
						++animalCount[SHARK];
					else
					{
						pair<int,int> p = getParameters(i,j);
						int width = p.first, length = p.second;

						if ((width == 4 && length > 4) || (width > 4 && length == 4)) ++animalCount[WHALE];
						else if ((width == 3 && length > 3) || (width > 3 && length == 3)) ++ animalCount[DOLPHIN];
						else if ((width == 2 && length > 2) || (width > 2 && length == 2)) ++ animalCount[GROUPER];
						else if (width > 1 && length > 1 && width == length) ++animalCount[TURTLE];
						else if ((width == 1 && length > 2) || (width > 2 && length == 1)) ++animalCount[SALMON];
						else if ((width == 1 && length == 2) || (width == 2 && length == 1)) ++animalCount[MACKEREL];
						else if (width = 1 && length == 1) ++animalCount[SARDINE];
					}
					FloodFill(i,j,grid[i][j]);
				}
		for(int i = 0; i < 8; ++i)
		{
			if (i > 0) cout << " ";
			cout << animalCount[i];
		}
		cout << endl;
		if (tests) cout << endl;
	}
	return 0;
}


