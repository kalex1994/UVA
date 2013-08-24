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

enum SQUARETYPE {WALL, BUMPER, EMPTY};
struct square
{
	SQUARETYPE type;
	int cost;
	int val;

	square() : type(EMPTY), cost(0), val(0) {}
};

int n, m;
square board[60][60];

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	int wallCost, p;
	cin >> n >> m >> wallCost >> p;

	for(int i = 1; i <= n; ++i)
	{
		board[i][1].type = board[i][m].type = WALL;
		board[i][1].cost = board[i][m].cost = wallCost;
	}
	for(int j = 1; j <= m; ++j)
	{
		board[1][j].type = board[n][j].type = WALL;
		board[1][j].cost = board[n][j].cost = wallCost;
	}

	int x,y,cost,val;
	while(p--)
	{
		cin >> x >> y >> val >> cost;
		board[y][x].type = BUMPER;
		board[y][x].val = val;
		board[y][x].cost = cost;
	}

	int dir, life, nx, ny, sum = 0;
	while(cin >> x >> y >> dir >> life)
	{
		int points = 0;
		for(int i = 0; i < life - 1; ++i)
		{
			nx = x + dc[dir];
			ny = y + dr[dir];

			if (board[ny][nx].type == WALL)
			{
				dir = (dir + 3) % 4;
				i += board[ny][nx].cost;
			}
			else if (board[ny][nx].type == BUMPER)
			{
				dir = (dir + 3) % 4;
				i += board[ny][nx].cost;
				points += board[ny][nx].val;
			}
			else
			{
				x = nx;
				y = ny;
			}
		}
		cout << points << endl;
		sum += points;
	}
	cout << sum << endl;
	return 0;
}


