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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int groups, width; 
	string word, result;

	while(cin >> groups && groups)
	{
		cin >> word;

		width = (int)word.size() / groups;
		result = "";

		while(!word.empty())
		{
			string temp = word.substr(0, width);
			reverse(temp.begin(), temp.end());
			result += temp;
			word.erase(0, width);
		}
		cout << result << endl;
	}
	return 0;
}




