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
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	char cipher[256];
	string line, plaintext, substitution;

	cin >> tests; 
	cin.ignore(100, '\n');
	cin.ignore(100, '\n');

	while(tests--)
	{
		fill(cipher, cipher + 256, '\0');

		getline(cin, plaintext);
		getline(cin, substitution);
		puts(substitution.c_str());
		puts(plaintext.c_str());	

		for(size_t i = 0; i < plaintext.length(); ++i)
			cipher[plaintext[i]] = substitution[i];

		while(getline(cin, line) && !line.empty())
		{
			for(char ch : line)
				if (cipher[ch] == '\0')
					putchar(ch);
				else
					putchar(cipher[ch]);
			putchar('\n');
		}

		if (tests)
			putchar('\n');
	}
}