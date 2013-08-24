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

int grid[8][8];
int king, queen, newqeen;
int dr[] = {+0,+0,-1,+1};
int dc[] = {-1,+1,+0,+0};
#define valid(row,col) ( (row) >= 0 && (row) < 8 && (col) >= 0 && (col) < 8)

void init()
{
	int num = 0;
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			grid[i][j] = num++;
}

pair<int,int> positionOf(int num)
{
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			if (grid[i][j] == num)
				return make_pair(i,j);
}

bool isLegalMove()
{
	pair<int,int> queenPos = positionOf(queen), newQueenPos = positionOf(newqeen), kingPos = positionOf(king);		
	if (queenPos == newQueenPos) return false;
	if (newQueenPos == kingPos) return false;
	if (queenPos.first != newQueenPos.first && queenPos.second != newQueenPos.second) return false;

	if (queenPos.first == kingPos.first)
		if ((queenPos.second < kingPos.second && kingPos.second < newQueenPos.second) ||
			(newQueenPos.second < kingPos.second && kingPos.second < queenPos.second))
			return false;

	if (queenPos.second == kingPos.second)
		if ((queenPos.first < kingPos.first && kingPos.first < newQueenPos.first) ||
			(newQueenPos.first < kingPos.first && kingPos.first < queenPos.first))
			return false;
	return true;
}

bool isAllowedMove()
{
	pair<int,int> kingPos = positionOf(king);
	for(int i = 0; i < 4; ++i)
		if (valid(kingPos.first + dr[i], kingPos.second + dc[i]))
			if(grid[ kingPos.first + dr[i] ][ kingPos.second + dc[i] ] == newqeen)
				return false;
	return true;
}

bool isLocked()
{
	if (king == 0 && newqeen == 9) return true;
	if (king == 7 && newqeen == 14) return true;
	if (king == 56 && newqeen == 49) return true;
	if (king == 63 && newqeen == 54) return true;
	return false;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	init();
	while(cin >> king >> queen >> newqeen)
	{
		if (king == queen)
			cout << "Illegal state" << endl;
		else if (!isLegalMove())
			cout << "Illegal move" << endl;
		else if (!isAllowedMove())
			cout << "Move not allowed" << endl;
		else if (!isLocked())
			cout << "Continue" << endl;
		else 
			cout << "Stop" << endl;
	}
	return 0;
}


