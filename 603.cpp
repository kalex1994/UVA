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

struct car
{
	int initialPosition;
	int actualPosition;
	int parkingPosition;
	bool hasParked;

	car(int _initialPosition)
	{
		this->actualPosition = this->initialPosition = _initialPosition;
		this->parkingPosition = -1;
		this->hasParked = false;
	}

	void nextPosition()
	{
		++actualPosition;
		if (actualPosition == 21)
			actualPosition = 1;
	}
};

set<int> freePositions;
vector<car> waitingCars;
int dataSets;
string line;

bool allCarsParked()
{
	for(int i = 0; i < waitingCars.size(); ++i)
		if (waitingCars[i].hasParked == false)
			return false;
	return true;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	cin >> dataSets;
	getline(cin,line);
	getline(cin,line);

	while(dataSets--)
	{
		freePositions.clear();
		waitingCars.clear();

		while(getline(cin,line) && atoi(line.c_str()) != 99)
			waitingCars.push_back(car(atoi(line.c_str())));
		while(getline(cin,line) && line.size() != 0)
		{
			freePositions.insert(atoi(line.c_str()));

			while(freePositions.empty() == false && allCarsParked() == false)
			{
				for(int i = 0; i < (int)waitingCars.size(); ++i)
					if (waitingCars[i].hasParked == false)
					{
						int pos = waitingCars[i].actualPosition;
						if (freePositions.find(pos) != freePositions.end())
						{
							freePositions.erase(pos);
							waitingCars[i].parkingPosition = pos;
							waitingCars[i].hasParked = true;
						}
					}
				if (freePositions.empty() == false)
					for(int i = 0; i < (int)waitingCars.size(); ++i)	
						if (!waitingCars[i].hasParked)
							waitingCars[i].nextPosition();
			}
		}

		for(int i = 0; i < (int)waitingCars.size(); ++i)
			if (waitingCars[i].hasParked)
				printf("Original position %d parked in %d\n",waitingCars[i].initialPosition, waitingCars[i].parkingPosition);
			else
				printf("Original position %d did not park\n",waitingCars[i].initialPosition);
		if (dataSets)
			cout << endl;
	}
	return 0;
}


