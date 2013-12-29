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
#include <cctype>
#include <limits>
#include <list>
#include <sstream>
using namespace std;

const string L[5] =
{
	"000 .0. 000 000 0.0 000 0.. 000 000 000 .0. ... 0.0 .0.",
	"0.0 .0. ..0 ..0 0.0 0.. 0.. ..0 0.0 0.0 .0. ... 0.0 ...",
	"0.0 .0. 000 000 000 000 000 ..0 000 000 000 000 .0. 000",
	"0.0 .0. 0.. ..0 ..0 ..0 0.0 ..0 0.0 ..0 .0. ... 0.0 ...",
	"000 .0. 000 000 ..0 000 000 ..0 000 ..0 .0. ... 0.0 .0."
};

vector<string> symbols[14];

void init()
{
	for (int i = 0; i < 5; ++i)
	{
		string token;
		istringstream iss(L[i]);

		for (int j = 0; iss >> token; ++j)
			symbols[j].push_back(token);
	}
}

char get(vector<string>& v)
{
	for (int i = 0; i < 14; ++i)
	{
		bool flag = true;

		for (int j = 0; j < 5; ++j)
			if (symbols[i][j] != v[j])
				flag = false;

		if (flag)
			switch (i)
		{
			case 10: return '+';
			case 11: return '-';
			case 12: return '*';
			case 13: return '/';
			default: return i + '0';
		}
	}
	return '?';
}

bool read_line(string &expr)
{
	string line[5], token;
	istringstream iss[5];
	vector< vector<string> > data;

	for (int i = 0; i < 5; ++i)
	{
		getline(cin, line[i]);
		iss[i].str(line[i]);
	}

	while (iss[0] >> token)
	{
		data.push_back(vector<string>(5));
		data.back()[0] = token;
		for (int i = 1; i < 5; ++i)
			iss[i] >> data.back()[i];
	}

	expr = "";
	for (int i = 0; i < data.size(); ++i)
	{
		char ch = get(data[i]);
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			expr.append(" ").append(string(1, ch)).append(" ");
		else expr += ch;
	}

	if (expr == "0") return false;
	getline(cin, token);
	return true;
}

int operation(int a, int b, string op)
{
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	return a / b;
}

void compute(vector<string>& tokens, string op1, string op2)
{
	for (size_t i = 0; i < tokens.size() - 1; ++i)
	{
		if (tokens[i + 1] == op1 || tokens[i + 1] == op2)
		{
			int a = atoi(tokens[i].c_str());
			int b = atoi(tokens[i + 2].c_str());
			ostringstream oss;
			oss << operation(a, b, tokens[i + 1]);
			tokens.erase(tokens.begin() + i, tokens.begin() + i + 3);
			tokens.insert(tokens.begin() + i, oss.str());
			--i;
		}
	}
}

string evaluate(const string& expr)
{
	vector<string> tokens;
	istringstream iss(expr);
	string token;

	while (iss >> token)
		tokens.push_back(token);

	compute(tokens, "*", "/");
	compute(tokens, "+", "-");

	return tokens[0];
}

void print( const string& s )
{
	for (int i = 0; i < 5; ++i)
	{
		for (size_t j = 0; j < s.length(); ++j)
		{
			if (j > 0) putchar(' ');
			int index = s[j] == '+' ? 10 : s[j] == '-' ? 11 : s[j] == '*' ? 12 : s[j] == '/' ? 13 : s[j] - '0';
			printf("%s", symbols[index][i].c_str());
		}
		putchar('\n');
	}
	putchar('\n');
}

int main()
{
	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif
	
	init();
	string expr;
	
	while (read_line(expr))
	{
		print(evaluate(expr));
	}

	return 0;
}
