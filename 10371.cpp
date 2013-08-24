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
	
map<string,int> D;

void init()
{
	D["UTC"] = 0;
	D["GMT"] = 0;
	D["BST"] = 60;
	D["IST"] = 60;
	D["WET"] = 0;
	D["WEST"] = 60;
	D["CET"] = 60;
	D["CEST"] = 120;
	D["EET"] = 120;
	D["EEST"] = 180;
	D["MSK"] = 180;
	D["MSD"] = 240;
	D["AST"] = -240;
	D["ADT"] = -180;
	D["NST"] = -210;
	D["NDT"] = -150;
	D["EST"] = -300;
	D["EDT"] = -240;
	D["CST"] = -360;
	D["CDT"] = -300;
	D["MST"] = -420;
	D["MDT"] = -360;
	D["PST"] = -480;
	D["PDT"] = -420;
	D["HST"] = -600;
	D["AKST"] = -540;
	D["AKDT"] = -480;
	D["AEST"] = 600;
	D["AEDT"] = 660;
	D["ACST"] = 570;
	D["ACDT"] = 630;
	D["AWST"] = 480;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, time;
	string line, timeZone1, timeZone2;

	init();
	cin >> tests; cin.ignore(100,'\n');
	while(tests--)
	{
		getline(cin,line);
		istringstream iss(line);
		string temp;

		iss >> temp;
		if (temp[0] == 'n' || temp[0] == 'm')
			time = temp[0] == 'm' ? 0 : 720;
		else
		{
			int h, m;
			sscanf(temp.c_str(),"%d:%d",&h,&m);
			time = h * 60 + m;
			iss >> temp;
			if (temp[0] == 'a' && time > 720)
				time -= 720;
			if (temp[0] == 'p' && time < 720)
				time += 720;
		}
		iss >> timeZone1 >> timeZone2;

		time -= D[timeZone1];
		time += D[timeZone2];

		if (time >= 1440) time -= 1440;
		if (time < 0) time = 1440 - abs(time);

		if (time == 0) cout << "midnight" << endl;
		else if (time == 720) cout << "noon" << endl;
		else
		{
			int hour = time / 60;
			int minute = time % 60;
			string ampm = "a.m.";

			if (hour == 0)
			{
				hour = 12;
				ampm = "a.m.";
			}
			else if (hour >= 12)
			{
				if (hour > 12)
					hour -= 12;
				ampm = "p.m.";
			}
			printf("%d:%02d %s\n", hour, minute, ampm.c_str());
		}
	}
	return 0;
}


