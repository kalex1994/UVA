#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int n, m;
string words[100];
string rule;

void make_passwords(string password, size_t index)
{
	if (index >= rule.length())
	{
		cout << password << "\n";
		return;
	}
	if (rule[index] == '0')
	{
		for(int i = 0; i <= 9; ++i)
			make_passwords(password + string(1, i + '0'), index + 1);
	}
	else
	{
		for(int i = 0; i < n; ++i)
			make_passwords(password + words[i], index + 1);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
			cin >> words[i];

		cin >> m;
		while(m--)
		{
			cin >> rule;
			cout << "--\n"; 
			make_passwords("", 0);
		}
	}
}