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
#include <sstream>
using namespace std;

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int n;
	char s[100];
	map<string, int> m;

	scanf("%d%*c", &n);
	while (n--)
	{
		gets(s);
		char *p = strtok(s, " ");
		++m[p];
	}

	for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
		printf("%s %d\n", it->first.c_str(), it->second);

	return 0;
} 

