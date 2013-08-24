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

int tests;
char board[8][8];
char player, opponent;
vector<string> commands;

inline void switchPlayers()
{
	swap(player,opponent);
}

int normalizeDifference(int a, int b)
{
	if (b > a) return 1;
	if (b < a) return -1;
	return 0;
}

bool isBracketed(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2) return false;
	if (board[x2][y2] != player) return false;

	int dr = normalizeDifference(x1,x2);
	int dc = normalizeDifference(y1,y2);
	x1 += dr;
	y1 += dc;
	if (x1 == x2 && y1 == y2) return false;

	while( !(x1 == x2 && y1 == y2 ) )
	{
		if (board[x1][y1] != opponent) return false;
		x1 += dr;
		y1 += dc;
	}
	return true;
}

vector< pair<int,int> > getMoves()
{
	set< pair<int,int> > moves;
	rep(i,8)
		rep(j,8)
		    if (board[i][j] == '-')
			{
				rep(k,8)
					rep(m,8)
					    if(isBracketed(i,j,k,m))
							moves.insert( make_pair(i,j) );
			}
	return vector< pair<int,int> >(moves.begin(),moves.end());
}

void listMoves()
{
	vector< pair<int,int> > moves = getMoves();
	if (moves.empty())
	{
		cout << "No legal move." << endl;
		return;
	}
	rep(i,moves.size())
	{
		if (i > 0) cout << ' ';
		cout << '(' << moves[i].first + 1 << ',' << moves[i].second + 1 << ')';
	}
	cout << endl;
}

void flipBetween(int x1, int y1, int x2, int y2)
{
	int dr = normalizeDifference(x1,x2);
	int dc = normalizeDifference(y1,y2);

	while( !(x1 == x2 && y1 == y2) )
	{
		board[x1][y1] = player;
		x1 += dr;
		y1 += dc;
	}
}

void makeMove(int row, int col)
{
	vector< pair<int,int> > brackets;
	vector< pair<int,int> > moves = getMoves();

	if (find(moves.begin(), moves.end(),make_pair(row,col)) == moves.end())
		switchPlayers();

	rep(i,8)
		rep(j,8)
		    if (isBracketed(row,col,i,j))
				brackets.push_back(make_pair(i,j));

	rep(i,brackets.size())
		flipBetween(row,col,brackets[i].first,brackets[i].second);

	switchPlayers();

	int black = 0, white = 0;
	rep(i,8)
		rep(j,8)
		{
			black += board[i][j] == 'B';
			white += board[i][j] == 'W';
		}
	printf("Black - %2d White - %2d\n",black,white);	
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	cin >> tests;
	while(tests--)
	{
		commands.clear();

		rep(i,8)
			rep(j,8)
			    cin >> board[i][j];
		cin >> player;
		opponent = player == 'W' ? 'B' : 'W';

		string command;
		while(cin >> command && command != "Q")
			commands.push_back(command);


		rep(i,commands.size())
			if (commands[i] == "L")
				listMoves();
			else
				makeMove(commands[i][1] - '0' - 1, commands[i][2] - '0' - 1);

		rep(i,8)
		{
			rep(j,8)
				cout << board[i][j];
			cout << endl;
		}

		if (tests) cout << endl;
	}
	return 0;
}


