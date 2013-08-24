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

vector<string> instructions;
int baits;

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	int tests;
	string line;

	cin >> tests; getline(cin,line);
	getline(cin,line);

	while(tests--)
	{
		instructions.clear();
		baits = 0;

		while(getline(cin,line) && line.empty() == false)
			instructions.push_back(line);

		int instuctionCount = 0;
		int lastFish = 0;
		bool firstFish = true;
		int fishCount = 0;

		for(int i = 0; i < (int)instructions.size(); ++i)
		{
			++instuctionCount;
			if (instructions[i] == "fish")
			{
				++lastFish;
				if (firstFish)
				{
					if (baits >= 2)
					{
						baits -= 2;
						fishCount++;
						firstFish = false;
					}
				}
				else if (instuctionCount >= 7 && lastFish >= 3)
				{
					if (baits >= 2)
					{
						baits -= 2;
						fishCount++;
						instuctionCount = lastFish = 0;
					}
				}
			}
			else if (instructions[i] == "bait")
			{
				if (baits < 6)
					++baits;
			}
		}

		cout << fishCount << endl;
		if (tests) cout << endl;
	}
	return 0;
}


