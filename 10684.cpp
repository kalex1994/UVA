#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif

	int N;
	while (cin >> N && N)
	{
		int sum = 0, maxSum = -1, bet;
		for (int i = 0; i < N; ++i)
		{
			cin >> bet;
			sum += bet;
			maxSum = max(maxSum, sum);
			if (sum < 0)
				sum = 0;
		}

		if (sum > 0) printf("The maximum winning streak is %d.\n", maxSum);
		else puts("Losing streak.");
	}
	return 0;
}