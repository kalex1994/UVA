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

enum ACTUAL_STATE {GREEN, ORANGE, RED};

struct trafficLight
{
	int green, orange, red, time;
	ACTUAL_STATE current;

	trafficLight(int cycleTime)
	{
		green = cycleTime - 5;
		orange = 5;
		red = cycleTime;
		current = GREEN;
		time = 0;
	}

	void next()
	{
		++time;
		switch(current)
		{
		case GREEN:
			if (time == green)
			{
				time = 0;
				current = ORANGE;
			}
			break;
		case ORANGE:
			if (time == orange)
			{
				time = 0;
				current = RED;
			}
			break;
		case RED:
			if (time == red)
			{
				time = 0;
				current = GREEN;
			}
		}
	}

	bool isGreen()
	{
		return current == GREEN;
	}

	bool isRed()
	{
		return current == RED;
	}
};

vector<trafficLight> lights;

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	int a, b, c;

	while(true)
	{
		lights.clear();

		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) return 0;
		
		lights.push_back(trafficLight(a));
		lights.push_back(trafficLight(b));
		if (c != 0)
		{
			lights.push_back(c);
			while(cin >> a && a)
				lights.push_back(trafficLight(a));
		}

		bool switchedToOrange = false;
		bool synchronized = false;
		for(int i = 0; i <= 18000; ++i)
		{		
			for(int j = 0; j < (int)lights.size(); ++j)
				if (lights[j].isGreen() == false)
					switchedToOrange = true;

			bool allGreen = true;
			for(int j = 0; j < (int)lights.size(); ++j)
				if (lights[j].isGreen() == false)
					allGreen = false;

			if (allGreen && switchedToOrange)
			{
				printf("%02d:%02d:%02d\n", i / 3600, i / 60 - (60 * (i / 3600))  , i % 60);
				synchronized = true;
				break;
			}

			for(int j = 0; j < (int)lights.size(); ++j)
				lights[j].next();
		}
		if (!synchronized)
			cout << "Signals fail to synchronise in 5 hours" << endl;
	}
	return 0;
}


