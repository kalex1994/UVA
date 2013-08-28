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

struct record
{
	int day, hour, minute, distance;
	bool isEnter;

	record (int _day, int _hour, int _minute, int _distance, string &action)
	{
		this->day = _day;
		this->hour = _hour;
		this->minute = _minute;
		this->distance = _distance;
		this->isEnter = action == "enter";
	}
};

bool recordcmp(record a, record b)
{
	if (a.day != b.day) return a.day < b.day;
	if (a.hour != b.hour) return a.hour < b.hour;
	return a.minute < b.minute;
}

map<string, vector<record> > m; 
int toll[24];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
		
	int tests;

	cin >> tests;
	cin.ignore(100, '\n');
	cin.ignore(100, '\n');

	while(tests--)
	{
		m.clear();

		for(int i = 0; i < 24; ++i)
			cin >> toll[i];
		cin.ignore(100, '\n');

		string line;
		while(getline(cin, line) && !line.empty())
		{
			string licenseNumber, action;
			int month, day, hour, minute, distance;
			char ch;
			istringstream iss(line);

			iss >> licenseNumber >> month >> ch >> day >> ch >> hour >> ch >> minute >> action >> distance;
			m[licenseNumber].push_back(record(day, hour, minute, distance, action));
		}

		for(map<string, vector<record> >::iterator it = m.begin(); it != m.end(); ++it)
		{
			sort(it->second.begin(), it->second.end(), recordcmp);

			int cost = 0;
			for(int i = 0; i < (int)it->second.size(); ++i)
				if (it->second[i].isEnter)
					if (i + 1 < (int)it->second.size() && !it->second[i + 1].isEnter)
						cost += abs(it->second[i + 1].distance - it->second[i].distance) * toll[ it->second[i].hour ] + 100;

			if (cost > 0) printf("%s $%d.%02d\n", it->first.c_str(), (cost + 200) / 100, cost % 100);
		}
		if (tests) cout << endl;
	}
	return 0;
}
