#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <sstream>
using namespace std;

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int n, pos;
	char s1[100], s2[100], t[100];
	string text;
	vector< pair<string, string> > rules;

	while (scanf("%d%*c", &n) != EOF && n)
	{
		rules.clear();
		for (int i = 0; i < n; ++i)
		{
			gets(s1);
			gets(s2);
			rules.push_back(make_pair(s1, s2));
		}
		gets(t);
		text = t;

		for (size_t i = 0; i < rules.size(); ++i)
		{
			while ( (pos = text.find(rules[i].first)) != string::npos)
				text.replace(pos, rules[i].first.length(), rules[i].second);
		}

		printf("%s\n", text.c_str());
	}
	return 0;
} 

