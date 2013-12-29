#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
const ull ONE = 1;

int main()
{
	set<int> s;
	for (int i = 0; i <= 20; ++i)
	{
		s.insert(i);
		s.insert(2 * i);
		s.insert(3 * i);
	}

	vector<int> numbers(s.begin(), s.end());
	numbers.push_back(50);

	int score;
	while (cin >> score && score > 0)
	{
		set<ull> used;
		int combinations = 0, permutations = 0;

		for (size_t i = 0; i < numbers.size(); ++i)
		for (size_t j = 0; j < numbers.size(); ++j)
		for (size_t k = 0; k < numbers.size(); ++k)
		{
			if (numbers[i] + numbers[j] + numbers[k] == score)
			{
				++permutations;
				ull num = (ONE << numbers[i]) | (ONE << numbers[j]) | (ONE << numbers[k]);
				if (!used.count(num))
				{
					used.insert(num);
					++combinations;
				}
			}
		}

		if (!combinations && !permutations) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
		else
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combinations);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, permutations);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
}