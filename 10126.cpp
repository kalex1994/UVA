#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

void get_words(string line, map<string, int>& words)
{
	string s = "";
	for(size_t i = 0; i < line.length(); ++i)
	{
		if (isalpha(line[i]))
			s += tolower(line[i]);
		else
			if (s.length() > 0)
			{
				if (words.find(s) == words.end())
					words[s] = 0;
				++words[s];
				s = "";
			}
	}
	if (s.length() > 0)
	{
		if (words.find(s) == words.end())
			words[s] = 0;
		++words[s];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n;
	string line;
	map<string, int> words;
	bool first = true;

	while(cin >> n)
	{
		words.clear();
		while(getline(cin, line) && line != "EndOfText")
			get_words(line, words);

		if (first)
			first = false;
		else
			putchar('\n');

		bool found = false;
		for(map<string, int>::iterator it = words.begin(); it != words.end(); ++it)
			if (it->second == n)
			{
				puts(it->first.c_str());
				found = true;
			}
		if (!found)
			puts("There is no such word.");
	}
}