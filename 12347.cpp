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

struct Node
{
	int value;
	Node *left, *right;
	Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree(int *preorder, int begin, int end) { build(&root, preorder, begin, end); }
	~BinarySearchTree() { destroy(root); }
	void printPostorder() { postorder(root); }

private:
	Node *root;

	void build(Node **node, int *preorder, int begin, int end)
	{
		if (begin == end)
			return;
		*node = new Node(preorder[begin]);
		if (begin + 1 != end)
		{
			int pos = begin + 1;
			while(pos < end && preorder[pos] < preorder[begin])
				++pos;
			build(&(*node)->left, preorder, begin + 1, pos);
			if (pos < end)
				build(&(*node)->right, preorder, pos, end);
		}	
	}

	void postorder(Node* node)
	{
		if (node != nullptr)
		{
			postorder(node->left);
			postorder(node->right);
			cout << node->value << endl;
		}
	}

	void destroy(Node *node)
	{
		if (node != nullptr)
		{
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int preorder[10000 + 5];
	int k, n;

	for(n = 0; cin >> k; ++n)
		preorder[n] = k;
	BinarySearchTree t(preorder, 0, n);
	t.printPostorder();
}