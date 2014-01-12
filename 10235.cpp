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

const int MAX = 1000000;

bitset<MAX + 5> is_prime;

void sieve()
{
	is_prime.set();
	is_prime[0] = is_prime[1] = false;

	for (int i = 4; i <= MAX; i += 2) 
		is_prime[i] = false;

	for (int i = 3; i <= (int)sqrt(MAX); i += 2)
		for (int j = 3; i * j <= MAX; j += 2)
			is_prime[i * j] = false;
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout); 

	sieve();

	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (is_prime[n])
		{
			int k = 0, p = n;

			while (p)
			{
				k = k * 10 + p % 10;
				p /= 10;
			}

			if (is_prime[k] && k != n) printf("%d is emirp.\n", n);
			else printf("%d is prime.\n", n);
		}
		else
			printf("%d is not prime.\n", n);
	}

	return 0;
} 

