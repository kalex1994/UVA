#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
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
#include <cfloat>
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
#endif
using namespace std;

char s[300];

bool are_equal(int a, int b, int c, int d)
{
	if (b - a != d - c) 
		return false;
	int n = b - a + 1;
	for(int i = 0; i < n; ++i)
		if (s[a + i] != s[c + i])
			return false;
	return true;
}

string create_str(int a, int b)
{
	char temp = s[b + 1];
	s[b + 1]= '\0';
	string ans(s + a);
	s[b + 1] = temp;
	return ans;
}

bool is_palinword()
{
	set<string> was;
	int n = strlen(s);
	if (n < 6) return false;
	s[n] = '$'; s[n + 1] = '\0';

	vector<pair<int,int>> v;
	for(int i = 1; i < n; ++i)
	{
		if (s[i] == s[i + 1])
		{
			int a = i, b = i;
			while(s[a - 1] == s[b + 2])
			{
				--a;
				++b;
				if (b - a + 1 >= 3) v.push_back(make_pair(a, b));
				string p = create_str(a, b);
				if (was.find(p) == was.end())
					was.insert(p);
				else
					break;
			}		
		}
		else
		{
			int a = i, b = i;
			while(s[a - 1] == s[b + 1])
			{
				--a;
				++b;
				if (b - a + 1 >= 3) v.push_back(make_pair(a, b));
				string p = create_str(a, b);
				if (was.find(p) == was.end())
					was.insert(p);
				else
					break;
			}
		}
	}

	for(auto p1 : v)
		for(auto p2 : v)
		{
			if (p1.first >= p2.first && p1.second <= p2.second) continue;
			if (p2.first >= p1.first && p2.second <= p1.second) continue;
			if (!are_equal(p1.first, p1.second, p2.first, p2.second))
			{
				return true;
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

	s[0] = '$';
	while(scanf("%s", &s[1]) != EOF)
		if (is_palinword())
		{
			int n = strlen(s);
			s[n - 1] = '\0'; 
			printf("%s\n", s + 1);
		}
}