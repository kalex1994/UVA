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

	int n, answer;

	while(scanf("%d", &n) && n)
	{
		while(n--)
		{
			char res = '\0';
			for(int i = 0; i < 5; ++i)
			{
				scanf("%d", &answer);
				if (answer <= 127)
				{
					if (res == '\0')
						res = 'A' + i;
					else
						res = '*';
				}
			}
			if (res == '\0' || res == '*')
				putchar('*');
			else
				putchar(res);
			putchar('\n');
		}
	}
}