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

vector< pair<int, int> > transposedMatrix[10005];
vector<int> colIndexes;
int rows, cols;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> rows >> cols)
	{
		for(int i = 1; i <= cols; ++i)
			transposedMatrix[i].clear();

		for(int i = 1; i <= rows; ++i)
		{
			int k;
			cin >> k;
			colIndexes.resize(k);

			for(int j = 0; j < k; ++j)
				cin >> colIndexes[j];

			int element;
			for(int j = 0; j < k; ++j)
			{
				cin >> element;
				transposedMatrix[ colIndexes[j] ].push_back( make_pair(i, element) );
			}
		}

		cout << cols << " " << rows << endl;
		for(int i = 1; i <= cols; ++i)
		{
			cout << transposedMatrix[i].size();

			for(int j = 0; j < (int)transposedMatrix[i].size(); ++j)
				cout << " " << transposedMatrix[i][j].first;
			cout << endl;

			for(int j = 0; j < (int)transposedMatrix[i].size(); ++j)
			{
				if (j > 0) cout << " ";
				cout << transposedMatrix[i][j].second;
			}
			cout << endl;
		}
	}	
	return 0;
}
