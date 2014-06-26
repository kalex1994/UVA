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

set< vector<int> > solution;

void solve(int *numbers, int n, int index, int actual_sum, vector<int>& used_numbers)
{
	if (actual_sum == 0)
	{
		solution.insert(used_numbers);
		return;
	}
	if (index == n)
		return;

	if (actual_sum - numbers[index] >= 0)
	{
		used_numbers.push_back(numbers[index]);
		solve(numbers, n, index + 1, actual_sum - numbers[index], used_numbers);
		used_numbers.pop_back();
	}
	solve(numbers, n, index + 1, actual_sum, used_numbers);
}

void print_soution(int t)
{
	printf("Sums of %d:\n", t);
	if (solution.empty())
		printf("%s\n", "NONE");
	else
	{
		for(set< vector<int> >::reverse_iterator it = solution.rbegin(); it != solution.rend(); ++it)
		{
			for(size_t j = 0; j < it->size(); ++j)
			{
				if (j > 0) 
					printf("%c", '+');
				printf("%d", (*it)[j]);
			}
			printf("%c", '\n');
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int t, n;
	int numbers[12];

	while(true)
	{
		scanf("%d %d", &t, &n);
		if (n == 0)
			break;
		solution.clear();

		for(int i = 0; i < n; ++i)
			scanf("%d", &numbers[i]);

		vector<int> used_numbers;
		solve(numbers, n, 0, t, used_numbers);
		print_soution(t);
	}	
}