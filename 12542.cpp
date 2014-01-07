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

#define MAX 100000
bool is_prime[MAX + 5];

void sieve()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;

	for (int i = 4; i <= MAX; i += 2) 
		is_prime[i] = false;

	int limit = (int)sqrt(MAX);
	for (int i = 3; i <= limit; i += 2)
		for (int j = 2; i * j <= MAX; ++j)
			is_prime[i * j] = false;
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);   10625 uva

	sieve();

	string s;

	while (cin >> s && s != "0")
	{
		int max_prime = 2;
		for (int i = 0; i < 255; ++i)
			for (int j = 1; i + j < s.length() && j <= 6; ++j)
			{
				int num = atoi(s.substr(i, i + j).c_str());
				if (num > 100000) continue;
				if (num > max_prime && is_prime[num])
					max_prime = num;
			}
		cout << max_prime << endl;
	}

	return 0;
} 

