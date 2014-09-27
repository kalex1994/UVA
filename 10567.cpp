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

vector<int> v[52];
string s, q;

inline int index_of(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch - 'A';
	else
		return ch - 'a' + 26;
}

void init()
{
	for(int i = 0; i < (int)s.length(); ++i)
		v[index_of(s[i])].push_back(i);
}

void search()
{
	int pos = 0, start = -1, end;
	for(char ch : q)
	{
		int i = index_of(ch);
		auto it = lower_bound(v[i].begin(), v[i].end(), pos);
		if (it == v[i].end())
		{
			cout << "Not matched" << endl;
			return;
		}
		else
		{
			if (start < 0)
				start = *it;
			end = *it;
			pos = *it + 1;
		}
	}
	cout << "Matched " << start << " " << end << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	cin >> s;
	init();

	int tests;
	cin >> tests;
	while(tests--)
	{
		cin >> q;
		search();
	}
}