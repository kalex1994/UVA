#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<limits>
#include<sstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<list>
#include<iomanip>
#include<queue>
#include<cfloat>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n;
	int *numbers = new int[1000005];
	
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
			cin >> numbers[i];
		sort(numbers, numbers + n);

		if (n & 1)
		{
			int count = 0, median = numbers[n / 2];
			for(int i = 0; i < n; ++i)
				if (numbers[i] == median)
					++count;
			cout << median << " " << count << " " << 1 << endl;
		}
		else
		{
			int median1 = numbers[n / 2 - 1], median2 = numbers[n / 2], median3;
			int differentValues = median2 - median1 + 1;

			int count = 0;
			for(int i = 0; i < n; ++i)
				if (numbers[i] >= median1 && numbers[i] <= median2)
					++count;


			cout << median1 << " " << count << " " << differentValues << endl;
		}
	}
	delete [] numbers;
	return 0;
}
