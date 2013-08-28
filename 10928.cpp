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
	
	int tests, P, minNeighbours;
	string line;
	vector< int > answer;

	cin >> tests;
	while(tests--)
	{
		answer.clear();

		cin >> P;
		cin.ignore(100, '\n');
		for(int i = 1; i <= P; ++i)
		{
			getline(cin, line);

			int neighbour, count;
			istringstream iss(line);

			count = 0;
			while(iss >> neighbour)
				++count;

			if (answer.empty())
			{
				minNeighbours = count;
				answer.push_back(i);
			}
			else if (count < minNeighbours)
			{
				minNeighbours = count;
				answer.clear();
				answer.push_back(i);
			}
			else if (count == minNeighbours)
				answer.push_back(i);
		}

		for(int i = 0; i < (int)answer.size(); ++i)
		{
			if (i > 0) cout << " ";
			cout << answer[i];
		}
		cout << endl;
	}
	return 0;
}
