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

#define Emax(L) log10((double)L)

bool isPunc(char ch)
{
	if (ch == ',' || ch == '.' || ch == ':' || ch == ';' || ch == '!' || ch == '?' || ch == '"' || ch == '(' || ch == ')' ||
		ch == ' ' || ch == '\t') return true;
	return false;
}

inline void lowercase(string &s)
{
	for(int i = 0; i < (int)s.size(); ++i)
		s[i] = static_cast<char>(tolower(s[i]));
}

void getWords(string &text, vector<string> &words)
{
	int i = 0;
	string word = "";

	while(true)
	{
		if (i == text.size())
		{
			if (word != "")
			{
				lowercase(word);
				words.push_back(word);
			}
			return;
		}
		if (!isPunc(text[i])) word += text[i];
		else
		{
			if (word != "")
			{
				lowercase(word);
				words.push_back(word);
			}
			word = "";
		}
		++i;
	}
}

map<string, int> frequency;
int wordcount;

double getEntropy()
{
	double sum = 0.0;

	for(map<string, int>::const_iterator it = frequency.begin(); it != frequency.end(); ++it)
		sum += (double)it->second * (log10((double)wordcount) - log10((double)it->second));

	return sum / (double)wordcount;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string line;

	while(getline(cin, line) && line != "****END_OF_INPUT****")
	{
		frequency.clear();
		wordcount = 0;

		if (line == "****END_OF_TEXT****")
		{
			printf("%d %0.1lf %d\n", 0, 0.0, 0);
			continue;
		}

		string text = line;
		while(getline(cin, line) && line != "****END_OF_TEXT****")
			text += " " + line;

		vector<string> words;
		getWords(text, words);
		wordcount += (int)words.size();

		for(int i = 0; i < (int)words.size(); ++i)
			++frequency[ words[i] ];

		double entropy = getEntropy();

		printf("%d %0.1lf %d\n", wordcount, entropy, (int)round(entropy / Emax(wordcount) * 100.0));
	}
	return 0;
}
