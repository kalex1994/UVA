#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;

void rotate_1(string &cube)
{
	char temp = cube[2];
	cube[2] = cube[1];
	cube[1] = cube[3];
	cube[3] = cube[4];
	cube[4] = temp;
}

void rotate_2(string &cube)
{
	char temp = cube[0];
	cube[0] = cube[3];
	cube[3] = cube[5];
	cube[5] = cube[2];
	cube[2] = temp;
}

void rotate_3(string &cube)
{
	char temp = cube[0];
	cube[0] = cube[1];
	cube[1] = cube[5];
	cube[5] = cube[4];
	cube[4] = temp;
}

bool is_same_cube(string cube1, string cube2)
{
	for (int i = 0; i < 4; ++i)
	{
		rotate_1(cube1);
		for (int j = 0; j < 4; ++j)
		{
			rotate_2(cube1);
			for (int k = 0; k < 4; ++k)
			{
				rotate_3(cube1);
				if (cube1 == cube2)
					return true;
			}
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string s;
	while (cin >> s)
	{
		if (is_same_cube(s.substr(0, 6), s.substr(6)))
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}
}