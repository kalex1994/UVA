#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <stack>
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
#include <array>
#include <regex>
using namespace std;

struct matrix
{
	int n, m;
	matrix(int n = 0, int m = 0) : n(n), m(m) {}
};

map<string, matrix> mat;

int eval(string expr)
{
	map<string, matrix> temp = mat;
	stack<string> s;
	int cost = 0;

	for(size_t i = 0; i < expr.length(); ++i)
	{
		if (expr[i] == '(')
			s.push("(");
		else if (isalpha(expr[i]))
		{
			string v;
			v += expr[i];
			s.push(v);
		}
		else if (expr[i] == ')')
		{
			string b = s.top(); s.pop();
			if (s.top() != "(")
			{
				string a = s.top(); 
				s.pop();
				s.pop();
				if (temp[a].m != temp[b].n)
					return -1;
				cost += temp[a].n * temp[a].m * temp[b].m;
				temp[a+b] = matrix(temp[a].n, temp[b].m);
				s.push(a+b);
			}
			else
				s.pop();
		}
	}
	return cost;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int k, n, m;
	string name, expr;

	cin >> k;
	while(k--)
	{
		cin >> name >> n >> m;
		mat[name] = matrix(n, m);
	}
	cin.ignore(100, '\n');
	while(getline(cin, expr))
	{
		int res = eval(expr);
		if (res < 0)
			cout << "error" << endl;
		else
			cout << res << endl;
	}
}