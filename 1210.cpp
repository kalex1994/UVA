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
#include <bitset>
#include <stdint.h>
using namespace std;

const int MAX = 10000;
vector<int> primes;

void sieve()
{
	bitset<MAX + 5> is_prime;
	is_prime.set();

	is_prime[0] = is_prime[1] = false;
	is_prime[2] = true;

	for (int i = 4; i <= MAX; i += 2) 
		is_prime[i] = false;

	for (int i = 3; i <= MAX; i += 2)
		for (int j = 2; i * j <= MAX; ++j)
			is_prime[i * j] = false;

	for (int i = 0; i <= MAX; ++i)
		if (is_prime[i])
			primes.push_back(i);
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout); 

	sieve();

	int k;
	while (scanf("%d", &k) == 1 && k)
	{
		int count = 0;

		for (size_t i = 0; i < primes.size(); ++i)
		{
			if (primes[i] > k) break;
			if (primes[i] == k)
			{
				++count;
				break;
			}

			int sum = primes[i];
			size_t j = i + 1;

			while (j < primes.size() && sum < k)
			{
				sum += primes[j];
				if (sum == k) ++count;
				++j;
			}
		}
	
		printf("%d\n", count);
	}
	
	return 0;
} 

