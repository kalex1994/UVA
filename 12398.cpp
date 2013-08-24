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

int puzzle[3][3];

void inc(char ch)
{
	int dr[] = {-1,+1,+0,+0};
	int dc[] = {+0,+0,-1,+1};
	int row, col;

	switch(ch)
	{
	case 'a':
		row = 0;
		col = 0;
		break;
	case 'b':
		row = 0;
		col = 1;
		break;
	case 'c':
		row = 0;
		col = 2;
		break;
	case 'd':
		row = 1;
		col = 0;
		break;
	case 'e':
		row = 1;
		col = 1;
		break;
	case 'f':
		row = 1;
		col = 2;
		break;
	case 'g':
		row = 2;
		col = 0;
		break;
	case 'h':
		row = 2;
		col = 1;
		break;
	case 'i':
		row = 2;
		col = 2;
		break;
	}

	puzzle[row][col] = ( puzzle[row][col] + 1 ) % 10;
	for(int k = 0; k < 4; ++k)
	{
		int nrow = row + dr[k];
		int ncol = col + dc[k];
		if (nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 3)
			puzzle[nrow][ncol] = ( puzzle[nrow][ncol] + 1 ) % 10;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int caseNumber = 1;
	string line;

	while(getline(cin, line))
	{
		memset(puzzle, 0, sizeof(puzzle));

		reverse(line.begin(), line.end());
		for(int i = 0; i < (int)line.size(); ++i)
			inc(line[i]);

		printf("Case #%d:\n", caseNumber++);
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				if (j > 0) cout << " ";
				cout << puzzle[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
