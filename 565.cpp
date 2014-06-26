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
#include <limits>
#include <set>
using namespace std;

int order[256];
string requests[15];
int n;
bool found;

void solve(int index)
{
	if (index == n)
	{
		if (!found)
		{
			found = true;	
			cout << "Toppings: ";
			for(char ch = 'A'; ch <= 'P'; ++ch)
				if (order[ch] > 0)
					cout << ch;
			cout << endl;
		}
		return;
	}

	for(size_t i = 0; requests[index][i] != ';'; i += 2)
	{
		if (requests[index][i] == '-')
		{
			if (order[requests[index][i+1]] > 0) return;
			int temp = order[requests[index][i+1]];
			order[requests[index][i+1]] = -1;
			solve(index + 1);
			order[requests[index][i+1]] = temp;
		}
		else
		{
			if (order[requests[index][i+1]] < 0) return;
			int temp = order[requests[index][i+1]];
			order[requests[index][i+1]] = 1;
			solve(index + 1);
			order[requests[index][i+1]] = temp;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string s;
	while(true)
	{
		for(int i = 0; i < 15; ++i)
			order[i] = 0;

		found = false;
		if (!(cin >> s))
			break;

		requests[0] = s;
		n = 1;

		while(cin >> s && s != ".")
			requests[n++] = s;

		solve(0);
		if (!found)
			cout << "No pizza can satisfy these requests." << endl;
	}
}