#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <limits>
#include <set>
using namespace std;

bool is_slump(const string& s)
{
	if (s.length() < 3) return false;
	if (s[0] != 'D' && s[0] != 'E') return false;
	if (s[1] != 'F') return false;

	int index = 2;
	while(index < s.length() && s[index] == 'F')
		++index;

	if (index == s.length()) return false;
	if (index + 1 == s.length()) return s[index] == 'G';
	return is_slump(s.substr(index));
}

bool is_slimp(const string& s)
{
	if (s[0] != 'A') return false;
	if (s.length() == 2) return s[1] == 'H';
	if (s[1] == 'B') return is_slimp(s.substr(2, s.length() - 3)) && s[s.length() - 1] == 'C';
	else return is_slump(s.substr(1, s.length() - 2)) && s[s.length() - 1] == 'C';
}

bool is_slurpy(const string& s)
{
	for(int i = 1; i + 1 < s.length(); ++i)
		if (is_slimp(s.substr(0, i)) && is_slump(s.substr(i)))
			return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;
	string s;

	cout << "SLURPYS OUTPUT" << endl;
	cin >> tests;
	while(tests--)
	{
		cin >> s;
		if (is_slurpy(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	cout << "END OF OUTPUT" << endl;
}