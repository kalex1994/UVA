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

char table[300][300];
int N, M;

void C()
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			table[i][j] = 'O';
}

void L(int x, int y, char c)
{
	--x; --y;
	table[y][x] = c;
}

void V(int x, int y1, int y2, char c)
{
	--x; --y1; --y2;
	if (y1 > y2) swap(y1, y2);
	for(int i = y1; i <= y2; ++i)
		table[i][x] = c;
}

void H(int x1, int x2, int y, char c)
{
	--x1; --x2; --y;
	if (x1 > x2) swap(x1, x2);
	for(int j = x1; j <= x2; ++j)
		table[y][j] = c;
}

void K(int x1, int y1, int x2, int y2, char c)
{
	--x1; --x2; --y1; --y2;
	for(int i = y1; i <= y2; ++i)
		for(int j = x1; j <= x2; ++j)
			table[i][j] = c;
}

void FloodFill(int row, int col, char oldColor, char newColor)
{
	table[row][col] = newColor;

	if (row - 1 >= 0 && table[row - 1][col] == oldColor)
		FloodFill(row - 1, col, oldColor, newColor);
	if (row + 1 < N && table[row + 1][col] == oldColor)
		FloodFill(row + 1, col, oldColor, newColor);
	if (col - 1 >= 0 && table[row][col - 1] == oldColor)
		FloodFill(row, col - 1, oldColor, newColor);
	if (col + 1 < M && table[row][col + 1] == oldColor)
		FloodFill(row, col + 1, oldColor, newColor);
}

void F(int x, int y, char c)
{
	if (y > 0 && y <= N && x > 0 && x <= M)
	{
		--x; --y;
		char oldColor = table[y][x];
		if (oldColor != c)
			FloodFill(y, x, oldColor, c);
	}
}

void print()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
			cout << table[i][j];
		cout << endl;
	}
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	char ch, c;
	int x,y,x1,x2,y1,y2;
	string fileName;

	while(cin >> ch)
	{
		switch(ch)
		{
		case 'I':
			cin >> M >> N;
			C();
			break;
		case 'C':
			C();
			break;
		case 'L':
			cin >> x >> y >> c;
			L(x,y,c);
			break;
		case 'V':
			cin >> x >> y1 >> y2 >> c;
			V(x,y1,y2,c);
			break;
		case 'H':
			cin >> x1 >> x2 >> y >> c;
			H(x1,x2,y,c);
			break;
		case 'K':
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			K(x1,y1,x2,y2,c);
			break;
		case 'F':
			cin >> x >> y >> c;
			F(x,y,c);
			break;
		case 'S':
			cin >> fileName;
			cout << fileName << endl;
			print();
			break;
		case 'X':
			return 0;
		default:
			break;
		}
	}
	return 0;
}


