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

inline bool isoperator(int ch)
{
	return ch == '*' || ch == '/' || ch == '+' || ch == '-';
}

vector<int> numbers;
vector<char> operators;
char res[50];

bool parse()
{
	numbers.clear(); operators.clear();
	int ch, prev = '+', n, sig = 1;

	if ((ch = getchar()) == EOF)
		return false;
	
	ungetc(ch, stdin);
	while((ch = getchar()) != '=')
	{
		if (isdigit(ch))
		{
			ungetc(ch, stdin);
			prev = ch;
			scanf("%d", &n);
			numbers.push_back(sig * n);
			sig = 1;
		}
		else if (isoperator(ch))
		{
			if (ch == '+' || ch == '-')
			{
				if (isoperator(prev))
					sig = ch == '+' ? 1 : -1;
				else
					operators.push_back(ch);
			}
			else
				operators.push_back(ch);
			prev = ch;
		}
	}

	res[0] = '=';
	res[1] = ' ';
	n = 2;
	while((ch = getchar()) != '\n')
		if (isalpha(ch))
			res[n++] = ch;
	res[n] = '\0';
	return true;
}

void print()
{
	for(size_t i = 0; i < operators.size(); ++i)
		printf("%d %c ", numbers[i], operators[i]);
	printf("%d ", numbers.back());
	puts(res);
}

void do_operation(int ind)
{
	int res = 0;
	switch (operators[ind])
	{
		case '*':
			res = numbers[ind] * numbers[ind + 1];
			break;
		case '/':
			res = numbers[ind] / numbers[ind + 1];
			break;
		case '+':
			res = numbers[ind] + numbers[ind + 1];
			break;
		case '-':
			res = numbers[ind] - numbers[ind + 1]; 
			break;
	}

	numbers.insert(numbers.begin() + ind, res);
	numbers.erase(numbers.begin() + ind + 1, numbers.begin() + ind + 3);
	operators.erase(operators.begin() + ind);
}

void eval()
{
	print();
	while(!operators.empty())
	{
		bool flag = false;
		for(size_t i = 0; i < operators.size(); ++i)
			if (operators[i] == '*' || operators[i] == '/')
			{
				do_operation(i);
				flag = true;
				break;
			}
		if (!flag)
			for(size_t i = 0; i < operators.size(); ++i)
				if (operators[i] == '+' || operators[i] == '-')
				{
					do_operation(i);
					break;
				}
		print();
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif
	
	while(parse())
	{
		eval();
		putchar('\n');
	}
}