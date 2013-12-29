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

enum {IN, OUT, END} current;

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int ch;
	string s;
	current = OUT;

	while (true)
	{
		ch = getchar();

		switch (current)
		{
		case IN:
			if (ch == EOF)
			{
				reverse(s.begin(), s.end());
				printf("%s", s.c_str());
				current = END;
			}
			else if (isspace(ch))
			{
				reverse(s.begin(), s.end());
				printf("%s%c", s.c_str(), ch);
				current = OUT;
			}
			else
				s += ch;
			break;
		case OUT:
			if (ch == EOF)
			{
				current = END;
			}
			else if (isspace(ch))
			{
				putchar(ch);
			}
			else
			{
				s = "";
				s += ch;
				current = IN;
			}
			break;
		case END:
			return 0;
		}
	}
} 

