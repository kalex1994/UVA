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

map<string, int> t;

void init()
{
	const char* words1[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
		                    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const char* words2[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	int num = 0;
	for(const char* w : words1)
		t[w] = num++;
	num = 20;
	for(const char* w : words2)
	{
		t[w] = num;
		num += 10;
	}
}

string tokens[20];
int n;

int find_index(int left, int right, const string& val)
{
	for(int i = left; i < right; ++i)
		if (tokens[i] == val)
			return i;
	return -1;
}

int parse_tens(int left, int right)
{
	int number = 0;
	for(int i = left; i < right; ++i)
		number += t[tokens[i]];
	return number;
}

int parse_hundreds(int left, int right)
{
	if (left >= right) return 0;
	int index = find_index(left, right, "hundred");
	if (index != -1)
		return parse_tens(left, index) * 100 + parse_tens(index + 1, right);
	else
		return parse_tens(left, right);
}

int parse_thousands(int left, int right)
{
	if (left >= right) return 0;
	int index = find_index(left, right, "thousand");
	if (index != -1)
		return parse_hundreds(left, index) * 1000 + parse_hundreds(index + 1, right);
	else
		return parse_hundreds(left, right);
}

int parse_millions(int left, int right)
{
	if (left >= right) return 0;
	int index = find_index(left, right, "million");
	if (index != -1)
		return parse_hundreds(left, index) * 1000000 + parse_thousands(index + 1, right);
	else
		return parse_thousands(left, right);
}

int parse_number(int left, int right)
{
	if (tokens[left] == "negative")
		return -parse_millions(left + 1, right);
	else
		return parse_millions(left, right);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif
	
	init();

	string line, token;
	while(getline(cin, line))
	{
		istringstream iss(line);
		n = 0;
		while(iss >> token)
		{
			tokens[n] = token;
			++n;
		}
		cout << parse_number(0, n) << endl;
	}
}