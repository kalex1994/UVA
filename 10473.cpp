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

	char s[20];
	int x;

	while (gets(s))
	{
		if (s[0] == '-') break;

		if (s[0] == '0')
		{
			sscanf(s, "%X", &x);
			printf("%d\n", x);
		}
		else
		{
			sscanf(s, "%d", &x);
			printf("0x%X\n", x);
		}
	}

	return 0;
} 

