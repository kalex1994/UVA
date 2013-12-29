#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <list>
#include <sstream>
using namespace std;

int check(string s)
{
	char op;

	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			op = s[i];
			s[i] = ' ';
		}
		else if (s[i] == '=') s[i] = ' ';
	}

	istringstream iss(s);
	int a, b, c;

	iss >> a >> b;
	if (iss.peek() == '?') return 0;
	iss >> c;

	if (op == '+') return a + b == c ? 1 : 0;
	else return a - b == c ? 1 : 0;
}


int main()
{
	int ans = 0;
	string s;

	while (cin >> s)
		ans += check(s);

	cout << ans << endl;

	return 0;
}
