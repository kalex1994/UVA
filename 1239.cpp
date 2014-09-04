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

char s[1005];
int k;

int greatest_k_palindrome()
{
	int len = strlen(s);
	int max_len = 0;

	for(int i = 0; i < len; ++i)
		for(int j = i; j < len; ++j)
		{
			int count = k;
			for(int left = i, right = j; left < right; ++left, --right)
			{
				if (s[left] != s[right])
				{
					--count;
					if (count < 0)
						break;
				}
			}
			if (count >= 0)
				max_len = max(max_len, j - i + 1);
		}
	return max_len;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;

	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%s %d", s, &k);
		printf("%d\n", greatest_k_palindrome());
	}
}