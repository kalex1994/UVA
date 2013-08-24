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

string toUpper(string s)
{
	string temp = "";
	for(int i = 0; i < (int)s.size(); ++i)
		temp += toupper(s[i]);
	return temp;
}

string toLower(string s)
{
	string temp = "";
	for(int i = 0; i < (int)s.size(); ++i)
		temp += tolower(s[i]);
	return temp;
}

vector<string> tokenize(string s)
{
	vector<string> tokens;
	istringstream iss(s);
	string token;

	while(iss >> token)
		tokens.push_back(toLower(token));
	return tokens;
}

struct Title
{
	vector<string> words;
	string keyWord;
	int index;

	Title(vector<string> _words, string _keyWord,int  _index) : words(_words), keyWord(_keyWord), index(_index) {};

	void printAll()
	{
		for(int i = 0; i < (int)words.size(); ++i)
			if (words[i] == keyWord)
			{
				for(int j = 0; j < (int)words.size(); ++j)
				{
					if (j > 0) cout << " ";
					if (i == j) cout << toUpper(words[j]);
					else cout << words[j];
				}
				cout << endl;
			}
	}
};

bool cmp(const Title &a, const Title &b)
{
	if (a.keyWord < b.keyWord) return true;
	else if (a.keyWord > b.keyWord) return false;
	else return a.index < b.index;
}

vector<Title> KWIC;
set<string> ignoredWords, usedKeyWords;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string line;

	while(getline(cin, line) && line != "::")
		ignoredWords.insert(line);

	int index = 0;
	while(getline(cin, line))
	{
		usedKeyWords.clear();
		vector<string> words = tokenize(line);
		for(int i = 0; i < (int)words.size(); ++i)
			if (ignoredWords.count(words[i]) == 0 && usedKeyWords.count(words[i]) == 0)
			{
				KWIC.push_back(Title(words, words[i], index++));
				usedKeyWords.insert(words[i]);
			}
	}

	sort(KWIC.begin(), KWIC.end(), cmp);

	for(int i = 0; i < (int)KWIC.size(); ++i)
		KWIC[i].printAll();

	return 0;
}




