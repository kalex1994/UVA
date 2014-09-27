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
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
using namespace std;

vector<string> newspapers;
vector<int> subset;

void print_subset(int n, int pos)
{
	if (n < 0)
		return;
	if (pos == newspapers.size())
	{
		if (n == 0)
		{
			for(int i = 0; i < subset.size(); ++i)
			{
				if (i != 0) cout << ", ";
				cout << newspapers[subset[i]];
			}
			cout << endl;
		}
		return;
	}
		
	subset.push_back(pos);
	print_subset(n - 1, pos + 1);
	subset.pop_back();
	print_subset(n, pos + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, a, b;
	string interval, s;

	cin >> tests;
	cin.ignore(100, '\n');
	cin.ignore(100, '\n');

	while(tests--)
	{
		newspapers.clear();

		getline(cin, interval);
		while(getline(cin, s) && !s.empty())
			newspapers.push_back(s);
		
		if (interval[0] == '*')
			a = 1, b = newspapers.size();
		else if (interval.find(' ') == string::npos)
			a = b = stoi(interval);
		else
			istringstream(interval) >> a >> b;
		
		for(int i = a; i <= b; ++i)
		{
			cout << "Size "<< i << endl;
			print_subset(i, 0);
			cout << endl;
		}
		if (tests)
			cout << endl;
	}
}