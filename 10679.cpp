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

	char s[100000 + 1], t[1000 + 1];
	int tests, q;

	scanf("%d%*c", &tests);
	while(tests--)
	{
		gets(s);
		scanf("%d%*c", &q);
		while(q--)
		{
			gets(t);
			if (strncmp(s, t, strlen(t)) == 0)
				puts("y");
			else
				puts("n");
		}
	}
}