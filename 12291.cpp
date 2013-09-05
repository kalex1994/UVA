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

const int MAX = 15;

char largePolyomino[MAX][MAX], smallPolyomino[MAX][MAX], p1[MAX][MAX], p2[MAX][MAX], combined[MAX][MAX]; 
int N, M;

inline bool valid(int row, int col)
{
	return row >= 0 && row < N && col >= 0 && col < N;
}

bool place(int row, int col, char p[MAX][MAX])
{
	char temp[MAX][MAX];
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			temp[i][j] = '.';

	for(int i = 0; i < M; ++i)
		for(int j = 0; j < M; ++j)
		{
			int nrow = row + i;
			int ncol = col + j;

			if (smallPolyomino[i][j] == '*')
			{	
				if(!valid(nrow, ncol)) return false;
				temp[nrow][ncol] = '*';
			}
		}
	memcpy(p, temp, sizeof(temp));
	return true;
}

bool combine()
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			combined[i][j] = '.';

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if (p1[i][j] == '*' && p2[i][j] == '*')
				return false;
			else if (p1[i][j] == '*' || p2[i][j] == '*')
				combined[i][j] = '*';
	return true;
}

bool equals()
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(largePolyomino[i][j] != combined[i][j])
				return false;
	return true;
}

bool canBeCombined()
{
	for(int i = -M; i < N + M; ++i)
		for(int j = -M; j < N + M; ++j)
			if (place(i, j, p1))
			{
				for(int k = -M; k < N + M; ++k)
					for(int l = -M; l < N + M; ++l)
						if (place(k, l, p2))
							if (combine())
								if (equals())
									return true;
			}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(scanf("%d%d%*c", &N, &M))
	{	
		if (N == 0 && M == 0) break;

		for(int i = 0; i < N; ++i) gets(largePolyomino[i]);
		for(int i = 0; i < M; ++i) gets(smallPolyomino[i]);

		cout << canBeCombined() << endl;
	}
	return 0;
}