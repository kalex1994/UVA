#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <iterator>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
using namespace std;

deque<string> words;

void moveToFront(int index)
{
	string temp = words[index];
	words.erase(words.begin() + index);
	words.push_front(temp);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int ch, pos = 0;
	char s[55];

	while( (ch = getchar()) != '0' )
	{
		if (isdigit(ch))
		{
			int index;
			ungetc(ch, stdin);
			scanf("%d", &index);
			--index;
			printf("%s", words[index].c_str());
			moveToFront(index);
		}
		else
		{
			putchar(ch);

			if (isalpha(ch))
				s[pos++] = ch;
			else
			{
				if (pos != 0)
				{
					s[pos] = '\0';
					words.push_front(s);
					pos = 0;
				}
			}
		}
	}
}