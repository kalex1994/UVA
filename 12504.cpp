#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<limits>
#include<sstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<list>
#include<iomanip>
#include<queue>
#include<cfloat>

using namespace std;

map<string, string> oldDictionary, newDictionary;

void tokenize(string &s, vector<string> &tokens)
{
	for(int i = 0; i < (int)s.size(); ++i)
		if (s[i] == '{' || s[i] == '}' || s[i] == ':' || s[i] == ',')
			s[i] = ' ';

	istringstream iss(s);
	string token;

	tokens.clear();
	while(iss >> token)
		tokens.push_back(token);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int test;
	string line;
	vector<string> tokens;

	cin >> test;
	while(test--)
	{
		oldDictionary.clear();
		newDictionary.clear();

		cin >> line;
		tokenize(line, tokens);
		for(int i = 0; i < (int)tokens.size(); i += 2)
			oldDictionary[ tokens[i] ] = tokens[i + 1];

		cin >> line;
		tokenize(line, tokens);
		for(int i = 0; i < (int)tokens.size(); i += 2)
			newDictionary[ tokens[i] ] = tokens[i + 1];

		bool isFirst = true;
		bool foundNewKey = false;
		for(map<string, string>::const_iterator it = newDictionary.begin(); it != newDictionary.end(); ++it)
			if (oldDictionary.count(it->first) == 0)
			{
				foundNewKey = true;
				if (isFirst)
				{
					cout << "+" << it->first;
					isFirst = false;
				}
				else cout << "," << it->first;
			}
		if (foundNewKey) cout << endl;

		isFirst = true;
		bool foundRemovedKey = false;
		for(map<string, string>::const_iterator it = oldDictionary.begin(); it != oldDictionary.end(); ++it)
			if (newDictionary.count(it->first) == 0)
			{
				foundRemovedKey = true;
				if (isFirst)
				{
					cout << "-" << it->first;
					isFirst = false;
				}
				else cout << "," << it->first;
			}
		if (foundRemovedKey) cout << endl;

		isFirst = true;
		bool foundChangedValue = false;
		for(map<string, string>::const_iterator it = oldDictionary.begin(); it != oldDictionary.end(); ++it)
			if (newDictionary.count(it->first) != 0 && it->second != newDictionary[it->first])
			{
				foundChangedValue = true;
				if (isFirst)
				{
					cout << "*" << it->first;
					isFirst = false;
				}
				else cout << "," << it->first;
			}
		if (foundChangedValue) cout << endl;

		if (!foundNewKey && !foundRemovedKey && !foundChangedValue)
			cout << "No changes" << endl;

		cout << endl;
	}
	return 0;
}
