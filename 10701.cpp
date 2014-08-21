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
#include <queue>
#include <map>
#include <cassert>
#include <list>
#include <functional>
using namespace std;

string getPostorder(const string& preorder, const string& inorder)
{
	if (preorder.empty()) return "";
	if (preorder.length() == 1) return preorder;
	int pos = inorder.find(preorder[0]);
	return getPostorder(preorder.substr(1, pos), inorder.substr(0, pos)) + 
		(pos > preorder.length() ? "" : getPostorder(preorder.substr(pos + 1), inorder.substr(pos + 1))) +
		preorder.substr(0, 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string preorder, inorder;
	int tests, n;

	cin >> tests;
	while(tests--)
	{
		cin >> n >> preorder >> inorder;
		cout << getPostorder(preorder, inorder) << endl;
	}	
}