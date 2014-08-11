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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int answer;
	double v_total, v_0, v, max_length;
	bool is_unique;

	while (cin >> v_total >> v_0)
	{
		if (v_total == 0.0 && v_0 == 0.0)
			break;

		max_length = -1.0;
		answer = -1;
		is_unique = true;

		for (int disks = 1;; ++disks)
		{
			v = v_total / disks;
			if (!(v > v_0)) break;

			double d = 0.3 * sqrt(v - v_0);
			double length = d * disks;

			if (!(fabs(length - max_length) > numeric_limits<double>::epsilon()))
			{
				is_unique = false;
				break;
			}
			else if (length > max_length)
			{
				max_length = length;
				answer = disks;
			}
		}

		if (answer > 0 && is_unique)
			cout << answer << endl;
		else cout << 0 << endl;
	}
}