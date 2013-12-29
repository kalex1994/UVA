#include <cstdio>
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
#include <limits>
#include <list>
#include <sstream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	string line;
	bool first = true;
	int count = 0;

	while (getline(cin, line))
	{
		if (first) first = false;
		else putchar('\n');

		do
		{
			for (size_t i = 0; i < line.length(); ++i)
			{
				if (!isdigit(line[i]))
				{
					if (line[i] == '!')
						putchar('\n');
					else
						for (int k = 0; k < count; ++k)
							putchar(line[i] == 'b' ? ' ' : line[i]);
					count = 0;
				}
				else
					count += line[i] - '0';
			}

			putchar('\n');

		} while (getline(cin, line) && !line.empty());
	}

	return 0;
}
