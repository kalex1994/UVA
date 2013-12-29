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

bool isVowel(int ch)
{
	switch (tolower(ch))
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

void printPigLatin(string s, char ch)
{
	if (s.empty()) return;
	if (isVowel(s[0]))
	{
		s += "ay";
		printf("%s", s.c_str());
		if (ch != EOF)
			putchar(ch);
	}
	else
	{
		s += s[0];
		s += "ay";
		s.erase(s.begin());
		printf("%s", s.c_str());
		if (ch != EOF)
			putchar(ch);
	}
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int ch;
	current = OUT;
	string s;

	while (true)
	{
		ch = getchar();
		switch (current)
		{
		case IN:
			if (ch == EOF)
			{
				printPigLatin(s, ch);
				current = END;
			}
			else if (isalpha(ch))
			{
				s += ch;
			}
			else
			{
				printPigLatin(s, ch);
				current = OUT;
			}
			break;
		case OUT:
			if (ch == EOF)
			{
				current = END;
			}
			else if (isalpha(ch))
			{
				s = "";
				s += ch;
				current = IN;
			}
			else
				putchar(ch);
			break;
		case END:
			return 0;
		}
	}
} 

