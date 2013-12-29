#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>
using namespace std;

typedef unsigned long ul;

ul f(ul n)
{
	ul ans = 0;
	while (n)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

ul g(ul n)
{
	while (f(n) >= 10)
		n = f(n);
	return f(n);
}

int main()
{
	ul n;
	while (cin >> n && n)
		cout << g(n) << endl;
	return 0;
}