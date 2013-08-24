#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<limits>
#include<sstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<list>
#include<iomanip>
#include<queue>

using namespace std;

typedef unsigned long long ull;

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	ull N;
	while(cin >> N)
	{
		ull lineIndex = (N + 1) / 2;	
		ull oddNumbersCount = lineIndex * (1 + (1 + 2 * (lineIndex - 1))) / 2;
		ull a = 2 * oddNumbersCount - 1;
		ull b = a - 2;
		ull c = b - 2;
		cout << a + b + c << endl;
	}
	return 0;
}


