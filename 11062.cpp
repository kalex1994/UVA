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

enum STATE {WORD, HYPHEN, OTHER};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	STATE currentState = OTHER;
	set<string> dictionary;
	string word = "";
	int ch;

	while( (ch = cin.get()) != EOF )
	{
		ch = tolower(ch);
		switch(currentState)
		{
		case WORD:
			if (ch == '-')
				currentState = HYPHEN;
			else if (isalpha(ch))
				word += ch;
			else
			{
				if (word != "")
					dictionary.insert(word);
				word = "";
				currentState = OTHER;
			}
			break;
		case HYPHEN:
			if (ch != '\n')
			{
				word += '-';
				word += ch;
			}
			currentState = WORD;
			break;
		case OTHER:
			if (isalpha(ch))
			{
				word += ch;
				currentState = WORD;
			}
			break;
		}
	}
	if (word != "") dictionary.insert(word);

	for(set<string>::const_iterator it = dictionary.begin(); it != dictionary.end(); ++it)
		cout << *it << endl;

	return 0;
}
