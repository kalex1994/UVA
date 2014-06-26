#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

map<char, int> values;

void init_values()
{
	const string s = "BUSPFTM";	
	for(size_t i = 0; i < s.length(); ++i)
		values[s[i]] = (int)pow(10, (double)i);
}

int convert(const string& s)
{
	int v = 0;
	int count = 1;

	if (values[s[0]] > values[s[s.length() - 1]])
	{
		for(int i = 0; i < s.length(); ++i)
		{
			if (i > 0)
			{
				if (s[i] == s[i - 1]) 
					++count;
				else 
					count = 1;
				if (values[s[i]] > values[s[i - 1]]) 
					return -1;
			}
			if (count > 9) 
				return -1;
			v += values[s[i]];
		}
	}
	else
	{
		for(int i = s.length() - 1; i >= 0; --i)
		{
			if (i < s.length() - 1)
			{
				if (s[i] == s[i + 1])
					++count;
				else 
					count = 1;
				if (values[s[i]] > values[s[i + 1]])
					return -1;
			}
			if (count > 9) 
				return -1;
			v += values[s[i]];
		}
	}
	return v;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	init_values();

	string s;
	int tests;

	cin >> tests;
	while(tests--)
	{
		cin >> s;
		int res = convert(s);
		if (res < 1)
			cout << "error" << endl;
		else
			cout << res << endl;
	}

}