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
	vector<string> surfaces;

	while(cin >> n && n)
	{
		cin.ignore(100, '\n');
		surfaces.resize(n);
		for(int i = 0; i < n; ++i)
			getline(cin, surfaces[i]);

		int count = 0;
		bool found = false;
		while(true)
		{
			for(int i = 0; i < n; ++i)
				if (surfaces[i].find(' ') == string::npos)
				{
					int count = 0;
					for(int k = 0; k < n; ++k)
						for(int m = 0; m < (int)surfaces[k].size(); ++m)
							if (surfaces[k][m] == ' ')
								++count;
					cout << count << endl;
					found = true;
					break;
				}

			if (found)
				break;

			for(int i = 0; i < n; ++i)
				surfaces[i].erase(surfaces[i].find(' '), 1);
		}
	}
	return 0;
}
