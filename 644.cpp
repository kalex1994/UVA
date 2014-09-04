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

bool cmp(const string& a, const string& b)
{
	return a.length() < b.length();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	vector<string> s;
	string w;
	int test = 1;

	while(cin >> w)
	{
		s.clear();
		s.push_back(w);
		while(cin >> w && w != "9")
			s.push_back(w);
		sort(s.begin(), s.end(), cmp);

		bool flag = true;
		for(size_t i = 0; flag && i + 1 < s.size(); ++i)
			for(size_t j = i + 1; flag && j < s.size(); ++j)
				if (s[j].compare(0, s[i].length(), s[i]) == 0)
					flag = false;
		if (flag)
			printf("Set %d is immediately decodable\n", test++);
		else
			printf("Set %d is not immediately decodable\n", test++);
	}
}