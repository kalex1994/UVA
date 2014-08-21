#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <functional>
using namespace std;

struct interval_tree
{
	int start, end;
	interval_tree *left, *right;
	set<char> chars;

	interval_tree(const string& s, int start, int end) : 
		chars(s.begin(), s.end()), start(start), end(end), left(nullptr), right(nullptr) { }

	void cut(const string& word, int position)
	{
		if (position < start || position > end) return;
		if (left != nullptr && right != nullptr)
		{
			left->cut(word, position);
			right->cut(word, position);
		}
		else
		{
			left = new interval_tree(word.substr(start, position - start + 1), start, position);
			right = new interval_tree(word.substr(position + 1, end - position), position + 1, end);
		}
	}

	int cost()
	{
		if (left != nullptr && right != nullptr)
		{
			char t[30];
			return (set_symmetric_difference(left->chars.begin(), left->chars.end(), right->chars.begin(), right->chars.end(), t) - t) 
				+ left->cost() + right->cost();
		}
		else return 0;
	}

	~interval_tree()
	{
		if (left != nullptr && right != nullptr)
		{
			delete left;
			delete right;
		}
	}
};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, ncuts;
	int cuts[1000];
	string s;

	cin >> tests;
	while (tests--)
	{
		cin >> ncuts;
		for (int i = 0; i < ncuts; ++i)
			cin >> cuts[i];
		cin >> s;

		interval_tree *t = new interval_tree(s, 0, s.length() - 1);
		for (int i = 0; i < ncuts; ++i)
			t->cut(s, cuts[i] - 1);
		cout << t->cost() << endl;
		delete t;
	}
}