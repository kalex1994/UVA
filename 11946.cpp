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

char decipher[] = {'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P'};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	string line;
	bool first = true;

	cin >> tests; cin.ignore(100, '\n');
	while(tests--)
	{
		if (first)
			first = false;
		else
			putchar('\n');
		while(getline(cin, line) && line.length() > 0)
		{
			for(size_t i = 0; i < line.length(); ++i)
				if (line[i] >= '0' && line[i] <= '9')
					putchar(decipher[line[i] - '0']);
				else
					putchar(line[i]);
			putchar('\n');
		}
	}
}