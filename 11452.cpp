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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n;
	char s[2005];

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		int len = strlen(s);

		for(int i = len / 2; i > 0; --i)
			if (strncmp(s, s + i, i) == 0)
			{
				int pos = len % i;
				for(int k = 0; k < 8; ++k, pos = (pos + 1) % i)
					putchar(s[pos]);
				break;
			}
		puts("...");
	}
}