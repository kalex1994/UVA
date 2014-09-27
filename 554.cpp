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

vector<string> dict;
int max_word_count, k;

int word_count(const string& s)
{
	istringstream iss(s);
	string token;
	int result = 0;

	while(iss >> token)
		if (find(dict.begin(), dict.end(), token) != dict.end())
			++result;
	return result;
}

char shift(char ch, int k)
{
	if (ch == ' ')
		return k == 0 ? ' ' : 'A' + k - 1;
	else
	{
		int m = (ch - 'A' + k + 1) % 27;
		return m == 0 ? ' ' : 'A' + m - 1;
	}
}

string decypher(const string& s, int k)
{
	string result = s;
	for(char& ch : result)
		ch = shift(ch, k);
	return result;
}

void trim(string& r)
{
	size_t endpos = r.find_last_not_of(" ");
	if (string::npos != endpos)
		r = r.substr(0, endpos + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string s, encrypted;
	while(cin >> s && s != "#")
		dict.push_back(s);
	cin >> ws;
	getline(cin, encrypted);

	int max_word_count = 0, answer = 0;
	for(int i = 0; i < 27; ++i)
	{
		string temp = decypher(encrypted, i);
		int w_count = word_count(temp);
		if (w_count > max_word_count)
		{
			max_word_count = w_count;
			answer = i;
		}
	}

	s = decypher(encrypted, answer);
	set<int> wstart;
	map<int, int> wlen;
	char prev = ' ';

	for(int i = 0; i < s.length(); ++i)
	{
		if (prev == ' ' && isalpha(s[i]))
		{
			int len = 1;
			for(int j = i + 1; j < s.length() && isalpha(s[j]); ++j)
				++len;
			wstart.insert(i);
			wlen[i] = len;
			i += len;
		}
		prev = s[i];
	}

	int printed = 0;
	string r = "";
	const int MAX = 60;

	for(int i = 0; i < s.length(); ++i)
	{
		if (isalpha(s[i]))
		{
			if (wstart.find(i) != wstart.end())
			{
				if (printed + wlen[i] > MAX)
				{
					trim(r);
					cout << r << endl;
					r = "";
					r += s[i];
					printed = 1;
				}
				else
				{
					++printed;
					r += s[i];
				}
			}
			else
			{
				r += s[i];
				++printed;
			}
		}
		else
		{
			if (printed < MAX)
			{
				r += s[i];
				++printed;
			}
			else if (printed == MAX)
			{
				trim(r);
				cout << r << endl;
				r = "";
				printed = 0;
			}
		}
	}
	if (!r.empty())
	{
		trim(r);
		cout << r;
	}
	putchar('\n');
}