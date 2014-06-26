#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

set<int> primes;

void init()
{
	int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	primes.insert(p, p + sizeof(p));
}

void print_solution(int *ring, int n)
{
	for(int i = 0; i < n; ++i)
	{
		if (i > 0) cout << " ";
		cout << ring[i];
	}
	cout << endl;
}

void solve(int *ring, int index, bool *used, int n)
{

	if (index == n)
	{
		if (primes.find(ring[0] + ring[index - 1]) != primes.end())
			print_solution(ring, n);
		return;
	}
	if (index == 0)
	{
		ring[index] = 1;
		used[1] = true;
		solve(ring, index + 1, used, n);
	}
	else
	{
		for(int i = index % 2 == 1 ? 2 : 3; i <= n; i += 2)
			if (!used[i])
				if (primes.find(ring[index - 1] + i) != primes.end())
				{
					ring[index] = i;
					used[i] = true;
					solve(ring, index + 1, used, n);
					used[i] = false;
				}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif
	init();

	int n;
	int ring[20];
	bool used[20];
	int case_number = 1;

	while(cin >> n)
	{
		if (case_number > 1)
			cout << endl;
		printf("Case %d:\n", case_number++);

		for(int i = 1; i <= n; ++i)
			used[i] = false;

		solve(ring, 0, used, n);
	}
}