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
	
struct fraction
{
	unsigned long long nominator, denominator;

	fraction(unsigned long long _nominator = 0, unsigned long long _denominator = 0)
	{
		this->nominator = _nominator;
		this->denominator = _denominator;
	}

	void operator=(const fraction &other)
	{
		this->nominator = other.nominator;
		this->denominator = other.denominator;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;
	string line;

	cin >> tests; cin.ignore(100,'\n');
	while(tests--)
	{
		getline(cin,line);
		fraction currentNode(1,1), leftSibling(0,1), rightSibling(1,0);

		for(int i = 0; i < line.size(); ++i)
		{
			if (line[i] == 'L')
			{
				fraction newCurrent(leftSibling.nominator + currentNode.nominator, leftSibling.denominator + currentNode.denominator);
				rightSibling = currentNode;
				currentNode = newCurrent;
				
			}
			else
			{
				fraction newCurrent(currentNode.nominator + rightSibling.nominator, currentNode.denominator + rightSibling.denominator);
				leftSibling = currentNode;
				currentNode = newCurrent;
			}	
		}
		cout << currentNode.nominator << "/" << currentNode.denominator << endl;
	}
	return 0;
}


