#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

enum DIRECTION {FORTH, LEFT, RIGHT};

bool isSafeToStep(string maze[], int row, int col)
{
	static const string SAFE = "IEHOVA#";
	if (SAFE.find(maze[row][col])  != string::npos)
		return true;
	return false;
}

void printSolution(const vector<DIRECTION>& steps)
{
	for(size_t i = 0; i < steps.size(); ++i)
	{
		if (i > 0) cout << ' ';
		cout << (steps[i] == FORTH ? "forth" : steps[i] == LEFT ? "left" : "right");
	}
	cout << endl;
}

void solve(string maze[], int r, int c, vector<DIRECTION>& steps)
{
	if (maze[r][c] == '#')
	{
		printSolution(steps);
		return;
	}

	if (r - 1 >= 0 && isSafeToStep(maze, r - 1, c))
	{
		steps.push_back(FORTH);
		char temp = maze[r][c];
		maze[r][c] = '.';
		solve(maze, r - 1, c, steps);
		maze[r][c] = temp;
		steps.pop_back();
	}
	else if (c - 1 >= 0 && isSafeToStep(maze, r, c - 1))
	{
		steps.push_back(LEFT);
		char temp = maze[r][c];
		maze[r][c] = '.';
		solve(maze, r, c - 1, steps);
		maze[r][c] = temp;
		steps.pop_back();
	}
	else if (c + 1 < (int)maze[0].length() && isSafeToStep(maze, r, c + 1))
	{
		steps.push_back(RIGHT);
		char temp = maze[r][c];
		maze[r][c] = '.';
		solve(maze, r, c + 1, steps);
		maze[r][c] = temp;
		steps.pop_back();
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, rows, cols, r, c;
	string maze[8];
	vector<DIRECTION> steps;
	
	cin >> tests;
	while(tests--)
	{
		cin >> rows >> cols;

		for(int i = 0; i < rows; ++i)
			cin >> maze[i];

		int r = rows - 1;
		int c = maze[r].find('@');

		solve(maze, r, c, steps); 
	}
}