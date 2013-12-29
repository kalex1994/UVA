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

	size_t n;
	string s;
	map<string, int> f;

	while (cin >> n >> s)
	{
		f.clear();
		for (size_t i = 0; i + n < s.length(); ++i)
			++f[s.substr(i, n)];

		int max = 0;
		string ans = "";
		for (map<string, int>::iterator it = f.begin(); it != f.end(); ++it)
		{
			if (it->second > max)
			{
				max = it->second;
				ans = it->first;
			}
		}

		cout << ans << endl;
	}
	return 0;
} 

