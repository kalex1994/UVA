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
#include <functional>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
#include <iomanip>
#include <stdint.h>
using namespace std;

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);

	int tests, pos;
	uint8_t T[100];
	string line;

	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		for (int i = 0; i < 100; ++i) T[i] = 0;
		pos = 0;

		cin >> line;
		for (size_t i = 0; i < line.length(); ++i)
		{
			switch (line[i])
			{
			case '<':
				pos--;
				if (pos == -1) pos = 99;
				break;
			case '>':
				pos++;
				if (pos == 100) pos = 0;
				break;
			case '+':
				T[pos]++;
				if (T[pos] == 256) T[pos] = 0;
				break;
			case '-':
				T[pos]--;
				if (T[pos] == -1) T[pos] = 255;
				break;
			default:
				break;
			}
		}
		
		cout << "Case " << test << ":";
		for (int i = 0; i < 100; ++i)
			printf(" %02X", T[i]);
		cout << '\n';
	}
	
	return 0;
} 

