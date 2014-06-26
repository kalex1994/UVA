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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif
	string line;
	getline(cin, line);
	while (getline(cin, line) && line != "___________")
	{
		char ch = 0;
		ch += line[2] == 'o' ? 64 : 0;
		ch += line[3] == 'o' ? 32 : 0;
		ch += line[4] == 'o' ? 16 : 0;
		ch += line[5] == 'o' ? 8 : 0;
		ch += line[7] == 'o' ? 4 : 0;
		ch += line[8] == 'o' ? 2 : 0;
		ch += line[9] == 'o' ? 1 : 0;
		putchar(ch);
	}
}