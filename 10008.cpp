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
	if (a.second > b.second) return true;
	else if (a.second < b.second) return false;

	if (a.first < b.first) return true;
	return false;
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	scanf("%*d%*c");

	int ch;
	int freq[26] = {0};

	while ((ch = getchar()) != EOF)
		if (isalpha(ch))
			++freq[toupper(ch) - 'A'];

	vector< pair<int, int> > ans;
	for (int i = 0; i < 26; ++i)
		if (freq[i] > 0)
			ans.push_back(make_pair(i, freq[i]));

	sort(ans.begin(), ans.end(), cmp);

	for (size_t i = 0; i < ans.size(); ++i)
		printf("%c %d\n", ans[i].first + 'A', ans[i].second);

	return 0;
} 

