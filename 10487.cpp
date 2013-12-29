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
	int n, m, s, caseNum = 1;

	vector<int> numbers, sums;

	while (cin >> n, n)
	{
		numbers.resize(n);
		sums.clear();

		for (int i = 0; i < n; ++i) cin >> numbers[i];

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				sums.push_back(numbers[i] + numbers[j]);

		printf("Case %d:\n", caseNum++);

		cin >> m;	
		for (int i = 0; i < m; ++i)
		{
			int ans, minDiff = INT_MAX;
			cin >> s;
			for (int j = 0; j < (int)sums.size(); ++j)
			if (abs(sums[j] - s) < minDiff)
			{
				minDiff = abs(sums[j] - s);
				ans = sums[j];
			}

			printf("Closest sum to %d is %d.\n", s, ans);
		}		
	}
	return 0;
}