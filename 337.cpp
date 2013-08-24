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

using namespace std;

enum MODE {owerwrite, insert};

char terminal[10][10];
MODE currentMode;
int cursorRow, cursorCol;

void clear()
{
	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j)
			terminal[i][j] = ' ';
}

void init()
{
	cursorRow = cursorCol = 0;
	currentMode = owerwrite;
	clear();
}

void erase()
{
	for(int j = cursorCol; j < 10; ++j)
		terminal[cursorRow][j] = ' ';
}

void writeChar(char ch)
{
	if (currentMode == owerwrite)
	{
		terminal[cursorRow][cursorCol] = ch;
	}
	else
	{
		for(int j = 9; j > cursorCol; --j)
			terminal[cursorRow][j] = terminal[cursorRow][j-1];
		terminal[cursorRow][cursorCol] = ch;
	}
	if (cursorCol + 1 < 10)
		++cursorCol;
}

void printTerminal()
{
	string top = "+----------+";
	cout << top << endl;
	for(int i = 0; i < 10; ++i)
	{
		string line = "|";
		for(int j = 0; j < 10; ++j)
			line += terminal[i][j];
		line += "|";
		cout << line << endl;
	}
	cout << top << endl;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	int N, caseNumber = 1;
	string line;

	while(cin >> N && N)
	{
		init();
		printf("Case %d\n",caseNumber++);

		getline(cin,line);
		while(N--)
		{
			getline(cin,line);
			for(int i = 0; i < (int)line.size(); ++i)
			{
				if (line[i] == '^')
				{
					++i;
					switch(line[i])
					{
					case 'b':
						cursorCol = 0;
						break;
					case 'c':
						clear();
						break;
					case 'd':
						if (cursorRow + 1 < 10)
							++cursorRow;
						break;
					case 'e':
						erase();
						break;
					case 'h':
						cursorRow = cursorCol = 0;
						break;
					case 'i':
						currentMode = insert;
						break;
					case 'l':
						if (cursorCol - 1 >= 0)
							--cursorCol;
						break;
					case 'o':
						currentMode = owerwrite;
						break;
					case 'r':
						if (cursorCol + 1 < 10)
							++cursorCol;
						break;
					case 'u':
						if (cursorRow - 1 >= 0)
							--cursorRow;
						break;
					case '^':
						writeChar('^');
						break;
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':		
						cursorRow = line[i] - '0';
						++i;
						cursorCol = line[i] - '0';
						break;
					}
				}
				else
					writeChar(line[i]);
			}
		}
		printTerminal();
	}

	return 0;
}


