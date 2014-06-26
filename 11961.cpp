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

const string DNA = "ACGT";
set<string> mutations;

void mutate(string s, int start, int limit)
{
	if (limit == 0)
	{
		mutations.insert(s);
		return;
	}
	if (start >= s.length())
		return;

	for(int i = start; i < s.length(); ++i)
		for(int j = 0; j < DNA.length(); ++j)
			if (s[i] != DNA[j])
			{
				char temp = s[i];
				s[i] = DNA[j];
				mutate(s, i + 1, limit - 1);
				s[i] = temp;
			}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, n, k;
	string s;

	cin >> tests;
	while(tests--)
	{
		cin >> n >> k >> s;
		mutations.clear();
		mutations.insert(s);
		for(int i = 1; i <= k; ++i)
			mutate(s, 0, i);

		cout << mutations.size() << endl;
		for(set<string>::iterator it = mutations.begin(); it != mutations.end(); ++it)
			cout << *it << endl;
	}


}