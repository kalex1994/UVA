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
#include <unistd.h>
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
	int n, k;
	int ages[100] = { 0 };

	while (true)
	{
		get_int(n);
		if (n == 0) break;

		for (int i = 0; i < n; ++i)
		{
			get_int(k);
			++ages[k];
		}
		
		bool first = true;
		for (int i = 1; i < 100; ++i)
		{		
			if (ages[i] > 0)
			{
				while (ages[i] > 0)
				{
					if (first) first = false;
					else pc(' ');
					put_int(i);
					--ages[i];
				}
			}
		}
		pc('\n');
	}

	return 0;
} 

