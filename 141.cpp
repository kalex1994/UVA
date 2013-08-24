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

class Board
{
private:
	bool _arr[60][60];
	int _size;

public:
	friend bool operator<(const Board &a, const Board &b);

	Board(int _size)
	{
		this->_size = _size;
		for(int i = 0; i < 60; ++i)
			for(int j = 0; j < 60; ++j)
				_arr[i][j] = false;
	}

	void rotate()
	{
		bool _temp[60][60];
		for(int i = 0; i < 60; ++i)
			for(int j = 0; j < 60; ++j)
				_temp[i][j] = false;

		for(int i = 0; i < _size; ++i)
			for(int j = 0; j < _size; ++j)
				_temp[i][j] = _arr[_size-j-1][i];
		memcpy(_arr,_temp,sizeof(_temp));
	}

	void set(int row, int col)
	{
		_arr[row-1][col-1] = true;
	}

	void clear(int row, int col)
	{
		_arr[row-1][col-1] = false;
	}
};

bool operator<(const Board &a, const Board &b)
{
	for(int i = 0; i < a._size; ++i)
		for(int j = 0; j < a._size; ++j)
			if (a._arr[i][j] < b._arr[i][j]) return true;
			else if (a._arr[i][j] > b._arr[i][j]) return false;
	return false;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	set<Board> patterns;
	int n, row, col, winner;
	char ch;

	while(cin >> n && n)
	{
		patterns.clear();
		Board board(n);
		winner = -1;

		for(int i = 0; i < 2 * n; ++i)
		{
			cin >> row >> col >> ch;

			if (winner != -1) continue;

			if (ch == '+')
				board.set(row,col);
			else
				board.clear(row,col);

			if (patterns.find(board) != patterns.end())
			{
				winner = i;
			    continue;
			}

			Board temp(board);
			for(int j = 0; j < 4; ++j)
			{
				patterns.insert(temp);
				temp.rotate();
			}
		}
		if (winner == -1) cout << "Draw" << endl;
		else if (winner % 2 == 0) printf("Player 2 wins on move %d\n",winner+1);
		else printf("Player 1 wins on move %d\n",winner+1);
	}

	return 0;
}


