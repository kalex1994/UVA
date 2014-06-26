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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	set<string> words;
	set<string> result;
	char word[1000];

	while(scanf("%s", word) != EOF)
		words.insert(word);

	for(set<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		const string &s = *it;
		for(size_t i = 1; i < s.length(); ++i)
		{
			string a = s.substr(0, i);
			string b = s.substr(i);

			if (words.find(a) != words.end() && words.find(b) != words.end())
			{
				result.insert(s);
				break;
			}
		}
	}

	for(set<string>::iterator it = result.begin(); it != result.end(); ++it)
		puts(it->c_str());
}