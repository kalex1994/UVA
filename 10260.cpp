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

string encode(char ch)
{
	switch(ch)
	{
	case 'B':
	case 'F':
	case 'P':
	case 'V':
		return "1";
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S':
	case 'X':
	case 'Z':
		return "2";
	case 'D':
	case 'T':
		return "3";
	case 'L':
		return "4";
	case 'M':
	case 'N':
		return "5";
	case 'R':
		return "6";
	default:
		return "";
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string word;

	while(cin >> word)
	{
		string::iterator it = unique(word.begin(), word.end());
		word.resize(distance(word.begin(), it));

		string code = "", prevCode;
		for(int i = 0; i < (int)word.size(); ++i)
		{
			string res = encode(word[i]);

			if (i == 0)
				prevCode = res;
			else
			{
				if (res == prevCode) continue;
				prevCode = res;
			}
			code += res;
		}
		cout << code << endl;
	}
	return 0;
}




