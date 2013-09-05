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
#include<cfloat>
#include<climits>

using namespace std;

const int MAX = 100;
const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};

int N, R, C, battles;
int kingdom[MAX][MAX];

inline int isValid(int row, int col)
{
	return row >= 0 && row < R && col >= 0 && col < C;
}

void print()
{
	for(int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
		{
			if (j > 0) cout << " ";
			cout << kingdom[i][j];
		}
		cout << endl;
	}
}

void battle()
{
	int temp[MAX][MAX];
	memcpy(temp, kingdom, sizeof(temp));

	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			for(int k = 0; k < 4; ++k)
			{
				int ni = i + dr[k];
				int nj = j + dc[k];

				if (isValid(ni, nj))
				{
					if ( kingdom[ni][nj] == (kingdom[i][j] + 1) % N )
						temp[ni][nj] = kingdom[i][j];
				}
			}

	memcpy(kingdom, temp, sizeof(temp));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> N >> R >> C >> battles)
	{
		if (N == 0 && R == 0 && C == 0 && battles == 0)
			break;

		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
				cin >> kingdom[i][j];

		for(int i = 0; i < battles; ++i)
			battle();

		print();
	}
	return 0;
}