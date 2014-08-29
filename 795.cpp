#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
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
using namespace std;

const int MAX_LEN = 108;
const int GROUP_LEN = 36;

char encrypted[MAX_LEN + 1];
char decrypted[MAX_LEN + 1];

const int holes[4][9] = 
{
	{1, 3, 5, 10, 14, 19, 22, 29, 33},
	{8, 11, 15, 18, 23, 26, 28, 31, 35},
	{2, 6, 13, 16, 21, 25, 30, 32, 34},
	{0, 4, 7, 9, 12, 17, 20, 24, 27}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(gets(encrypted))
	{
		strcpy(decrypted, "");
		size_t n = strlen(encrypted);
		for (size_t k = 0; k < n; k += GROUP_LEN)
		{
			for (size_t i = 0; i < 4; ++i)
				for (size_t j = 0; j < 9; ++j)
					decrypted[k + i * 9 + j] = encrypted[k + holes[i][j]];
		}
		decrypted[n] = '\0';
		if (n != 0)
			for(size_t i = 0, j = n - 1; i < j; ++i, --j)
				swap(decrypted[i], decrypted[j]);
			for (size_t i = n - 1; i >= 0 && decrypted[i] == '#'; --i)
				decrypted[i] = '\0';
		puts(decrypted);	
	}
}