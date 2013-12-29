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
#include <limits>
#include <list>
#include <sstream>
using namespace std;

int main()
{
	vector<string> lines;
	string line;
	size_t max_len = 0;

	while (getline(cin, line))
	{
		lines.push_back(line);
		if (line.length() > max_len)
			max_len = line.length();
	}

	for (size_t i = 0; i < max_len; ++i)
	{
		for (vector<string>::reverse_iterator j = lines.rbegin(); j != lines.rend(); ++j)
			if (i >= j->length())
				putchar(' ');
			else
				putchar((*j)[i]);
		putchar('\n');
	}

	return 0;
}
