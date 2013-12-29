#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int SIZE = 1000 + 5;
int numbers[SIZE];
int N;

int solve()
{
	for (int d = N - 1; d >= 0; --d)
		for (int a = 0; a < N; ++a)
			for (int b = a + 1; b < N; ++b)
				for (int c = b + 1; c < N; ++c)
					if (numbers[d] == numbers[a] + numbers[b] + numbers[c] && a != d && b != d && c != d)
						return numbers[d];
	return INT_MAX;
}

int main()
{
	while (cin >> N && N)
	{
		for (int i = 0; i < N; ++i)
			cin >> numbers[i];
		sort(numbers, numbers + N);

		int ans = solve();
		if (ans == INT_MAX) cout << "no solution";
		else cout << ans;
		cout << endl;
	}
}