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

int G, P, S, K;
vector< vector<int> > races;
vector< vector<int> > scoring;
vector<int> points;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	while(cin >> G >> P && (G || P))
	{
		races.assign(G, vector<int>(P, 0));
		for(int i = 0; i < G; ++i)
			for(int j = 0; j < P; ++j)
			{
				int pos;
				cin >> pos;
				races[i][pos - 1] = j + 1;
			}

		cin >> S;
		scoring.clear();
		while(S--)
		{
			cin >> K;
			scoring.push_back(vector<int>(K));
			for(int i = 0; i < K; ++i)
				cin >> scoring.back()[i];
		}

		for(int i = 0; i < (int)scoring.size(); ++i)
		{
			points.assign(P, 0);

			for(int j = 0; j < (int)races.size(); ++j)
				for(int k = 0; k < (int)scoring[i].size(); ++k)
					points[ races[j][k] - 1 ] += scoring[i][k];

			int maxPoint = *max_element(points.begin(), points.end());
			bool isFirst = true;
			for(int c = 0; c < (int)points.size(); ++c)
				if (points[c] == maxPoint)
				{
					if (isFirst) 
						isFirst = false;
					else 
						cout << " ";
					cout << c + 1;
				}
			cout << endl;			
		}
	}
	return 0;
}
