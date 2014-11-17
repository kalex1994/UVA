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
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
using namespace std;

const int MAXN = 50000000;
const int MAXP = 4000000;
const int sqrtN = sqrt(MAXN + 1);

int primes[MAXP];
int size;

void sieve()
{
	vector<char> p(MAXN + 1, true);
	for(int i = 3; i <= sqrtN; i += 2)
		if (p[i])
			for(int j = i * i; j <= MAXN; j += 2 * i)
				p[j] = false;

	primes[size++] = 2; primes[size++] = 3; primes[size++] = 5;
	for(int i = 7, d = 4; i <= MAXN; i += d, d = 6 - d)
		if (p[i])
			primes[size++] = i;
}

bool is_prime(int n)
{
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	int sq = sqrt(n);
	for(int i = 0; primes[i] <= sq; ++i)
		if (n % primes[i] == 0)
			return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	sieve();

	int n;
	while(scanf("%d", &n) == 1)
	{
		if (n <= 4)
		{
			printf("%d is not the sum of two primes!\n", n);
			continue;
		}
		if (n % 2 == 1)
		{
			if (is_prime(n - 2))
				printf("%d is the sum of %d and %d.\n", n, 2, n - 2);
			else
				printf("%d is not the sum of two primes!\n", n);
			continue;
		}

		int pos = distance(primes, lower_bound(primes, primes + size, n / 2));
		if (pos == size) --pos;
		while(pos > 0 && primes[pos] > n / 2) --pos;

		bool found = false;
		while(pos >= 0)
		{
			if (n != 2 * primes[pos] && is_prime(n - primes[pos]))
			{
				printf("%d is the sum of %d and %d.\n", n, primes[pos], n - primes[pos]);
				found = true;
				break;
			}
			--pos;
		}
		if (!found)
			printf("%d is not the sum of two primes!\n", n);
	}

}