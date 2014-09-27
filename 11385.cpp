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

map<int, int> fibo;
vector<int> fibs;

string clean_punctuation(const string& s)
{
	string result;
	for(const char ch : s)
		if (ch >= 'A' && ch <= 'Z')
			result += ch;
	return result;
}

void init_fibonacci_numbers()
{
	fibo[1] = 1;
	fibo[2] = 2;
	fibs.push_back(1);
	fibs.push_back(2);

	int index = 3;
	const unsigned long long LIMIT = (1llu << 31);
	unsigned long long a = 1, b = 2, c;

	while(true)
	{
		c = a + b;
		if (c >= LIMIT)
			break;
		fibo[(int)c] = index++;
		fibs.push_back((int)c);
		a = b;
		b = c;
	}
}

string decode(const vector<int>& f, const string& s)
{
	int max_fibo = *max_element(f.begin(), f.end());
	int missing = 0;
	for(size_t i = 0; fibs[i] < max_fibo; ++i)
		if (find(f.begin(), f.end(), fibs[i]) == f.end())
			++missing;

	string result(max(s.length() + missing, f.size()),' '); 
	for(size_t i = 0; i < min(f.size(), s.length()); ++i)
		result[fibo[f[i]] - 1] = s[i];
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	init_fibonacci_numbers();
	
	int tests, n;
	vector<int> f;
	string s;

	cin >> tests;
	while(tests--)
	{
		cin >> n;
		f.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> f[i];
		cin >> ws;
		getline(cin, s);

		s = decode(f, clean_punctuation(s));

		size_t endpos = s.find_last_not_of(' ');
		if (string::npos != endpos)
			s = s.substr(0, endpos + 1);
		cout << s << endl;
	}
}