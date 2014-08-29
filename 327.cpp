#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
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

const int N = 26;

bool used[N];
int v1[N], v2[N];

void init()
{
	for(int i = 0; i < N; ++i)
	{
		v1[i] = v2[i] = i + 1;
		used[i] = false;
	}
}

string clean(const string& s)
{
	string result;
	for(char ch : s)
		if (!isspace(ch))
			result += ch;
	return "$$" + result + "$$";
}

int eval(string s)
{
	for(size_t i = 0; i + 2 < s.length(); ++i)
		if (isalpha(s[i]))
		{
			used[s[i] - 'a'] = true;
			if (s[i-1] == s[i-2])
			{
				if (s[i-1] == '-')
				{
					--v1[s[i] - 'a'];
					--v2[s[i] - 'a'];
				}
				else if (s[i-1] == '+')
				{
					++v1[s[i] - 'a'];
					++v2[s[i] - 'a'];
				}
				s[i-1] = s[i-2] = ' ';
			}
			if (s[i+1] == s[i+2])
			{
				if (s[i+1] == '-')
					--v2[s[i] - 'a'];
				else if (s[i+1] == '+')
					++v2[s[i] - 'a'];
				s[i+1] = s[i+2] = ' ';
			}
		}

	istringstream iss(s);
	int result;
	char n, op;

	iss >> n;
	result = v1[n - 'a'];
	while(iss >> op)
	{
		iss >> n;
		if (op == '-')
			result -= v1[n - 'a'];
		else 
			result += v1[n - 'a'];
	}

	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string line;
	while(getline(cin, line))
	{
		init();
		printf("Expression: %s\n", line.c_str());
		printf("    value = %d\n", eval(clean(line)));
		for(int i = 0; i < N; ++i)
			if (used[i])
				printf("    %c = %d\n", i + 'a', v2[i]);
	}
}