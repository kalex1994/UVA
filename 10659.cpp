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
	
int paragraphCount;
vector<string> paragraphs;
int slideWidth, slideHeight;

vector<string> getWords(string &line)
{
	vector<string> ret;
	string temp;
	istringstream iss(line);
	while(iss >> temp)
		ret.push_back(temp);
	return ret;
}

bool fitWithFontSize(int fontSize)
{	
	if (fontSize > slideHeight || fontSize > slideWidth) return false;

	int width, height = 0;
	for(int i = 0; i < (int)paragraphs.size(); ++i)
	{
		width = 0;
		height += fontSize;

		vector<string> words = getWords(paragraphs[i]);
		for(int j = 0; j < (int)words.size(); ++j)
			if (words[j].size() * fontSize > slideWidth) return false;
			else
			{
				if (words[j].size() * fontSize + width <= slideWidth)
					width += words[j].size() * fontSize;
				else
				{
					width = words[j].size() * fontSize;
					height += fontSize;
					if (height > slideHeight) return false;
				}

				if (j == (int)words.size() - 1) continue;

				if (width + fontSize <= slideWidth)
					width += fontSize;
				else
				{
					width = 0;
					height += fontSize;
					if (height > slideHeight) return false;
				}
			}
	}
	return true;
}

void tryFit()
{
	for(int i = 28; i >= 8; --i)
		if (fitWithFontSize(i))
		{
			cout << i << endl;
			return;
		}
	cout << "No solution" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;
	string line;
	
	cin >> tests;
	while(tests--)
	{
		paragraphs.clear();
		cin >> paragraphCount; getline(cin, line);
		while(paragraphCount--)
		{
			getline(cin, line);
			paragraphs.push_back(line);
		}
		cin >> slideWidth >> slideHeight;
		tryFit();
	}
	return 0;
}


