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

const int MAXN = 1000;
int dp[MAXN + 1][MAXN + 1];

string remove_punctuation(const string s)
{
	const regex punctuation("[^a-zA-Z0-9 ]");
	return regex_replace(s, punctuation, " ");
}

vector<string> split(const string& s)
{
	vector<string> tokens;
	istringstream iss(s);
	string token;
	while(iss >> token)
		tokens.push_back(token);
	return tokens;
}

int lcs(const vector<string>& a, const vector<string>& b)
{
	for(size_t i = 0; i < a.size(); ++i)
		dp[i][0] = 0;
	for(size_t j = 0; j < b.size(); ++j)
		dp[0][j] = 0;

	for(int i = 1; i <= a.size(); ++i)
		for(int j = 1; j <= b.size(); ++j)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	return dp[a.size()][b.size()];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string s1, s2;
	int test_case = 1;

	while(getline(cin, s1))
	{
		getline(cin, s2);
		vector<string> v1 = split(remove_punctuation(s1));
		vector<string> v2 = split(remove_punctuation(s2));

		if (v1.empty() || v2.empty())
			printf("%2d. Blank!\n", test_case++);
		else
			printf("%2d. Length of longest match: %d\n", test_case++, lcs(v1, v2));
	}
}