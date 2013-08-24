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

map<string, int> courses;

string makeKey(string &s)
{
	vector<string> numbers;
	string token;
	istringstream iss(s);

	while(iss >> token)
		numbers.push_back(token);

	sort(numbers.begin(), numbers.end());

	string key = "";
	for(int i = 0; i < (int)numbers.size(); ++i)
		key += numbers[i];

	return key;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n;
	string line;

	while(getline(cin, line))
	{
		n = atoi(line.c_str());
		if (n == 0) break;

		courses.clear();
		while(n--)
		{
			getline(cin, line);
			++courses[makeKey(line)];
		}

		int max = 0;
		for(map<string, int>::iterator it = courses.begin(); it != courses.end(); ++it)
			if (it->second > max)
				max = it->second;

		int count = 0;
		for(map<string, int>::iterator it = courses.begin(); it != courses.end(); ++it)
			if (it->second == max)
				count += max;

		cout << count << endl;
	}
	return 0;
}
