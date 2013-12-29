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

int main()
{
	int v, t;

	while (scanf("%d%d", &v, &t) != EOF)
		printf("%d\n", 2 * v * t);

	return 0;
}
