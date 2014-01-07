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
	const char* s = "Peter should buy books whose prices are ";
	int n, l, r, money, ans_i, ans_j, s_len = strlen(s);
	int prices[10000 + 5];

	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
			get_int(prices[i]);
		get_int(money);

		sort(prices, prices + n);

		l = 0;
		r = n - 1;

		while (l < r)
		{
			int sum = prices[l] + prices[r];
			if (sum > money) --r;
			else if (sum < money) ++l;
			else
			{
				ans_i = prices[l];
				ans_j = prices[r];
				++l;
				--r;
			}
		}

		for (int i = 0; i < s_len; ++i)
			pc(s[i]);
		put_int(ans_i);
		pc(' '); pc('a'); pc('n'); pc('d'); pc(' ');
		put_int(ans_j);
		pc('.'); pc('\n'); pc('\n');
	}

	return 0;
} 

