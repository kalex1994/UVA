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

class ORname
{
private:
	string country, ADMD, PRMD, organizationName;

public:
	friend bool operator==(const ORname&, const ORname&);

	ORname(string _country, string _ADMD, string _PRMD, string _organizationName)
	{
		this->country = _country;
		this->ADMD = _ADMD;
		this->PRMD = _PRMD;
		this->organizationName = _organizationName;
	}
};

bool operator==(const ORname& a, const ORname& b)
{
	if (a.country == b.country || a.country == "*" || b.country == "*")
		if(a.ADMD == b.ADMD || a.ADMD == "*" || b.ADMD == "*")
			if (a.PRMD == b.PRMD || a.PRMD == "*" || b.PRMD == "*")
				if (a.organizationName == b.organizationName || a.organizationName == "*" || b.organizationName == "*")
					return true;
	return false;
}

map<string, vector< pair<string,ORname> > > MTA;

void routeMail(int caseNum, string current, ORname data)
{
	set<string> cycleDetection;
	string next;
	cycleDetection.insert(current);

	while(true)
	{
		bool isFound = false;
		for(int i = 0; i < (int)MTA[current].size(); ++i)
			if (data == MTA[current][i].second)
			{
				isFound = true;
				next = MTA[current][i].first;
				break;
			}
		if (!isFound)
		{
			printf("%d -- unable to route at %s\n",caseNum,current.c_str());
			return;
		}
		if (next == current)
		{
			printf("%d -- delivered to %s\n",caseNum,current.c_str());
			return;
		}
		if (cycleDetection.count(next))
		{
			printf("%d -- circular routing detected by %s\n",caseNum,next.c_str());
			return;
		}
		cycleDetection.insert(next);
		current = next;
	}
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	int M, scenario = 1;
	while(cin >> M)
	{
		MTA.clear();

		string name;
		int k;

		while(M--)
		{
			cin >> name >> k;
			while(k--)
			{
				string delivery, country, ADMD, PRMD, organizationName;
				cin >> delivery >> country >> ADMD >> PRMD >> organizationName;
				MTA[name].push_back( make_pair(delivery, ORname(country,ADMD,PRMD,organizationName)) );
			}
		}

		printf("Scenario # %d\n",scenario++);

		cin >> k;
		int caseNum = 1;
		while(k--)
		{
			string current, country, ADMD, PRMD, organizationName;
			cin >> current >> country >> ADMD >> PRMD >> organizationName;
			routeMail(caseNum++,current,ORname(country,ADMD,PRMD,organizationName));
		}
		cout << endl;
	}
	return 0;
}


