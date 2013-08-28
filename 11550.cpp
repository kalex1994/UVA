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
	
	int tests, V, E;
	string columns[30];
	char ch;
	
	cin >> tests;
	while(tests--)
	{
		cin >> V >> E;

		for(int i = 0; i < E; ++i)
			columns[i] = "";

		bool isSimpleGraph = true;
		for(int i = 0; i < V; ++i)
		{
			for(int j = 0; j < E; ++j)
			{
				cin >> ch;
				columns[j] += ch;
			}
		}

		for(int i = 0; i < E; ++i)
		{
			int count = 0;
			for(int j = 0; j < V; ++j)
				if (columns[i][j] == '1')
					++count;
			if (count != 2)
			{
				isSimpleGraph = false;
				break;;
			}
		}

		for(int i = 0; i < E; ++i)
			for(int j = 0; j < E; ++j)
				if(i != j && columns[i] == columns[j])
					isSimpleGraph = false;

		if (isSimpleGraph) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
