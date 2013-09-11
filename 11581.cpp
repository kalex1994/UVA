#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <iterator>

using namespace std;

int tests;
int grid[3][3];
char ch;

bool isAllZero()
{
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			if (grid[i][j] != 0)
				return false;
	return true;
}

void next()
{
	int temp[3][3];

	temp[0][0] = (grid[0][1] + grid[1][0]) % 2;
	temp[0][1] = (grid[0][0] + grid[0][2] + grid[1][1]) % 2;
	temp[0][2] = (grid[0][1] + grid[1][2]) % 2;
	temp[1][0] = (grid[0][0] + grid[1][1] + grid[2][0]) % 2;
	temp[1][1] = (grid[0][1] + grid[1][0] + grid[1][2] + grid[2][1]) % 2;
	temp[1][2] = (grid[0][2] + grid[1][1] + grid[2][2]) % 2;
	temp[2][0] = (grid[1][0] + grid[2][1]) % 2;
	temp[2][1] = (grid[1][1] + grid[2][0] + grid[2][2]) % 2;
	temp[2][2] = (grid[1][2] + grid[2][1]) % 2;

	memcpy(grid, temp, sizeof(grid));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d:\\in.txt", "r", stdin);
	freopen("d:\\out.txt", "w", stdout);
#endif

	cin >> tests;

	while(tests--)
	{
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
			{
				cin >> ch;
				grid[i][j] = (ch == '1' ? 1 : 0);
			}

		int answer = -1;
		while(!isAllZero())
		{
			next();
			++answer;
		}
		cout << answer << endl;
	}
	return 0;
}