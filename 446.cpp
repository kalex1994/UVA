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
#include <bitset>
#include <stdint.h>
using namespace std;

void print_binary(int k)
{
	char buf[15], ind = 0;

	while (k)
	{
		buf[ind++] = k % 2 == 0 ? '0' : '1';
		k >>= 1;
	}

	for (; ind < 13; ++ind)
		buf[ind] = '0';

	do
	{
		putchar(buf[--ind]);
	} while (ind != 0);
}


int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout); 

	int tests, a, b;
	char op[2];

	scanf("%d", &tests);
	while (tests--)
	{
		scanf("%X%s%X", &a, op, &b);
		print_binary(a);
		putchar(' ');
		putchar(op[0]);
		putchar(' ');
		print_binary(b);
		putchar(' ');
		putchar('=');
		putchar(' ');
		printf("%d\n", op[0] == '+' ? a + b : a - b);
	}

	return 0;
} 

