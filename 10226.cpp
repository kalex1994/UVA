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

using namespace std;

map<string, int> species;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, count;
	string line;

	cin >> tests; cin.ignore(100, '\n'); getline(cin,line);
	while(tests--)
	{
		species.clear();
		count = 0;

		while(getline(cin,line) && !line.empty())
		{
			++count;
			if (species.count(line) == 0)
				species[line] = 1;
			else ++species[line];
		}

		for(map<string,int>::const_iterator it = species.begin(); it != species.end(); ++it)
			printf("%s %0.4lf\n", it->first.c_str(), (double)it->second * 100 / (double)count);
		if (tests) cout << endl;
	}
	return 0;
}




