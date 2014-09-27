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

string header, message;
vector<string> pattern;

string int_to_binary_string(int n, size_t length)
{
	string result;
	while (n)
	{
		result += n % 2 == 0 ? '0' : '1';
		n /= 2;
	}
	for (auto len = result.length(); len < length; ++len)
		result += '0';
	reverse(result.begin(), result.end());
	return result;
}

int binary_to_int(const string& s, int pos, int len)
{
	int result = 0, p = 1;
	for(int i = pos + len - 1; i >= pos; --i)
	{
		result += s[i] == '1' ? p : 0;
		p <<= 1;
	}
	return result;
}

void init()
{
	for(int length = 1; length <= 7; ++length)
		for(int j = 0; j + 1 < (1 << length); ++j)
			pattern.push_back(int_to_binary_string(j, length));
}

bool read_testcase()
{
	cin >> ws;
	if (!getline(cin, header))
		return false;
	message = "";
	while(true)
	{
		int ch = (cin >> ws).peek();
		if (ch == '0' || ch == '1')
		{
			message += ch;
			cin.get();
		}
		else
			break;
	}
	return true;
}

inline int get_position(const string& patt)
{
	return (int)distance(pattern.begin(), find(pattern.begin(), pattern.end(), patt));
}

string decode()
{
	int i = 0, length;
	string patt, answer;

	while((length = binary_to_int(message, i, 3)) != 0)
	{
		i += 3;
		string end = string(length, '1');
		while(true)
		{
			patt = message.substr(i, length);
			i += length;
			if (patt == end)
				break;
			answer += header[get_position(patt)];
			
		}
	}
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	init();
	while(read_testcase())
		cout << decode() << endl;
}