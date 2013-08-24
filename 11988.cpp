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
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	string line;
	list<char> beiju;
	list<char>::iterator current = beiju.end();

	while(getline(cin,line))
	{
		beiju.clear();

		for(int i = 0; i < (int)line.size(); ++i)
			if (line[i] == '[')
				current = beiju.begin();
			else if (line[i] == ']')
				current = beiju.end();
			else
				beiju.insert(current,line[i]);

		for(current = beiju.begin(); current != beiju.end(); ++current)
			cout << *current;
		cout << endl;
	}
	return 0;
}


