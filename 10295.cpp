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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	map<string, int> prices;
	int m, n;

	cin >> m >> n;
	while(m--)
	{
		string word;
		int price;

		cin >> word >> price;
		prices[word] = price;
	}

	cin.ignore(100, '\n');

	string line;
	while(n--)
	{
		unsigned long long salary = 0;

		while(getline(cin, line) && line != ".")
		{
			istringstream iss(line);
			string word;

			while(iss >> word)
				if (prices.count(word))
					salary += prices[word];
		}

		cout << salary << endl;
	}
	return 0;
}
