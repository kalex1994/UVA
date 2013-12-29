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

bool isPrime(int k)
{
	if (k == 1) return false;
	if (k == 2) return true;

	for (int i = 2; i <= (int)sqrt(k); ++i)
		if (k % i == 0)
			return false;

	return true;
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int n;
	char s[2050];
	int freq[256];

	scanf("%d%*c", &n);
	for (int test = 1; test <= n; ++test)
	{
		memset(freq, 0, sizeof(freq));
		gets(s);

		size_t len = strlen(s);
		for (size_t i = 0; i < len; ++i)
			++freq[s[i]];

		string ans = "";
		for (size_t i = 0; i < 256; ++i)
			if (freq[i] > 0 && isPrime(freq[i]))
				ans += (char)i;

		printf("Case %d: %s\n", test, ans.empty() ? "empty" : ans.c_str());
	}

	return 0;
} 

