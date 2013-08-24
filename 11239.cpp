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

map<string, set<string> > projects;
set<string> invalidUsers;

bool moreThanOneProject(string userid)
{
	bool found = false;
	for(map<string, set<string> >::iterator it = projects.begin(); it != projects.end(); ++it)
		if (it->second.count(userid))
		{
			if (found) return true;
			else found = true;
		}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string projectName, line;

	while(true)
	{
		projects.clear();
		invalidUsers.clear();

		getline(cin, projectName);
		projects[projectName].clear();
		if (projectName[0] == '0') break;

		while(getline(cin, line) && line[0] != '1')
		{
			if (isupper(line[0])) 
			{
				projectName = line;
				projects[projectName].clear();
			}
			else
				projects[projectName].insert(line);		
		}

		for(map<string, set<string> >::iterator it = projects.begin(); it != projects.end(); ++it)
			for(set<string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
				if (!invalidUsers.count(*jt) && moreThanOneProject(*jt))
					invalidUsers.insert(*jt);


		vector< pair<int, string> > output;
		for(map<string, set<string> >::iterator it = projects.begin(); it != projects.end(); ++it)
		{
			int count = 0;

			for(set<string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
				if (!invalidUsers.count(*jt))
					++count;

			output.push_back( make_pair(-count, it->first) );
		}
		
		sort(output.begin(), output.end());
		for(int i = 0; i < (int)output.size(); ++i)
			cout << output[i].second << " " << -output[i].first << endl;
	}
	return 0;
}
