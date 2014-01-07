#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
#include <iomanip>
#include <stdint.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node() : left(NULL), right(NULL) {}

	Node(int data, Node *left, Node *right) : data(data), left(left), right(right) {}
};

Node* read_tree()
{
	int ch;

	do
	{
		ch = cin.get();
	} while (ch != '(');

	if (cin.peek() == ')')
	{
		cin.get();
		return NULL;
	}

	int data;
	scanf("%d", &data);
	Node *n = new Node(data, read_tree(), read_tree());

	do
	{
		ch = cin.get();
	} while (ch != ')');

	return n;
}

void delete_tree(Node *root)
{
	if (root == NULL) return;
	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
}

bool solve(Node *root, int val)
{
	if (root->left == NULL && root->right != NULL) return solve(root->right, val - root->data);
	if (root->left != NULL && root->right == NULL) return solve(root->left, val - root->data);
	if (root->left == NULL && root->right == NULL) return val - root->data == 0;
	if (root->left != NULL && root->right != NULL) return solve(root->left, val - root->data) || solve(root->right, val - root->data);
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);

	Node *root;
	int sum;

	while (scanf("%d", &sum) != EOF)
	{
		root = read_tree();
		if (root == NULL)
		{
			cout << "no" << endl;
			continue;
		}

		if (solve(root, sum)) 
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
		delete_tree(root);
	}

	return 0;
} 

