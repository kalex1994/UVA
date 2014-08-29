#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <numeric>
#include <deque>
#include <map>
#include <iterator>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
using namespace std;

int code[256];
const set<int> not_encoded { 'A', 'E', 'I', 'O', 'U', 'Y', 'W', 'H' };
string name;

void init()
{
	code['A'] = code['E'] = code['I'] =  code['O'] = code['U'] = code['Y'] = code['W'] = code['H'] = 0;
	code['B'] = code['P'] = code['F'] = code['V'] = 1;
	code['C'] = code['S'] = code['K'] = code['G'] = code['J'] = code['Q'] = code['X'] = code['Z'] = 2;
	code['D'] = code['T'] = 3;
	code['L'] = 4;
	code['M'] = code['N'] = 5;
	code['R'] = 6;
}

string encode(const string& name)
{
	stringstream ss;
	ss << name[0];

	for(int i = 1; i < name.length(); ++i)
		if (code[name[i]] != code[name[i - 1]] && find(not_encoded.begin(), not_encoded.end(), name[i]) == not_encoded.end())
			ss << code[name[i]];

	string result = ss.str();
	if (result.length() < 4)
		while(result.length() < 4)
			result += '0';
	return result.substr(0, 4);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	init();
	puts("         NAME                     SOUNDEX CODE");
	while(cin >> name)
		printf("         %s%*s\n", name.c_str(), 29 - name.length(), encode(name).c_str());
	puts("                   END OF OUTPUT");
}