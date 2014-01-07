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
#include <iomanip>
#include <stdint.h>
using namespace std;

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);

	bool inside_word;
	int word_count;
	char s[1000000];

	while (gets(s))
	{
		int len = strlen(s);
		inside_word = false;
		word_count = 0;

		for (int i = 0; i < len; ++i)
		{
			if (inside_word)
			{
				if (!isalpha(s[i])) inside_word = false;
			}
			else
			{
				if (isalpha(s[i]))
				{
					inside_word = true;
					++word_count;
				}
			}
		}

		printf("%d\n", word_count);
	}


	return 0;
} 

