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

map<string, int> position;

void generateOne(int &p)
{
	for(char a = 'a'; a <= 'z'; ++a)
	{
		string s = "";
		s += a;
		position[s] = p++;
	}
}

void generateTwo(int &p)
{
	for(char a = 'a'; a <= 'z'; ++a)
		for(char b = a + 1; b <= 'z'; ++b)
		{
			string s = "";
			s += a; s += b;
			position[s] = p++;
		}
}

void generateThree(int &p)
{
	for(char a = 'a'; a <= 'z'; ++a)
		for(char b = a + 1; b <= 'z'; ++b)
			for(char c = b + 1; c <= 'z'; ++c)
			{
				string s = "";
				s += a; s += b; s += c;
				position[s] = p++;
			}
}

void generateFour(int &p)
{
	for(char a = 'a'; a <= 'z'; ++a)
		for(char b = a + 1; b <= 'z'; ++b)
			for(char c = b + 1; c <= 'z'; ++c)
				for(char d = c + 1; d <= 'z'; ++d)
				{
					string s = "";
					s += a; s += b; s += c; s += d;
					position[s] = p++;
				}
}

void generateFive(int &p)
{
	for(char a = 'a'; a <= 'z'; ++a)
		for(char b = a + 1; b <= 'z'; ++b)
			for(char c = b + 1; c <= 'z'; ++c)
				for(char d = c + 1; d <= 'z'; ++d)
					for(char e = d + 1; e <= 'z'; ++e)
					{
						string s = "";
						s += a; s += b; s += c; s += d; s += e;
						position[s] = p++;
					}
}

void init()
{
	int p = 1;
	generateOne(p);
	generateTwo(p);
	generateThree(p);
	generateFour(p);
	generateFive(p);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	init();

	string word;
	while(cin >> word)
		cout << position[word] << endl;

	return 0;
}
