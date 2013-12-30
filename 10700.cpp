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
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
using namespace std;

char prec;

typedef unsigned long ul;

ul evaluate(string s)
{
	stack<ul> values;
	stack<char> operators;

	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			ul k = 0;
			while (s[i] >= '0' && s[i] <= '9')
				k = k * 10 + s[i++] - '0';
			--i;
			values.push(k);
		}
		else if (s[i] == '+' || s[i] == '*')
		{
			while (!operators.empty() && (operators.top() == s[i] || operators.top() == prec))
			{
				char op = operators.top(); operators.pop();
				ul a = values.top(); values.pop();
				ul b = values.top(); values.pop();
				ul res = op == '*' ? a * b : a + b;
				values.push(res);
			}
			operators.push(s[i]);
		}
	}

	while (!operators.empty())
	{
		char op = operators.top(); operators.pop();
		ul a = values.top(); values.pop();
		ul b = values.top(); values.pop();
		ul res = op == '*' ? a * b : a + b;
		values.push(res);
	}

	return values.top();
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int n;
	string s;

	cin >> n;
	while (n--)
	{
		cin >> s;
		
		prec = '*';
		ul min = evaluate(s);
		prec = '+';
		ul max = evaluate(s);

		printf("The maximum and minimum are %llu and %llu.\n", max, min);
	}
	return 0;
} 

