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

using namespace std;

int N;
int matrix[110][110];
int startRow, startCol, endRow, endCol, ring;

void leftRightFlip()
{
	for(int i = startRow; i <= endRow; ++i)
	{
		if (i == startRow || i == endRow)
		{
			for(int left = startCol, right = endCol; left < right; ++left, --right)
				swap(matrix[i][left], matrix[i][right]);
		}
		else swap(matrix[i][startCol], matrix[i][endCol]);
	}
}

void upsideDownFlip()
{
	for(int j = startCol; j <= endCol; ++j)
	{
		if (j == startCol || j == endCol)
		{
			for(int upper = startRow, lower = endRow; upper < lower; ++upper, --lower)
				swap(matrix[upper][j], matrix[lower][j]);
		}
		else swap(matrix[startRow][j], matrix[endRow][j]);
	}
}

void mainDiagonalFlip()
{
	for(int k = 1; k < endRow - startRow; ++k)
	{
		swap(matrix[startRow][startCol + k], matrix[startRow + k][startCol]);
		swap(matrix[endRow][endRow - k], matrix[endRow - k][endCol]);
	}
	swap(matrix[endRow][startCol], matrix[startRow][endCol]);
}

void inverseDiagonalFlip()
{
	for(int k = 1; k < endRow - startRow; ++k)
	{
		swap(matrix[startRow][startCol + k], matrix[endRow - k][endCol]);
		swap(matrix[startRow + k][startCol], matrix[endRow][endCol - k]);
	}
	swap(matrix[startRow][startCol], matrix[endRow][endCol]);
}

void printMatrix()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if (j > 0) cout << " ";
			cout <<matrix[i][j];
		}
		cout << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;
	
	cin >> tests;
	while(tests--)
	{
		cin >> N;

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				cin >> matrix[i][j];

		int moves, move;
		for(int i = 0; i < N / 2 + (N & 1); ++i)
		{
			startRow = startCol = i;
			endRow = endCol = N - i - 1;

			cin >> moves;
			while(moves--)
			{
				cin >> move;
				switch(move)
				{
				case 1:
					upsideDownFlip();
					break;
				case 2:
					leftRightFlip();
					break;
				case 3:
					mainDiagonalFlip();
					break;
				case 4:
					inverseDiagonalFlip();
				}
			}
		}
		printMatrix();
	}
	return 0;
}
