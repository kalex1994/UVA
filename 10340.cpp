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

string s, t;

bool isSubSequence()
{
	for(int i = 0; i < (int)s.size(); ++i)
	{
		int p = t.find_first_of(s[i]);
		if (p == string::npos) return false;
		t.erase(0, p + 1);
	}
	return true;
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	while(cin >> s >> t)
	{
		if (isSubSequence()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}


