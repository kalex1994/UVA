#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	for (ll a = 1; a <= 125; ++a)
	for (ll b = a; a + b < 2000; ++b)
	for (ll c = b; a + b + c < 2000; ++c)
	{
		ll sum = a + b + c;
		ll product = a * b * c;

		ll numerator = 1000000 * sum;
		ll denominator = product - 1000000;

		if (denominator > 0 && numerator % denominator == 0)
		{
			ll d = numerator / denominator;
			if (d >= c && sum + d <= 2000)
				printf("%0.2f %0.2f %0.2f %0.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);			
		}
	}
}