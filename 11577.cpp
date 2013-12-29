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

	int n;
	int freq[26];
	char s[200];

	scanf("%d%*c", &n);
	while (n--)
	{
		memset(freq, 0, sizeof(freq));
		gets(s);
		size_t len = strlen(s);
		for (size_t i = 0; i < len; ++i)
			if (isalpha(s[i]))
				++freq[tolower(s[i]) - 'a'];

		int max = 0;
		for (size_t i = 0; i < 26; ++i)
			if (freq[i] > max)
				max = freq[i];

		string ans = "";
		for (size_t i = 0; i < 26; ++i)
			if (freq[i] == max)
				ans += (i + 'a');
		
		printf("%s\n", ans.c_str());
	}


	return 0;
} 

