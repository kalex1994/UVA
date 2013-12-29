#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int tc, n, iq, minIQ, maxIQ, maxDiff;

	cin >> tc;
	while (tc--)
	{
		cin >> n;

		maxIQ;
		maxDiff = INT_MIN;
		bool first = true;
		while (n--)
		{
			cin >> iq;

			if (first)
			{
				first = false;
				maxIQ = iq;
				minIQ = iq;
			}			
			else
			{
				maxDiff = max(maxDiff, max( maxIQ - iq , minIQ - iq) );
				if (iq > maxIQ) maxIQ = iq;
				if (iq < minIQ) minIQ = iq;
			}
		}
		cout << maxDiff << endl;
	}
	return 0;
}