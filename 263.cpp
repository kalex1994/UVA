#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <functional>
using namespace std;

int reverse_number(int n)
{
	int result = 0;
	while (n)
	{
		result = result * 10 + n % 10;
		n /= 10;
	}
	return result;
}

int sorted_digits(int n)
{
	char buf[20];
	sprintf(buf, "%d", n);
	sort(buf, buf + strlen(buf), greater<char>());
	int result;
	sscanf(buf, "%d", &result);
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n, a, b, chain_length;
	set<int> used;

	while (cin >> n && n)
	{
		used.clear();
		chain_length = 0;

		printf("Original number was %d\n", n);
		while (true)
		{
			++chain_length;
			a = sorted_digits(n);
			b = reverse_number(a);
			n = a - b;

			printf("%d - %d = %d\n", a, b, n);
			if (used.find(n) != used.end())
				break;
			else
				used.insert(n);
		}
		printf("Chain length %d\n\n", chain_length);
	}
}