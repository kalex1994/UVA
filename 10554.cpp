#include<iostream>
#include<cstdio>
#include<math.h>
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

vector<string> getTokens(string s)
{
	istringstream iss(s);
	vector<string> tokens;
	string token;
	while(iss >> token)
		tokens.push_back(token);
	return tokens;
}

vector<double> getCalories(vector<string> data)
{
	vector<double> ret(5, -1.0);

	int percent = 100;
	int calories = 0;
	for(int i = 0; i < data.size(); ++i)
	{
		char ch; int val;
		sscanf(data[i].c_str(),"%d%c",&val,&ch);

		if (ch == 'g') 
		{
			ret[i] = val * (i == 0 ? 9 : (i == 4 ? 7 : 4 ) );
			calories += ret[i];
		}
		else if (ch == 'C')
		{
			ret[i] = val;
			calories += ret[i];
		}
		else percent -= val;
	}
	for(int i = 0; i < data.size(); ++i)
	{
		char ch; int val;
		sscanf(data[i].c_str(),"%d%c",&val,&ch);

		if (ch == '%')
		{
			ret[i] = (double)(val * calories) / (double)percent;
		}
	}

	return ret;
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	string line;

	while(getline(cin, line) && line != "-")
	{
		double fat = 0, sum = 0;

		vector<double> cal = getCalories(getTokens(line));

		fat += cal[0];
		for(int i = 0; i < cal.size(); ++i)
			sum += cal[i];

		while(getline(cin, line) && line != "-")
		{
			cal = getCalories(getTokens(line));
			fat += cal[0];
			for(int i = 0; i < cal.size(); ++i)
				sum += cal[i];
		}
		cout << (int)(fat * 100 / sum + .5) << "%" << endl;
	}
	return 0;
}


