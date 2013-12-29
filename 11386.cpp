#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>
using namespace std;

typedef unsigned long ul;

int main()
{
	ul n, k;
	map<ul, ul> f;
	
	while (scanf("%ul", &n) != EOF)
	{
		f.clear();
		for (int i = 0; i < n; ++i)
		{
			scanf("%ul", &k);
			++f[k];
		}

		vector<ul> numbers;
		for (map<ul, ul>::iterator it = f.begin(); it != f.end(); ++it)
			numbers.push_back(it->first);

		ul answer = 0;
		for (int z = (int)numbers.size() - 1; z > 0; --z)
		{
			int left = 0, right = z - 1;
			while (left <= right)
			{
				if (numbers[left] + numbers[right] < numbers[z]) ++left;
				else if (numbers[left] + numbers[right] > numbers[z]) --right;
				else
				{
					if (left == right)
					{
						if (f[numbers[left]] > 1)
							answer += f[numbers[z]] * f[numbers[left]] * (f[numbers[left]] - 1) / 2;
					}
					else 
						answer += f[numbers[z]] * f[numbers[left]] * f[numbers[right]];
					++left; --right;
				}
			}
		}
		printf("%lu\n", answer);
	}
	return 0;
}