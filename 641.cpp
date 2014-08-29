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
using namespace std;

const int MAXN = 70;
int k;
char message[MAXN + 1];

int encode(char ch)
{
	if (ch == '_') return 0;
	if (ch == '.') return 27;
	return ch - 'a' + 1;
}

char decode(int c)
{
	if (c == 0) return '_';
	if (c == 27) return '.';
	return c + 'a' - 1;
}

void decrypt()
{
	int plaincode[MAXN];
	int n = strlen(message);

	for(int i = 0; i < n; ++i)
	{
		int ciphercode = encode(message[i]);
		int index = k * i % n;
		plaincode[index] = (ciphercode + i) % 28;
	}

	for(int i = 0; i < n; ++i)
		putchar(decode(plaincode[i]));
	putchar('\n');
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(scanf("%d", &k) && k)
	{
		scanf("%s", message);
		decrypt();
	}
}