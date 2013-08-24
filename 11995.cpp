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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n, command, number;
	bool canbeStack, canbeQueue, canbePriorityQueue;

	while(cin >> n)
	{
		stack<int> myStack;
		priority_queue<int> myPriority_Queue;
		queue<int> myQueue;
		canbeStack = canbeQueue = canbePriorityQueue = true;

		while(n--)
		{
			cin >> command >> number;
			if (command == 1)
			{
				myStack.push(number);
				myPriority_Queue.push(number);
				myQueue.push(number);
			}
			else
			{
				if (canbeStack)
				{
					if (myStack.empty())
						canbeStack = false;
					else
					{
						if (number != myStack.top())
							canbeStack = false;
						myStack.pop();
					}
				}

				if (canbePriorityQueue)
				{
					if (myPriority_Queue.empty())
						canbePriorityQueue = false;
					else
					{
						if (number != myPriority_Queue.top())
							canbePriorityQueue = false;
						myPriority_Queue.pop();
					}
				}

				if (canbeQueue)
				{
					if (myQueue.empty())
						canbeQueue = false;
					else
					{
						if (number != myQueue.front())
							canbeQueue = false;
						myQueue.pop();
					}
				}
			}
		}
		
		if (canbeStack + canbePriorityQueue + canbeQueue > 1) cout << "not sure" << endl;
		else if (canbeStack + canbePriorityQueue + canbeQueue == 0) cout << "impossible" << endl;
		else if (canbeStack) cout << "stack" << endl;
		else if (canbePriorityQueue) cout << "priority queue" << endl;
		else if (canbeQueue) cout << "queue" << endl;
	}
	return 0;
}
