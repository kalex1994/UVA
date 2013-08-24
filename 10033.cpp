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

int registers[10], RAM[1000], testCases;
string line;

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	cin >> testCases;
	getline(cin,line);
	getline(cin,line);

	while(testCases--)
	{
		for(int i = 0; i < 10; ++i)
			registers[i] = 0;
		for(int i = 0; i < 1000; ++i)
			RAM[i] = 0;

		int size = 0;
		while(getline(cin,line) && line.size() != 0)
			RAM[size++] = atoi(line.c_str());

		int actualInstruction = 0, instuctionCount = 0;
		while(RAM[actualInstruction] != 100)
		{
			++instuctionCount;

			int a = RAM[actualInstruction] / 100;
			int b = RAM[actualInstruction] / 10 % 10;
			int c = RAM[actualInstruction] % 10;
			bool isJumped = false;

			switch(a)
			{
			case 2:
				registers[b] = c;
				break;
			case 3:
				registers[b] += c;
				registers[b] %= 1000;
				break;
			case 4:
				registers[b] *= c;
				registers[b] %= 1000;
				break;
			case 5:
				registers[b] = registers[c];
				break;
			case 6:
				registers[b] += registers[c];
				registers[b] %= 1000;
				break;
			case 7:
				registers[b] *= registers[c];
				registers[b] %= 1000;
				break;
			case 8:
				registers[b] = RAM[ registers[c] ];
				break;
			case 9:
				RAM[ registers[c] ] = registers[b];
				break;
			case 0:
				if (registers[c] != 0)
				{
					actualInstruction = registers[b];
					isJumped = true;
				}
				break;
			}

			if (!isJumped)
				++actualInstruction;
		}
		cout << instuctionCount + 1 << endl;
		if (testCases)
			cout << endl;
	}
	return 0;
}


