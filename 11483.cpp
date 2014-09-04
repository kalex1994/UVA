#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <stack>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <numeric>
#include <deque>
#include <map>
#include <iterator>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
#include <array>
#include <regex>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif
	
	int n, ch, c = 1;
	string line;

	while(cin >> n && n)
	{
		cin.ignore(100, '\n');

		cout << "Case " << c++ << ":" << endl;
		cout << "#include<string.h>" << endl << "#include<stdio.h>" << endl << "int main()" << endl << "{" << endl;
		while(n--)
		{
			cout << "printf(\"";
			getline(cin, line);
			for(char ch : line)
			{
				if (ch == '\\' || ch == '"')
					cout << '\\';
				cout << ch;
			}
			cout << "\\n\");\n";
		}
		cout << "printf(\"\\n\");" << endl << "return 0;" << endl << "}" << endl;
	}
}