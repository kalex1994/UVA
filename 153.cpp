#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef unsigned long long ull;

ull number_of_permutations(ull n, const vector<ull>& d)
{
	vector<ull> numerator;
	for (int i = 2; i <= n; ++i)
		numerator.push_back(i);

	vector<ull> denominator;
	for (ull k : d)
		for (int i = 2; i <= k; ++i)
			denominator.push_back(i);

	for (size_t i = 0; i < denominator.size(); ++i)
		for (size_t j = 0; j < numerator.size(); ++j)
			if (numerator[j] > 1 && numerator[j] % denominator[i] == 0)
			{
				numerator[j] /= denominator[i];
				denominator[i] = 1;
				break;
			}

	ull result = 1;
	for (ull i : numerator)
		result *= i;
	for (ull i : denominator)
		result /= i;
	return result;
}

ull number_of_lesser_permutations(const string& s)
{
	int freq[26];
	fill(freq, freq + 26, 0);
	for (char ch : s)
		++freq[ch - 'a'];

	bool is_lesser[26];
	fill(is_lesser, is_lesser + 26, false);
	for (size_t i = 1; i < s.length(); ++i)
		if (s[i] < s[0])
			is_lesser[s[i] - 'a'] = true;

	ull answer = 0;
	for (int i = 0; i < 26; ++i)
		if (is_lesser[i])
		{
			freq[i]--;
			ull numerator = (ull)s.length() - 1;
			vector<ull> denominator;
			for (int j = 0; j < 26; ++j)
				if (freq[j] > 1)
					denominator.push_back(freq[j]);
			answer += number_of_permutations(numerator, denominator);
			freq[i]++;
		}
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string s;
	while (cin >> s && s != "#")
	{
		ull index = 0;
		for (size_t i = 0; i + 1 < s.length(); ++i)
			index += number_of_lesser_permutations(s.substr(i));
		printf("%10llu\n", index + 1);
	}
}