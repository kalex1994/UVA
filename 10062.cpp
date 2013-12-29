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

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second < b.second) return true;
	else if (a.second > b.second) return false;

	if (a.first > b.first) return true;
	return false;
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	const int MAX_LEN = 1000 + 5;
	char s[MAX_LEN];
	int frequency[130];
	bool first = true;

	while (gets(s) != NULL)
	{
		if (first) first = false;
		else putchar('\n');

		memset(frequency, 0, sizeof(frequency));
		int len = strlen(s);
		for (int i = 0; i < len; ++i)
			++frequency[s[i]];

		vector< pair<int, int> > ans;
		for (int i = 0; i < 130; ++i)
			if (frequency[i] != 0)
				ans.push_back(make_pair(i, frequency[i]));

		sort(ans.begin(), ans.end(), cmp);
		for (size_t i = 0; i < ans.size(); ++i)
			printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
} 

