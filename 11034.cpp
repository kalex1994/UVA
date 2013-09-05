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
#include<climits>

using namespace std;

enum SIDE {LEFT, RIGHT} currentSide;
queue<int> cars[2];
int tests, l, m, cm;
string side;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	cin >> tests;
	while(tests--)
	{
		while(!cars[LEFT].empty()) cars[LEFT].pop();
		while(!cars[RIGHT].empty()) cars[RIGHT].pop();

		cin >> l >> m;
		l *= 100;

		while(m--)
		{
			cin >> cm >> side;
			if (side[0] == 'l')
				cars[LEFT].push(cm);
			else
				cars[RIGHT].push(cm);
		}

		currentSide = LEFT;
		int turns = 0;
		while( cars[LEFT].empty() == false || cars[RIGHT].empty() == false )
		{
			if (!cars[currentSide].empty())
			{
				int sumOfLength = 0;
				while(cars[currentSide].empty() == false && sumOfLength + cars[currentSide].front() <= l)
				{
					sumOfLength += cars[currentSide].front();
					cars[currentSide].pop();
				}
			}
			++turns;
			currentSide = currentSide == LEFT ? RIGHT : LEFT;
		}

		cout << turns << endl;
	}
	return 0;
}