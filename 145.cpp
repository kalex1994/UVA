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

enum RATE {DAY, EVENING, NIGHT};

double prices[70][3];

void init()
{
	prices['A'][DAY] = 0.1; prices['A'][EVENING] = 0.06; prices['A'][NIGHT] = 0.02;
	prices['B'][DAY] = 0.25; prices['B'][EVENING] = 0.15; prices['B'][NIGHT] = 0.05;
	prices['C'][DAY] = 0.53; prices['C'][EVENING] = 0.33; prices['C'][NIGHT] = 0.13;
	prices['D'][DAY] = 0.87; prices['D'][EVENING] = 0.47; prices['D'][NIGHT] = 0.17;
	prices['E'][DAY] = 1.44; prices['E'][EVENING] = 0.8; prices['E'][NIGHT] = 0.3;
}

const int dayStart = 480;
const int dayEnd = 1080;
const int eveningStart = 1080;
const int eveningEnd = 1320;
const int nightStart = 1320;
const int nightEnd = 480;

char chargingStep;
string number;
int h1, m1, h2, m2, callStart, callEnd;

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	init();

	while(cin >> chargingStep && chargingStep != '#')
	{
		cin >> number >> h1 >> m1 >> h2 >> m2;
		callStart = h1 * 60 + m1;
		callEnd = h2 * 60 + m2;

		int day = 0, evening = 0, night = 0;

		if (callStart == callEnd)
		{
			day = dayEnd - dayStart;
			evening = eveningEnd - eveningStart;
			night = 600;
		}
		else
		{
			for(int i = callStart + 1; ; ++i)
			{
				if (i == 1440) i = 0;

				if (i > dayStart && i <= dayEnd) 
					++day;
				else if (i > eveningStart && i <= eveningEnd)
					++evening;
				else 
					++night;

				if (i == callEnd)
					break;
			}
		}
		printf("%10s%6d%6d%6d%3c%8.2lf\n",number.c_str(),day,evening,night,chargingStep,
		(double)day * prices[chargingStep][DAY] + (double)evening * prices[chargingStep][EVENING] + (double)night * prices[chargingStep][NIGHT] );
	}
	return 0;
}


