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

inline string nextLine()
{
	string line; getline(cin, line); return line;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
		
	int tests = atoi(nextLine().c_str());
	nextLine();

	while(tests--)
	{
		vector<string> fragments;
		string line;

		size_t minLength = 999, maxLength = 0;
		while( !(line = nextLine()).empty() )
		{
			fragments.push_back(line);
			if (line.size() < minLength)
				minLength = line.size();
			if (line.size() > maxLength)
				maxLength = line.size();
		}

		vector< pair<string, string> > files;
		for(int i = 0; i < (int)fragments.size() - 1; ++i)
			for(int j = i + 1; j < (int)fragments.size(); ++j)
				if (fragments[i].size() + fragments[j].size() == minLength + maxLength)
				{
					files.push_back(make_pair(fragments[i], fragments[j]));
					fragments.erase(fragments.begin() + i);
					--j;
					fragments.erase(fragments.begin() + j);
				}

		map<string, int> m;
		for(int i = 0; i < files.size(); ++i)
		{
			m[ files[i].first + files[i].second]++;
			m[ files[i].second + files[i].first]++;
		}

		int maxValue = 0;
		string answer;
		for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
			if(it->second > maxValue)
			{
				maxValue = it->second;
				answer = it->first;
			}
		cout << answer << endl;
		if (tests) cout << endl;
	}
	return 0;
}
