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

vector<string> numbers;
char vigenere_table[26][26];

void init_numbers()
{
	const vector<string> digit_names { "nine", "eight", "seven", "six", "five", "four", "three", "two", "one", "zero" };
	for(const string& s1 : digit_names)
		for(const string& s2 : digit_names)
			for(const string& s3 : digit_names)
				numbers.push_back(s1 + s2 + s3);
}

inline char next_letter(const char ch)
{
	if (ch == 'Z')
		return 'A';
	else
		return ch + 1;
}

void init_vigenere_table()
{
	char start = 'B';
	for(int i = 0; i < 26; ++i)
	{
		char current = start;
		for(int j = 0; j < 26; ++j, current = next_letter(current))
			vigenere_table[i][j] = current;
		start = next_letter(start);
	}
}

int find_row(char val, char column)
{
	int col = column - 'a';
	for (int row = 0; row < 26; ++row)
	if (vigenere_table[row][col] == val)
		return row;
}

void decode(const string& encoded)
{
	for(const string& plaintext : numbers)
	{
		if (plaintext.length() != encoded.length())
			continue;

		string key = "";
		for(size_t i = 0; i < encoded.length(); ++i)
			key += (char)('A' + find_row(encoded[i], plaintext[i]));
		cout << key << " -> " << plaintext << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	init_numbers();
	init_vigenere_table();

	string encoded;
	bool first = true;
	while(cin >> encoded)
	{
		if (first)
			first = false;
		else
			cout << '\n';
		decode(encoded);
	}
}