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

using namespace std;

void lowercase(string &s)
{
	for(int i = 0; i < (int)s.size(); ++i)
		s[i] = static_cast<char>(tolower(s[i]));
}

vector<string> tokenize(string &s)
{
	vector<string> tokens;
	string buf = "";

	while(!s.empty())
	{
		if (isalpha(s[0])) buf += s[0];
		else
		{
			if (buf != "") 
				tokens.push_back(buf);
			buf = "";
		}
		s.erase(0, 1);
		if (s.empty() && buf != "")
			tokens.push_back(buf);
	}
	return tokens;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string token;
	set<string> dictionary;

	while(cin >> token)
	{
		vector<string> tokens = tokenize(token);
		for(int i = 0; i < (int)tokens.size(); ++i)
		{
			lowercase(tokens[i]);
			dictionary.insert(tokens[i]);
		}
	}
	for(set<string>::const_iterator it = dictionary.begin(); it != dictionary.end(); ++it)
		cout << *it << endl;
	return 0;
}
