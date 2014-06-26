#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

void solve(string s, int n, int index, int count)
{
	if (index == n)
	{
		if (count == 0)
			cout << s << endl;
		return;
	}

	solve(s + "0", n, index + 1, count);
	solve(s + "1", n, index + 1, count - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, n, h;

	scanf("%d", &tests);
	while(tests--)
	{
		scanf("%d %d", &n, &h);
		solve("", n, 0, h);
		if (tests)
			putchar('\n');
	}
}