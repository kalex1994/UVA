#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
using namespace std;

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int n, q, k, case_num = 1;
	vector<int> numbers;

	while (cin >> n >> q && (n || q))
	{
		numbers.clear();
		while (n--)
		{
			cin >> k;
			numbers.push_back(k);
		}

		sort(numbers.begin(), numbers.end());

		printf("CASE# %d:\n", case_num++);
		while (q--)
		{
			cin >> k;
			vector<int>::iterator it = lower_bound(numbers.begin(), numbers.end(), k);
			if (it == numbers.end() || *it != k)
				printf("%d not found\n", k);
			else
				printf("%d found at %d\n", k, distance(numbers.begin(), it) + 1);
		}
	}

	return 0;
} 

