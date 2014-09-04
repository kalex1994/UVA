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

string decode(const string& s)
{
	string res;
	size_t i = 0;
	int ascii;

	while(i < s.length())
	{
		ascii = s[i] - '0' + 10 * (s[i + 1] - '0');
		if (ascii < 32)
		{
			ascii += 100;
			i += 3;
		}
		else
			i += 2;
		
		res += (char)ascii;
	}

	reverse(res.begin(), res.end());
	return res;
}

string encode(const string& s)
{
	string res, temp;
	for(int i = (int)s.length() - 1; i >= 0; --i)
	{
		temp = to_string(s[i]);
		reverse(temp.begin(), temp.end());
		res += temp;
	}
	return res;
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
		if (isdigit(line[0]))
			cout << decode(line) << endl;
		else 
			cout << encode(line) << endl;
	}
}