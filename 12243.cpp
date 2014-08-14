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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string line;

	while (getline(cin, line) && line != "*")
	{
		istringstream iss(line);
		string s;
		char ch = '\0';
		bool is_tautogram = true;

		while (iss >> s)
			if (ch == '\0')
				ch = tolower(s[0]);
			else
				if (ch != tolower(s[0]))
				{
					is_tautogram = false;
					break;
				}
		if (is_tautogram) cout << 'Y' << endl;
		else cout << 'N' << endl;
	}
}