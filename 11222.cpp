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

bool solved[3][10005];
vector<int> solvedUnique[3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, count, solvedProblem, caseNumber = 1;

	cin >> tests;
	while(tests--)
	{
		memset(solved, false, sizeof(solved));
		solvedUnique[0].clear(); solvedUnique[1].clear(); solvedUnique[2].clear();

		for (int i = 0; i < 3; ++i)
		{
			cin >> count;
			for (int j = 0; j < count; ++j)
			{
				cin >> solvedProblem;
				solved[i][solvedProblem] = true;
			}
		}

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 10005; ++j)
				if ( solved[i][j] && !solved[ (i + 1) % 3 ][j] && !solved[ (i + 2) % 3 ][j] )
					solvedUnique[i].push_back(j);

		int maxProblemsSolved = solvedUnique[0].size();
		if (solvedUnique[1].size() > maxProblemsSolved) maxProblemsSolved = solvedUnique[1].size();
		if (solvedUnique[2].size() > maxProblemsSolved) maxProblemsSolved = solvedUnique[2].size();

		printf("Case #%d:\n", caseNumber++);
		for(int i = 0; i < 3; ++i)
			if ((int)solvedUnique[i].size() == maxProblemsSolved)
			{
				cout << i + 1 << " " << maxProblemsSolved;				
				for(int j = 0; j < (int)solvedUnique[i].size(); ++j)
					cout << " " << solvedUnique[i][j];
				cout << endl;
			}
	}
	return 0;
}




