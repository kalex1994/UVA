#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
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

	int tests, ch, letter;
	scanf("%d%*c", &tests);

	for(int test = 1; test <= tests; ++test)
	{
		printf("Case %d: ", test);
		while((ch = getchar()) != '\n')
		{
			if(isdigit(ch))
			{
				int count;
				ungetc(ch, stdin);
				scanf("%d", &count);
				for(int i = 0; i < count; ++i)
					putchar(letter);
			}
			else
				letter = ch;
		}
		putchar('\n');
	}

}