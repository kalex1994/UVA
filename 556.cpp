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

enum DIRECTION {EAST, NORTH, WEST, SOUTH};

vector<string> maze;
vector< vector<int> > visited;
int n, m, row, col;
DIRECTION current_direction;

void move()
{
	switch(current_direction)
	{
	case EAST:
		if (col + 1 < m && maze[row][col+1] == '0')
		{
			++visited[row][++col];
			if (row + 1 < n && maze[row+1][col] != '1')
				current_direction = SOUTH;
		}
		else
			current_direction = NORTH;
		break;
	case NORTH:
		if (row - 1 >= 0 && maze[row-1][col] == '0')
		{
			++visited[--row][col];
			if (col + 1 < m && maze[row][col+1] != '1')
				current_direction = EAST;
		}
		else
			current_direction = WEST;
		break;
	case WEST:
		if (col - 1 >= 0 && maze[row][col-1] == '0')
		{
			++visited[row][--col];
			if (row - 1 >= 0 && maze[row-1][col] != '1')
				current_direction = NORTH;
		}
		else
			current_direction = SOUTH;
		break;
	case SOUTH:
		if (row + 1 < n && maze[row+1][col] == '0')
		{
			++visited[++row][col];
			if (col - 1 >= 0 && maze[row][col-1] != '1')
				current_direction = WEST;
		}
		else
			current_direction = EAST;
		break;
	}
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	while(cin >> n >> m && (n || m))
	{
		maze.clear();
		visited.assign(n, vector<int>(m, 0) );

		string line;
		for(int i = 0; i < n; ++i)
		{
			cin >> line;
			maze.push_back(line);
		}

		row = n - 1; col = 0;
		current_direction = EAST;

		while(true)
		{
			move();
			if (row == n - 1 && col == 0) break;
		}

		int zero = 0, one = 0, two = 0, three = 0, four = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
			{
				if (visited[i][j] == 0 && maze[i][j] == '0') ++zero;
				if (visited[i][j] == 1) ++one;
				if (visited[i][j] == 2) ++two;
				if (visited[i][j] == 3) ++three;
				if (visited[i][j] == 4) ++four;
			}
		printf("%3d%3d%3d%3d%3d\n",zero,one,two,three,four);
	}
	return 0;
}


