#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 200 + 5;
const char HIEROGLYPHS[] = {'W', 'A', 'K', 'J', 'S', 'D'};

int H, W, testCase = 1;
char ch;
int pixels[MAX_SIZE][MAX_SIZE];
map<char, string> decoder;

struct position
{
	int row, col;
	position(int _row = 0, int _col = 0) : row(_row), col(_col) {}
};

void floodFill(int startRow, int startCol, int oldColor, int newColor)
{
	stack<position> s;
	position p;

	s.push(position(startRow, startCol));
	while(!s.empty())
	{
		p = s.top(); s.pop();
		pixels[p.row][p.col] = newColor;
		if (p.row > 0 && pixels[p.row - 1][p.col] == oldColor) s.push(position(p.row - 1, p.col));
		if (p.col > 0 && pixels[p.row][p.col - 1] == oldColor) s.push(position(p.row, p.col - 1));
		if (p.row + 1 < H && pixels[p.row + 1][p.col] == oldColor) s.push(position(p.row + 1, p.col));
		if (p.col + 1 < W && pixels[p.row][p.col + 1] == oldColor) s.push(position(p.row, p.col + 1));
	}
}

int floodFill(int row, int col)
{
	if (pixels[row][col] == 0)
	{
		if (row > 0) return floodFill(row - 1, col);
		if (col > 0) return floodFill(row, col - 1);
		if (row + 1 < H) return floodFill(row + 1, col);
		if (col + 1 < W) return floodFill(row, col + 1);
	}
	else return pixels[row][col];
}

int main()
{	
	decoder['0'] = "0000"; decoder['1'] = "0001"; decoder['2'] = "0010"; decoder['3'] = "0011";
	decoder['4'] = "0100"; decoder['5'] = "0101"; decoder['6'] = "0110"; decoder['7'] = "0111";
	decoder['8'] = "1000"; decoder['9'] = "1001"; decoder['a'] = "1010"; decoder['b'] = "1011";
	decoder['c'] = "1100"; decoder['d'] = "1101"; decoder['e'] = "1110"; decoder['f'] = "1111";

	while(cin >> H >> W && (H || W))
	{
		for(int i = 0; i < H; ++i)
		{
			string line = "";
			for(int j = 0; j < W; ++j)
			{
				cin >> ch;
				line += decoder[ch];
			}
			for(int j = 0; j < (int)line.size(); ++j)
				pixels[i][j] = line[j] - '0';
		}
		W *= 4;

		int color = 1;
		for(int i = 0; i < H; ++i)
			for(int j = 0; j < W; ++j)
				if (pixels[i][j] == 1)
					floodFill(i, j, 1, ++color);

		for(int i = 0; i < H; ++i)
		{
			if (pixels[i][0] == 0) floodFill(i, 0, 0, 1);
			if (pixels[i][W - 1] == 0) floodFill(i, W - 1, 0, 1);
		}
		for(int j = 0; j < W; ++j)
		{
			if (pixels[0][j] == 0) floodFill(0, j, 0, 1);
			if (pixels[H - 1][j] == 0) floodFill(H - 1, j, 0, 1);
		}

		map<int,int> objects;
		for(int i = 2; i <= color; ++i)
			objects[i] = 0;

		for(int i = 0; i < H; ++i)
			for(int j = 0; j < W; ++j)
				if (pixels[i][j] == 0)
				{
					int c = floodFill(i, j);
					++objects[c];
					floodFill(i, j, 0, c);
				}

		string output = "";
		for(map<int,int>::const_iterator it = objects.begin(); it != objects.end(); ++it)
			output += HIEROGLYPHS[it->second];

		sort(output.begin(), output.end());
		printf("Case %d: %s\n", testCase++, output.c_str());
	}
	return 0;
}