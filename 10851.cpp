#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

string matrix[10];
const int powers[] = { 0, 1, 2, 4, 8, 16, 32, 64, 128 };

char decode(int col)
{
	char ch = 0;
	
	for(int row = 7; row > 0; --row)
	{
		if (matrix[row][col] == '/')
		{
			if ( (ch / powers[row]) % 2 != 0)
				ch += powers[row];
		}
		else
		{
			if ( (ch / powers[row]) % 2 != 1)
				ch += powers[row];
		}
	}

	return ch;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	string s;

	cin >> tests;
	while(tests--)
	{
		for(int i = 0; i < 10; ++i)
			cin >> matrix[i];
		s = "";
		for(int col = 1; col < matrix[0].length() - 1; ++col)
			s += decode(col);
		cout << s << endl;
	}

}