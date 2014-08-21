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

struct word
{
	int freq[26];

	word(const string& s)
	{
		fill(freq, freq + 26, 0);
		for (char ch : s)
			++freq[ch - 'a'];
	}

	bool can_be_made_from(const word& other)
	{
		for (size_t i = 0; i < 26; ++i)
			if (freq[i] > 0 && other.freq[i] < freq[i])
					return false;
		return true;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	vector<word> dict;
	string s;

	while (getline(cin, s) && s != "#")
		dict.push_back(word(s));
	while (getline(cin, s) && s != "#")
	{
		string puzzle;
		for (size_t i = 0; i < s.length(); i += 2)
			puzzle += s[i];
		word w(puzzle);

		int count = 0;
		for (size_t i = 0; i < dict.size(); ++i)
			if (dict[i].can_be_made_from(w))
				++count;
		cout << count << endl;	
	}
}