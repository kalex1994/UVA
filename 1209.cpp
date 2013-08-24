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

int getMinimumAbsoluteDistance(string &username)
{
	int min = 0;
	for(int i = 1; i < (int)username.size(); ++i)
		if (min == 0) min = abs(username[i] - username[i-1]);
		else if (abs(username[i] - username[i-1]) < min)
			min = abs(username[i] - username[i-1]);
	return min;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	vector<string> permutations;
	string username, temp, answer;

	while(cin >> username)
	{
		permutations.clear();

		temp = username;
		for(int i = 0; i < 10 && prev_permutation(temp.begin(), temp.end()); ++i)
			permutations.push_back(temp);
		reverse(permutations.begin(), permutations.end());
		permutations.push_back(username);
		temp = username;
		for(int i = 0; i < 10 && next_permutation(temp.begin(), temp.end()); ++i)
			permutations.push_back(temp);

		int max = 0;

		for(int i = 0; i < (int)permutations.size(); ++i)
		{
			if (i == 0)
			{
				answer = permutations[i];
				max = getMinimumAbsoluteDistance(permutations[i]);
			}
			else if (getMinimumAbsoluteDistance(permutations[i]) > max)
			{
				answer = permutations[i];
				max = getMinimumAbsoluteDistance(permutations[i]);
			}
		}
		cout << answer << max << endl;
	}
	return 0;
}