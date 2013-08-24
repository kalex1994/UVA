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

char chessBoard[8][8];

#define valid(row,col) (row) >= 0 && (row) < 8 && (col) >= 0 && (col) < 8

bool readBoard()
{
	string line;
	if (!getline(cin,line)) return false;

	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			chessBoard[i][j] = '.';

	int row = 0, col = 0;
	for(int i = 0; i < (int)line.size(); ++i)
		if (line[i] == '/') 
			++row, col = 0;
		else if (isdigit(line[i])) 			
			col += line[i] - '0';
		else 
			chessBoard[row][col++] = line[i];
	return true;
}

void King(int row, int col)
{
	for(int i = -1; i <= 1; ++i)
		for(int j = -1; j <= 1; ++j)
			if (valid(row+i,col+j))
				if (chessBoard[row+i][col+j] == '.' || chessBoard[row+i][col+j] == '-')
					chessBoard[row+i][col+j] = '-';
}

void Rook(int row, int col)
{
	int dr[] = {+0,+0,+1,-1};
	int dc[] = {+1,-1,+0,+0};

	for(int i = 0; i < 4; ++i)
		for(int k = 1; k < 8; ++k)
			if (valid(row + k * dr[i], col + k * dc[i]))
				if (chessBoard[row + k * dr[i]][col + k * dc[i]] == '.' || chessBoard[row + k * dr[i]][col + k * dc[i]] == '-')
					chessBoard[row + k * dr[i]][col + k * dc[i]] = '-';
				else break;
}

void Bishop(int row, int col)
{
	int dr[] = {+1,-1,+1,-1};
	int dc[] = {+1,-1,-1,+1};

	for(int i = 0; i < 4; ++i)
		for(int k = 1; k < 8; ++k)
			if (valid(row + k * dr[i], col + k * dc[i]))
				if (chessBoard[row + k * dr[i]][col + k * dc[i]] == '.' || chessBoard[row + k * dr[i]][col + k * dc[i]] == '-')
					chessBoard[row + k * dr[i]][col + k * dc[i]] = '-';
				else break;
}

void Knight(int row, int col)
{
	int dr[] = {-2,-2,-1,-1,+1,+1,+2,+2};
	int dc[] = {-1,+1,-2,+2,-2,+2,-1,+1};

	for(int i = 0; i < 8; ++i)
		if (valid(row+dr[i],col+dc[i]))
			if (chessBoard[row+dr[i]][col+dc[i]] == '.' || chessBoard[row+dr[i]][col+dc[i]] == '-')
				chessBoard[row+dr[i]][col+dc[i]] = '-';
}

void Queen(int row, int col)
{
	Rook(row,col);
	Bishop(row,col);
}

void blackPawn(int row, int col)
{
	if (row + 1 < 8)
	{
		if (col - 1 >= 0 && (chessBoard[row+1][col-1] == '.' || chessBoard[row+1][col-1] == '.') )
			chessBoard[row+1][col-1] = '-';
		if (col + 1 < 8 && (chessBoard[row+1][col+1] == '.' || chessBoard[row+1][col+1] == '-') )
			chessBoard[row+1][col+1] = '-';
	}
}

void whitePawn(int row, int col)
{
	if (row - 1 >= 0)
	{
		if (col - 1 >= 0 && (chessBoard[row-1][col-1] == '.' || chessBoard[row-1][col-1] == '-') )
			chessBoard[row-1][col-1] = '-';
		if (col + 1 < 8 && (chessBoard[row-1][col+1] == '.' || chessBoard[row-1][col+1] == '-') )
			chessBoard[row-1][col+1] = '-';
	}
}

int getNumberOfUnoccupiedSquares()
{
	int n = 0;
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			if (chessBoard[i][j] == '.')
				++n;
	return n;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	while(readBoard())
	{
		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j)
			{
				switch(chessBoard[i][j])
				{
				case 'p':
					blackPawn(i,j);
					break;
				case 'P':
					whitePawn(i,j);
					break;
				case 'r':
				case 'R':
					Rook(i,j);
					break;
				case 'b':
				case 'B':
					Bishop(i,j);
					break;
				case 'n':
				case 'N':
					Knight(i,j);
					break;;
				case 'k':
				case 'K':
					King(i,j);
					break;;
				case 'q':
				case 'Q':
					Queen(i,j);
					break;;
				}
			}
		cout << getNumberOfUnoccupiedSquares() << endl;
	}
	return 0;
}


