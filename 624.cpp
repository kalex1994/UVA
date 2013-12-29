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

int tracks[25];
int N, T, maxLength, used;

int main()
{
	while (cin >> N)
	{
		cin >> T;
		for (int i = 0; i < T; ++i)
			cin >> tracks[i];

		maxLength = INT_MIN;
		for (int i = 0; i < (1 << T); ++i)
		{
			int sum = 0;
			for (int j = 0; j < T; ++j)
				if (i & (1 << j))
				{
					sum += tracks[j];
					if (sum > N)
						break;
				}
			if (sum <= N && sum > maxLength)
			{
				maxLength = sum;
				used = i;
			}
		}

		bool first = true;
		for (int i = 0; i < T; ++i)
		if (used & (1 << i))
		{
			if (first) first = false;
			else cout << ' ';
			cout << tracks[i];
		}
		cout << " sum:" << maxLength << endl;
	}
}