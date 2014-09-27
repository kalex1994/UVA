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

vector<pair<char, string>> codes;
string encrypted;

bool read_input()
{
	int n;
	char letter;
	string code;

	cin >> n;
	if (n == 0)
		return false;

	codes.clear();
	while(n--)
	{
		cin >> letter >> code;
		codes.push_back(make_pair(letter, code));
		codes.push_back(make_pair(letter, "0" + code));
	}
	cin >> encrypted;
	sort(codes.begin(), codes.end());
	return true;
}

const int MAXN = 500;
char code[MAXN], decoded[MAXN];
int printed;

void solve(int cpos, int dpos)
{
	if (cpos == encrypted.length())
	{
		++printed;
		decoded[dpos] = '\0';
		cout << decoded << endl;
		return;
	}

	for(auto p : codes)
	{
		bool flag = true;

		if (cpos + p.second.length() <= encrypted.length())
		{
			for(int i = 0; i < p.second.length(); ++i)
				if (encrypted[cpos + i] != p.second[i])
					flag = false;
		}
		else
			flag = false;

		if (flag)
		{
			for(int i = 0; i < p.second.length(); ++i)
				code[cpos + i] = p.second[i];
			decoded[dpos] = p.first;
			if (printed < 100)
				solve(cpos + p.second.length(), dpos + 1);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int test = 1;
	while(read_input())
	{
		cout << "Case #" << test++ << endl;
		printed = 0;
		solve(0, 0);
		cout << endl;
	}
}