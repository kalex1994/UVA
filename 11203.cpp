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

void split(string s, string& token1, string& token2, string& token3)
{
	for (char& ch : s)
		if (ch == 'M' || ch == 'E')
			ch = ' ';
	istringstream iss(s);
	iss >> token1 >> token2 >> token3;
}

bool is_theorem(string s)
{
	if (count(s.begin(), s.end(), 'M') != 1) return false;
	if (count(s.begin(), s.end(), 'E') != 1) return false; 
	if (distance(find(s.begin(), s.end(), 'M'), find(s.begin(), s.end(), 'E')) < 2) return false;

	string tokens[3];
	split(s, tokens[0], tokens[1], tokens[2]);

	for (string& token : tokens)
		if (count(token.begin(), token.end(), '?') != token.length()) 
			return false;

	if (1 + tokens[0].length() == tokens[2].length() - (tokens[1].length() - 1))
		return true;
	else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	string s;
	
	cin >> tests;
	while (tests--)
	{
		cin >> s;
		if (is_theorem(s))
			cout << "theorem" << endl;
		else
			cout << "no-theorem" << endl;
	}
}