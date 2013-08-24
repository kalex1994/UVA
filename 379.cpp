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

#define rep(i,n) for(int i = 0; i < (int)n; ++i)

struct square
{
	bool isValid;
	bool hasPeg;
	int number;
};

square board[7][7];

void init()
{
	rep(i,7)
		rep(j,7)
		    board[i][j].isValid = true;

	board[0][0].isValid = board[0][1].isValid = board[0][5].isValid = board[0][6].isValid = false;
	board[1][0].isValid = board[1][1].isValid = board[1][5].isValid = board[1][6].isValid = false;
	board[5][0].isValid = board[5][1].isValid = board[5][5].isValid = board[5][6].isValid = false;
	board[6][0].isValid = board[6][1].isValid = board[6][5].isValid = board[6][6].isValid = false;

	rep(i,7)
		rep(j,7)
		    if (board[i][j].isValid)
				board[i][j].hasPeg = false;

	int num = 1;
	rep(i,7)
		rep(j,7)
		    if (board[i][j].isValid)
				board[i][j].number = num++;

}

pair<int,int> positionOf(int n)
{
	rep(i,7)
		rep(j,7)
		    if(board[i][j].isValid)
				if(board[i][j].number == n)
					return make_pair(i,j);
}

vector< pair<int,int> > listPossibleMoves()
{
	vector< pair<int,int> > moves;
	rep(i,7)
		rep(j,7)
			if (board[i][j].isValid && board[i][j].hasPeg)
			{
				if (i - 1 >= 0 && i - 2 >= 0 && board[i-1][j].isValid && board[i-2][j].isValid && board[i-1][j].hasPeg && !board[i-2][j].hasPeg)
					moves.push_back(make_pair(board[i-2][j].number, board[i][j].number));

				if (i + 1 < 7 && i + 2 < 7 && board[i+1][j].isValid && board[i+2][j].isValid && board[i+1][j].hasPeg && !board[i+2][j].hasPeg)
					moves.push_back(make_pair(board[i+2][j].number, board[i][j].number));

				if (j - 1 >= 0 && j - 2 >= 0 && board[i][j-1].isValid && board[i][j-2].isValid && board[i][j-1].hasPeg && !board[i][j-2].hasPeg)
					moves.push_back(make_pair(board[i][j-2].number, board[i][j].number));

				if (j + 1 < 7 && j + 2 < 7 && board[i][j+1].isValid && board[i][j+2].isValid && board[i][j+1].hasPeg && !board[i][j+2].hasPeg)
					moves.push_back(make_pair(board[i][j+2].number, board[i][j].number));
			}
	sort(moves.begin(), moves.end());
	return moves;
}

void makeMove(int source, int target)
{
	pair<int, int> pos1 = positionOf(source), pos2 = positionOf(target);
	board[pos1.first][pos1.second].hasPeg = false;
	board[pos2.first][pos2.second].hasPeg = true;

	if (pos1.first < pos2.first)
		board[ pos1.first + 1 ][pos1.second].hasPeg = false;
	if (pos1.first > pos2.first)
		board[ pos1.first - 1 ][pos1.second].hasPeg = false;
	if (pos1.second < pos2.second)
		board[pos1.first][ pos1.second + 1 ].hasPeg = false;
	if (pos1.second > pos2.second)
		board[pos1.first][ pos1.second - 1 ].hasPeg = false;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	int tests, peg;

	cout << "HI Q OUTPUT" << endl;
	cin >> tests;
	while(tests--)
	{
		init();
		while(cin >> peg && peg)
		{
			pair<int,int> pos = positionOf(peg);
			board[ pos.first ][ pos.second ].hasPeg = true;
		}

		while(true)
		{
			vector< pair<int,int> > moves = listPossibleMoves();
			if (moves.empty())
				break;

			makeMove(moves.back().second, moves.back().first);
		}

		int sum = 0;
		rep(i,7)
			rep(j,7)
			    if (board[i][j].isValid)
					if (board[i][j].hasPeg)
						sum += board[i][j].number;
		cout << sum << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}


