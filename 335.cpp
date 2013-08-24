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

struct MXrecord
{
	string name1, name2;
	int priority;
	bool isUp;

	MXrecord(string _name1, string _name2, int _priority) : isUp(true)
	{
		this->name1 = _name1;
		this->name2 = _name2;
		this->priority = _priority;
	}

	void shutDown()
	{
		isUp = false;
	}

	void restart()
	{
		isUp = true;
	}
};

vector<MXrecord> records;

vector<string> tokenize(string &line)
{
	vector<string> temp;
	string token;
	istringstream iss(line);

	while(iss >> token)
		temp.push_back(token);
	return temp;
}

bool isMatch(string s1, string s2)
{
	s1.erase(0,1);
	if (s2.find(s1) != string::npos)
	{
		for(int i = s1.size() - 1, j = s2.size() - 1; i >= 0 && j >= 0; --i, --j)
			if (s1[i] != s2[j])
				return false;
		return true;
	}
	return false;
}

string searchFor(string adress)
{
	int minPriority = 999999999, idx = -1;

	for(int i = 0; i < (int)records.size(); ++i)
		if (records[i].isUp)
			if ( (records[i].name1 == adress) || (records[i].name1[0] == '*' && isMatch(records[i].name1,adress)) )
				if (records[i].priority < minPriority)
				{
					minPriority = records[i].priority;
					idx = i;
				}
	return idx == -1 ? "" : records[idx].name2;
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	int n;
	string line;

	cin >> n; getline(cin,line);
	while(n--)
	{
		getline(cin, line);
		vector<string> tokens = tokenize(line);
		if (tokens.size() == 3)
			records.push_back(MXrecord(tokens[0],tokens[2],atoi(tokens[1].c_str())));
		else
			records.push_back(MXrecord(records.back().name1, tokens[1], atoi(tokens[0].c_str())));
	}

	while(getline(cin,line) && line != "X")
	{
		string command, adress;
		istringstream iss(line);
		iss >> command >> adress;

		if (command == "D")
		{
			for(int i = 0; i < (int)records.size(); ++i)
				if (records[i].name2 == adress)
					records[i].shutDown();
		}
		else if (command == "U")
		{
			for(int i = 0; i < (int)records.size(); ++i)
				if (records[i].name2 == adress)
					records[i].restart();
		}
		else
		{
			string s = searchFor(adress);
			cout << adress << " =>";
			if (s != "") cout << " " << s;
			cout << endl;
		}
	}

	return 0;
}


