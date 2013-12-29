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

	const int MAX_LEN = 1000 + 5;
	char s1[MAX_LEN], s2[MAX_LEN];
	int freq1[256], freq2[256];

	while (gets(s1) != NULL)
	{
		memset(freq1, 0, sizeof(freq1));
		memset(freq2, 0, sizeof(freq2));

		gets(s2);

		int len = strlen(s1);
		for (int i = 0; i < len; ++i)
			++freq1[s1[i]];

		len = strlen(s2);
		for (int i = 0; i < len; ++i)
			++freq2[s2[i]];

		string ans = "";

		for (int i = 0; i < 256; ++i)
			if (freq1[i] > 0 && freq2[i] > 0)
				for (int j = 0; j < min(freq1[i], freq2[i]); ++j)
					ans += (char)i;

		sort(ans.begin(), ans.end());
		puts(ans.c_str());
	}

	return 0;
} 

