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
	int battleFields, greenCount, blueCount, soldier;
	
	cin >> tests;
	while(tests--)
	{
		priority_queue<int> greenArmy, blueArmy;

		cin >> battleFields >> greenCount >> blueCount;
		while(greenCount--)
		{
			cin >> soldier;
			greenArmy.push(soldier);
		}
		while(blueCount--)
		{
			cin >> soldier;
			blueArmy.push(soldier);
		}

		bool warEnd = false;
		while(true)
		{
			vector<int> toGreen, toBlue;

			for(int i = 0; i < battleFields; ++i)
			{
				if (!greenArmy.empty() && !blueArmy.empty())
				{
					int greenSoldier = greenArmy.top(); greenArmy.pop();
					int blueSoldier = blueArmy.top(); blueArmy.pop();

					if (greenSoldier > blueSoldier) toGreen.push_back(greenSoldier - blueSoldier);
					else if (blueSoldier > greenSoldier) toBlue.push_back(blueSoldier - greenSoldier);
				}
				else
				{
					if (!toGreen.empty() || !toBlue.empty()) continue;

					warEnd = true;

					if (greenArmy.empty() && blueArmy.empty()) cout << "green and blue died" << endl;
					else if (greenArmy.empty())
					{
						cout << "blue wins" << endl;
						while(!blueArmy.empty())
						{
							cout << blueArmy.top() << endl;
							blueArmy.pop();
						}
					}
					else
					{
						cout << "green wins" << endl;
						while(!greenArmy.empty())
						{
							cout << greenArmy.top() << endl;
							greenArmy.pop();
						}
					}
					break;
				}
			}

			for(int i = 0; i < (int)toGreen.size(); ++i) greenArmy.push(toGreen[i]);
			for(int i = 0; i < (int)toBlue.size(); ++i) blueArmy.push(toBlue[i]);
			if (warEnd) break;
		}
		if (tests) cout << endl;
	}
	return 0;
}
