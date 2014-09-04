#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <stack>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <numeric>
#include <deque>
#include <map>
#include <iterator>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
#include <array>
#include <regex>
using namespace std;

vector<string> keywords;
vector<string> excuses;

int number_of_occurences(string ex, string kw)
{
	for(char &ch : ex)
		ch = tolower(ch);
	for(char &ch : kw)
		ch = tolower(ch);

	int count = 0;
	int pos = ex.find(kw);

	while(pos != string::npos)
	{
		if ((pos == 0 || !isalpha(ex[pos - 1])) && (pos + kw.length() >= ex.length() || !isalpha(ex[pos + kw.length()])))
			++count;
		pos = ex.find(kw, pos + 1);
	}
	return count;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int k, e, excuseset = 1;
	char s[500];

	while(scanf("%d %d%*c", &k, &e) == 2)
	{
		keywords.clear();
		excuses.clear();

		while(k--)
		{
			gets(s);
			keywords.push_back(s);
		}
		while(e--)
		{
			gets(s);
			excuses.push_back(s);
		}

		int max_count = -1;
		vector<string> answer;
		for(const string& ex : excuses)
		{
			int count = 0;
			for(const string& kw : keywords)
				count += number_of_occurences(ex, kw);
			if (count > max_count)
			{
				answer.clear();
				answer.push_back(ex);
				max_count = count;
			}
			else if (count == max_count)
				answer.push_back(ex);
		}

		cout << "Excuse Set #" << excuseset++ << endl;
		for(const string &ex : answer)
			cout << ex << endl;
		cout << endl;
	}
}