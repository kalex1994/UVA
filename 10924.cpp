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

bool is_prime(int n)
{
	if (n == 0) return false;
	if (n == 1 || n == 2) return true;
	if (n % 2 == 0) return false;

	for (int i = 3; i <= (int)sqrt(n); i += 2)
		if (n % i == 0) return false;
	return true;
}

int get_value(char ch)
{
	if (ch >= 'a' && ch <= 'z') return ch - 'a' + 1;
	return ch - 'A' + 27;
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);   10625 uva

	char s[30];

	while (gets(s))
	{
		int sum = 0;
		int len = strlen(s);
		for (int i = 0; i < len; ++i)
			sum += get_value(s[i]);
		if (is_prime(sum))
			puts("It is a prime word.");
		else
			puts("It is not a prime word.");
	}

	return 0;
} 

