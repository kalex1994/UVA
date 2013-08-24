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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;
	string line, temp;

	vector< pair<int, string> > permutations;

	cin >> tests; cin.ignore(100,'\n'); getline(cin, line);
	while(tests--)
	{
		permutations.clear();

		getline(cin, line);
		stringstream ss;
		ss << line;
		while(ss >> temp)
			permutations.push_back( make_pair( atoi(temp.c_str()), "" ) );

		getline(cin, line);

		stringstream ss2;
		ss2 << line;
		int index = 0;
		while(ss2 >> temp)
		{
			permutations[index].second = temp;
			++index;
		}

		sort(permutations.begin(), permutations.end());

		for(int i = 0; i < (int)permutations.size(); ++i)
			cout << permutations[i].second << endl;

		if (tests) cout  << endl;

		getline(cin, line);
	}
	return 0;
}




