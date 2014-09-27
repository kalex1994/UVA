#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <stack>
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

	stringstream s1;
	s1 << 'n' << (unsigned char)243 << 's';
	stringstream s2;
	s2 << 'v' << (unsigned char)243 << 's';

	const string nos = s1.str();
	const string vos = s2.str();
	const string pronouns[] = {"eu", "tu", "ele/ela", nos, vos, "eles/elas"};
	const string conj12[] = {"o", "s", "", "mos", "is", "m"};
	const string conj3[] = {"o", "es", "e", "mos", "s", "em"};
	const bool needtv12[] = {false, true, true, true, true, true};
	const bool needtv3[] = {false, false, false, true, true, false};

	string portuguese, english;
	bool first = true;
	while(cin >> portuguese)
	{
		while(cin.peek() == ' ')
			cin.get();
		getline(cin, english);
		string suffix, root;
		if (portuguese.length() == 1)
		{
			root = "";
			suffix = ".";
		}
		else if (portuguese.length() == 2)
		{
			suffix = portuguese.substr((int)portuguese.length() - 2);
			root = "";
		}
		else
		{
			suffix = portuguese.substr((int)portuguese.length() - 2);
			root = portuguese.substr(0, (int)portuguese.length() - 2);
		}

		if (first)
			first = false;
		else
			putchar('\n');

		printf("%s (to %s)\n", portuguese.c_str(), english.c_str());
		for(int i = 0; i < 6; ++i)
		{
			if (suffix == "ar" || suffix == "er")
				printf("%-10s%s\n", pronouns[i].c_str(), (root + (needtv12[i] ? suffix.substr(0, 1) : "") + conj12[i]).c_str());
			else if (suffix == "ir")
				printf("%-10s%s\n", pronouns[i].c_str(), (root + (needtv3[i] ? suffix.substr(0, 1) : "") + conj3[i]).c_str());
			else
			{
				puts("Unknown conjugation");
				break;
			}
		}	
	}
}