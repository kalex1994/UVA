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

enum FONT {C1, C5};

const string fontC5[5][27] =
{
	{".***..", "****..", ".****.", "****..", "*****.", "*****.", ".****.", "*...*.", "*****.", "..***.", "*...*.", "*.....", "*...*.", "*...*.", ".***..", "****..", ".***..", "****..", ".****.", "*****.", "*...*.", "*...*.", "*...*.", "*...*.", "*...*.", "*****.", "......"},
	{"*...*.", "*...*.", "*...*.", "*...*.", "*.....", "*.....", "*.....", "*...*.", "..*...", "...*..", "*..*..", "*.....", "**.**.", "**..*.", "*...*.", "*...*.", "*...*.", "*...*.", "*.....", "*.*.*.", "*...*.", "*...*.", "*...*.", ".*.*..", ".*.*..", "...*..", "......"},
	{"*****.", "****..", "*.....", "*...*.", "***...", "***...", "*..**.", "*****.", "..*...", "...*..", "***...", "*.....", "*.*.*.", "*.*.*.", "*...*.", "****..", "*...*.", "****..", ".***..", "..*...", "*...*.", ".*.*..", "*.*.*.", "..*...", "..*...", "..*...", "......"},
	{"*...*.", "*...*.", "*.....", "*...*.", "*.....", "*.....", "*...*.", "*...*.", "..*...", "*..*..", "*..*..", "*.....", "*...*.", "*..**.", "*...*.", "*.....", "*..**.", "*..*..", "....*.", "..*...", "*...*.", ".*.*..", "**.**.", ".*.*..", "..*...", ".*....", "......"},
	{"*...*.", "****..", ".****.", "****..", "*****.", "*.....", ".***..", "*...*.", "*****.", ".**...", "*...*.", "*****.", "*...*.", "*...*.", ".***..", "*.....", ".****.", "*...*.", "****..", ".***..", ".***..", "..*...", "*...*.", "*...*.", "..*...", "*****.", "......"}
};

char grid[60][60];
FONT actualFont;

inline bool valid(int row, int col)
{
	return row >= 0 && row < 60 && col >= 0 && col < 60;
}

vector<string> makeC5Text(string text)
{
	vector<string> temp(5,"");
	for(int i = 0; i < (int)text.size(); ++i)
	{
		int idx;
		if (text[i] == ' ') idx = 26;
		else idx = text[i] - 'A';

		for(int j = 0; j < 5; ++j)
			temp[j] += fontC5[j][idx];
	}
	return temp;
}

void printText(int row, int col, FONT font, string text)
{
	if (font == C1)
	{
		for(int i = 0; i < (int)text.size(); ++i, ++col)
			if (valid(row,col) && !isspace(text[i]))
				grid[row][col] = text[i];
	}
	else
	{
		vector<string> c5Text = makeC5Text(text);
		for(int i = 0; i < (int)c5Text.size(); ++i)
			for(int j = 0; j < (int)c5Text[i].size(); ++j)
				if (valid(row + i, col + j) && c5Text[i][j] != '.')
					grid[row + i][col + j] = c5Text[i][j];
	}
}

void initGrid()
{
	for(int i = 0; i < 60; ++i)
		for(int j = 0; j < 60; ++j)
			grid[i][j] = '.';
}

void printGrid()
{
	for(int i = 0; i < 60; ++i)
	{
		for(int j = 0; j < 60; ++j)
			cout << grid[i][j];
		cout << endl;
	}
}
	
int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	initGrid();
	string command, font, text;
	int row, col;

	while(cin >> command)
	{
		if (command == ".EOP")
		{
			printGrid();
			cout << endl;
			string dash(60,'-');
			cout << dash << endl;
			cout << endl;
			initGrid();
			continue;
		}

		cin >> font >> row;
		--row;
		actualFont = font == "C1" ? C1 : C5;

		if (command == ".P")
		{
			cin >> col;
			--col;
			getline(cin,text);
			text = text.erase(0,text.find_first_of('|')+1);
			text = text.erase(text.find_last_of('|'));
			printText(row,col,actualFont,text);
		}
		else if (command == ".L")
		{
			getline(cin,text);
			text = text.erase(0,text.find_first_of('|')+1);
			text = text.erase(text.find_last_of('|'));
			printText(row,0,actualFont,text);
		}
		else if (command == ".R")
		{
			getline(cin,text);
			text = text.erase(0,text.find_first_of('|')+1);
			text = text.erase(text.find_last_of('|'));
			if (actualFont == C1)
				printText(row, 60 - (int)text.size(), actualFont, text);
			else
				printText(row, 60 - (int)text.size() * 6, actualFont, text);
		}
		else if (command == ".C")
		{
			getline(cin,text);
			text = text.erase(0,text.find_first_of('|')+1);
			text = text.erase(text.find_last_of('|'));
			if (actualFont == C1)
				printText(row, (60 - (int)text.size()) / 2 + (text.size() & 1 ? 1 : 0),actualFont,text);
			else
			{
				printText(row, (60 - (int)text.size() * 6) / 2,actualFont,text);
			}
		}
	}
	return 0;
}


