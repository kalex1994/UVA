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

map<string, int> m;
char dat[256];

void init()
{
	dat['A'] = dat['B'] = dat['C'] = '2';
	dat['D'] = dat['E'] = dat['F'] = '3';
	dat['G'] = dat['H'] = dat['I'] = '4';
	dat['J'] = dat['K'] = dat['L'] = '5';
	dat['M'] = dat['N'] = dat['O'] = '6';
	dat['P'] = dat['R'] = dat['S'] = '7';
	dat['T'] = dat['U'] = dat['V'] = '8';
	dat['W'] = dat['X'] = dat['Y'] = '9';
}

string encode(string &s)
{
	string temp = "";
	for(int i = 0; i < (int)s.size(); ++i)
		if (isdigit(s[i])) temp += s[i];
		else if (isalpha(s[i])) temp += dat[ s[i] ];
	temp.insert(3, "-");
	return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	init();

	int tests, n;
	string telephoneNumber;

	cin >> tests;
	while(tests--)
	{
		m.clear();

		cin >> n;
		while(n--)
		{
			cin >> telephoneNumber;
			++m[encode(telephoneNumber)];
		}

		bool hasDuplicate = false;
		for(map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it)
			if (it->second > 1)
			{
				cout << it->first << " " << it->second << endl;
				hasDuplicate = true;
			}
		if (!hasDuplicate) cout << "No duplicates." << endl;
		if (tests) cout << endl;
	}
	return 0;
}




