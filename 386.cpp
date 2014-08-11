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
#include <cmath>
#include <set>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	for (int a = 2; a <= 200; ++a)
	for (int b = 2; b < a; ++b)
	for (int c = b; c < a; ++c)
	for (int d = c; d < a; ++d)
	if (a*a*a == b*b*b + c*c*c + d*d*d)
		printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
}