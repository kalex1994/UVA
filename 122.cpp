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

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode(int value = -1) : value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
	BinaryTree() : root(new BinaryTreeNode()), fullySpecified(true) {}
	~BinaryTree() { destroy(root); }

	void insert(int value, char *path)
	{
		insert(root, value, path);
	}

	void print()
	{
		checkIfFullySpecified(root);
		if (fullySpecified)
			printInLevelOrder();
		else
			cout << "not complete" << endl;
	}

private:
	BinaryTreeNode *root;
	bool fullySpecified;

	void insert(BinaryTreeNode *node, int value, char *path)
	{
		if (*path == '\0')
		{
			if (node->value != -1)
				fullySpecified = false;
			node->value = value;
		}		
		else if (*path == 'L')
		{
			if (node->left == nullptr)
				node->left = new BinaryTreeNode();
			insert(node->left, value, path + 1);
		}
		else
		{
			if (node->right == nullptr)
				node->right = new BinaryTreeNode();
			insert(node->right, value, path + 1);
		}
	}

	void checkIfFullySpecified(BinaryTreeNode *node)
	{
		if (node != nullptr)
		{
			if (node->value == -1)
				fullySpecified = false;
			checkIfFullySpecified(node->left);
			checkIfFullySpecified(node->right);
		}
	}

	void printInLevelOrder()
	{
		queue<BinaryTreeNode*> nodes;
		nodes.push(root);

		while(!nodes.empty())
		{
			BinaryTreeNode* temp = nodes.front(); nodes.pop();
			if (temp != root) cout << ' ';
			cout << temp->value;
			if (temp->left != nullptr)
				nodes.push(temp->left);
			if (temp->right != nullptr)
				nodes.push(temp->right);
		}
		cout << endl;
	}

	void destroy(BinaryTreeNode *node)
	{
		if (node != NULL)
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

	char buffer[300];
	char path[300];
	int value;

	while(scanf("%s", buffer) != EOF)
	{
		BinaryTree tree;

		while(strcmp(buffer, "()") != 0)
		{
			path[0] = '\0';
			sscanf(buffer, "(%d,%[^)]", &value, path);
			tree.insert(value, path);
			scanf("%s", buffer);
		}

		tree.print();
	}
}