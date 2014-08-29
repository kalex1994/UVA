#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	string encrypted, word, encrypted_word, token;
	vector<string> v;

	cin >> tests; cin.ignore(100, '\n');
	while(tests--)
	{
		v.clear();
		getline(cin, encrypted);
		getline(cin, word);
		istringstream iss(encrypted);
		while(iss >> token)
			v.push_back(token);

		for(char key = 0; key < 26; ++key)
		{
			encrypted_word.clear();
			for(char ch : word)
				encrypted_word += 'a' + (ch - 'a' + key) % 26;
			if (encrypted.find(encrypted_word) != string::npos && find(v.begin(), v.end(), encrypted_word) != v.end())
				putchar('a' + key);
		}
		putchar('\n');
	}
}