#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
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
#include <cfloat>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
#endif
using namespace std;

vector<string> tokenize(const string& line)
{
	vector<string> tokens;
	istringstream sin(line);
	string token;
	while(sin >> token)
		tokens.push_back(token);
	return tokens;
}

char rotate_to_right(char ch, int n)
{
	ch -= 'A';
	ch = (ch + n) % 26;
	return ch + 'A';
}

string encrypt(int& m, const string& word, const string& key, const int n)
{
	char buffer[10000];
	int i = 0;

	for(char ch : word)
	{
		if(key.find(ch) != string::npos)
		{
			buffer[i++] = key[m];
			buffer[i++] = rotate_to_right(ch, n);
			buffer[i++] = key[(m + 1) % key.length()];
			m = (m + 1) % key.length();
		}
		else
			buffer[i++] = rotate_to_right(ch, n);
	}

	buffer[i] = '\0';
	return string(buffer);
}

string encrypt_message(const string& message, const string& key, const int n)
{
	string ciphered = "";
	vector<string> words = tokenize(message);
	
	int m = 0;
	for(const auto& w : words)
		if (ciphered.empty())
			ciphered += encrypt(m, w, key, n);
		else
		{
			ciphered += ' ';
			ciphered += encrypt(m, w, key, n);
		}

	return ciphered;
}

char rotate_to_left(char ch, int n)
{
	ch -= 'A';
	ch = (ch + 26 - n) % 26;
	return ch + 'A';
}

string decrypt(int i, string ans, const string& word, int&m, const string& key, const int n)
{
	if (i == word.length())
		return ans;
	if (i + 2 < word.length())
	{
		if (word[i] == key[m] && word[i + 2] == key[(m + 1) % key.length()])
		{
			m = (m + 1) % key.length();
			char ch = rotate_to_left(word[i + 1], n);
			if (key.find(ch) != string::npos)
				return decrypt(i + 3, ans + ch, word, m, key, n);
			m = (m + key.length() - 1) % key.length();
		}
	}
	char ch = rotate_to_left(word[i], n);
	if (key.find(ch) == string::npos)
		return decrypt(i + 1, ans + ch, word, m, key, n);
	return "";
}

string decrypt_message(const string& message, const string& key, const int n)
{
	string decrypted = "";
	vector<string> words = tokenize(message);

	int m = 0;
	for (const auto& w : words)
		if(decrypted.empty())
			decrypted += decrypt(0, "", w, m, key, n);
		else
		{
			decrypted += ' ';
			decrypted += decrypt(0, "", w, m, key, n);
		}

	return decrypted;
}

void solve(const string& message, const string& key, const int n)
{
	string decrypted = decrypt_message(message, key, n);
	if (encrypt_message(decrypted, key, n) == message)
		cout << decrypted << endl;
	else
		cout << "error in encryption" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, n, messages;
	string message, key;

	cin >> tests;
	while (tests--)
	{
		cin >> key >> n >> messages;
		cin.ignore(100, '\n');
		while(messages--)
		{
			getline(cin, message);
			solve(message, key, n);
		}
		if (tests)
			cout << endl;
	}
}