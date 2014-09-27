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

const int MAXN = 1000000;
vector<int> primes;

void sieve()
{
	bool is_prime[MAXN + 1];
	fill(is_prime, is_prime + MAXN + 1, true);
	is_prime[0] = is_prime[1] = false;

	int sqrtn = sqrt(MAXN);

	for (int i = 4; i <= MAXN; i += 2)
		is_prime[i] = false;
	for (int i = 3; i <= sqrtn; i += 2)
	for (int j = i * i; j <= MAXN; j += i)
		is_prime[j] = false;

	primes.push_back(2);
	for (int i = 3; i <= MAXN; i += 2)
	if (is_prime[i])
		primes.push_back(i);
}

unsigned long long solve(int n)
{
	int l = 0, r = 0;
	unsigned long long answer = 0;

	while (primes[r] <= n)
		++r;
	--r;

	while (l < r)
	{
		if (primes[l] + primes[r] > n)
			--r;
		else
		{
			answer += (unsigned long long)(r - l);
			++l;
		}
	}
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	sieve();

	int n, test = 1;
	while (cin >> n && n)
	{
		cout << "Case " << test++ << ": ";
		cout << solve(n) << endl;
	}
}