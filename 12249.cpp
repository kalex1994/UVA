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

int n;
string scenes[6];

size_t longest_common(const string& a, const string& b)
{
	size_t len = min(a.length(), b.length());
	size_t result = 0;
	for (size_t i = 1; i <= len; ++i)
		if (a.substr(a.length() - i) == b.substr(0, i))
			result = i;
	return result;
}

string merge(const string& a, const string& b)
{
	return a + b.substr(longest_common(a, b));
}

int solve()
{
	if (n == 0) return 0;
	if (n == 1) return scenes[0].length();

	vector<int> index(n);
	for (int i = 0; i < n; ++i)
		index[i] = i;

	size_t answer = 99999999;
	do
	{
		string s = merge(scenes[index[0]], scenes[index[1]]);
		for (int i = 2; i < n; ++i)
			s = merge(s, scenes[index[i]]);
		answer = min(answer, s.length());

	} while (next_permutation(index.begin(), index.end()));
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	
	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> scenes[i];
		printf("Case %d: %d\n", test, solve());
	}	
}