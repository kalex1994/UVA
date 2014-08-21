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
#include <map>
using namespace std;

void clean_string(string& s)
{
	for (char& ch : s)
		if (ch == '?' || ch == '!' || ch == ',' || ch == '.')
			ch = ' ';
}

int word_length(const string& s)
{
	int length = 0;
	for (char ch : s)
		if (isalpha(ch))
			++length;
	return length;
}

vector<string> tokenize(const string& s)
{
	istringstream iss(s);
	vector<string> tokens;
	string token;

	while (iss >> token)
		tokens.push_back(token);
	return tokens;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string line;
	while (true)
	{
		if (!getline(cin, line) || line.empty())
			break;
		if (line[0] == '#')
			continue;

		string s = line;
		while (getline(cin, line) && line[0] != '#')
		{
			if (s.back() != '-')
				s += ' ';
			s += line;
		}
			
		clean_string(s);

		map<int, int> m;
		for (string& t : tokenize(s))
			++m[word_length(t)];

		for (auto it = m.begin(); it != m.end(); ++it)
			cout << it->first << " " << it->second << endl;		
		cout << endl;
	}	
}