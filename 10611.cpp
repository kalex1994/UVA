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
#include <functional>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
using namespace std;

#ifdef linux
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc getchar
#define pc putchar
#endif

inline void get_int(int &x)
{
	int ch;

	while (ch = gc(), ch <= ' ')
		;

	x = ch - 48;
	while (ch = gc(), ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + ch - 48;
}

inline void put_int(int x)
{
	char buf[12], *p = buf;

	do
	{
		*p++ = x % 10 + 48;
		x /= 10;
	} while (x);

	do
	{
		pc(*--p);
	} while (p != buf);
}

int main()
{	
	int n, q, query;
	int heights[50000 + 5], *end;

	get_int(n);
	for (int i = 0; i < n; ++i)
		get_int(heights[i]);

	end = heights + n;

	get_int(q);
	while (q--)
	{
		get_int(query);

		int *p1 = lower_bound(heights, heights + n, query);
 		int *p2 = upper_bound(heights, heights + n, query);

		if (p1 == heights) pc('X');
		else put_int(*(p1 - 1));
		pc(' ');
		if (p2 == end) pc('X');
		else put_int(*p2);
		pc('\n');
	}
	return 0;
} 

