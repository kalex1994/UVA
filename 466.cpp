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
#include<cfloat>

using namespace std;

struct Pattern
{
	vector<string> square;

	Pattern() {}

	Pattern(vector<string> &_square)
	{
		this->square = _square;
	}

	Pattern rotateBy90()
	{
		Pattern p(this->square);

		for(int i = 0; i < (int)square.size(); ++i)
			for(int j = 0; j < (int)square.size(); ++j)
				p.square[i][j] = square[(int)square.size() - j - 1][i];

		return p;
	}

	Pattern reflectVertically()
	{
		Pattern p(this->square);

		for(int i = 0, j = (int)p.square.size() - 1; i < j; ++i, --j)
			swap(p.square[i], p.square[j]);

		return p;
	}

	bool equals(Pattern &other)
	{
		for(int i = 0; i < (int)square.size(); ++i)
			if (this->square[i] != other.square[i])
				return false;
		return true;
	}
};

string getRelationShip(Pattern &p1, Pattern &p2)
{
	if (p1.equals(p2)) return "preserved.";
	if (p1.rotateBy90().equals(p2)) return "rotated 90 degrees.";
	if (p1.rotateBy90().rotateBy90().equals(p2)) return "rotated 180 degrees.";
	if (p1.rotateBy90().rotateBy90().rotateBy90().equals(p2)) return "rotated 270 degrees.";
	if (p1.reflectVertically().equals(p2)) return "reflected vertically.";
	if (p1.reflectVertically().rotateBy90().equals(p2)) return "reflected vertically and rotated 90 degrees.";
	if (p1.reflectVertically().rotateBy90().rotateBy90().equals(p2)) return "reflected vertically and rotated 180 degrees.";
	if (p1.reflectVertically().rotateBy90().rotateBy90().rotateBy90().equals(p2)) return "reflected vertically and rotated 270 degrees.";
	return "improperly transformed.";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n, caseNumber = 1;
	while(cin >> n)
	{
		vector<string> square1, square2;
		string s1, s2;

		while(n--)
		{
			cin >> s1 >> s2;
			square1.push_back(s1);
			square2.push_back(s2);
		}

		Pattern p1(square1);
		Pattern p2(square2);

		printf("Pattern %d was %s\n", caseNumber++, getRelationShip(p1, p2).c_str());
	}
	return 0;
}
