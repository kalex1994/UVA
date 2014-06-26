#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

const int NUMBER_OF_OPERATORS = 6;
enum OPERATOR { FILL_A, FILL_B, EMPTY_A, EMPTY_B, POUR_AB, POUR_BA };
const OPERATOR OPERATORS[] = { FILL_A, FILL_B, EMPTY_A, EMPTY_B, POUR_AB, POUR_BA };

int capacity_a, capacity_b;
set< pair<int, int> > _visited;

struct State
{
	int a, b;
	vector<OPERATOR> operators;
};

bool visited(const State& state)
{
	bool ans = _visited.find(make_pair(state.a, state.b)) != _visited.end();
	_visited.insert(make_pair(state.a, state.b));
	return ans;
}

bool is_applicable(const State& state, OPERATOR op)
{
	switch(op)
	{
	case FILL_A:
		return state.a < capacity_a;
	case FILL_B:
		return state.b < capacity_b;
	case EMPTY_A:
		return state.a > 0;
	case EMPTY_B:
		return state.b > 0;
	case POUR_AB:
		return state.a > 0 && state.b < capacity_b;
	case POUR_BA:
		return state.b > 0 && state.a < capacity_a;
	}
}

State apply(State& state, OPERATOR op)
{
	State new_state = state;
	new_state.operators.push_back(op);

	int poured = 0;
	switch(op)
	{
	case FILL_A:
		new_state.a = capacity_a;
		break;
	case FILL_B:
		new_state.b = capacity_b;
		break;
	case EMPTY_A:
		new_state.a = 0;
		break;
	case EMPTY_B:
		new_state.b = 0;
		break;
	case POUR_AB:
		poured = min(new_state.a, capacity_b - new_state.b);
		new_state.a -= poured;
		new_state.b += poured;
		break;
	case POUR_BA:
		poured = min(new_state.b, capacity_a - new_state.a);
		new_state.a += poured;
		new_state.b -= poured;
		break;
	}

	return new_state;
}

void print_solution(const vector<OPERATOR>& operators)
{
	for(size_t i = 0; i < operators.size(); ++i)
		switch(operators[i])
		{
		case FILL_A:
			cout << "fill A" << endl;
			break;
		case FILL_B:
			cout << "fill B" << endl;
			break;
		case EMPTY_A:
			cout << "empty A" << endl;
			break;
		case EMPTY_B:
			cout << "empty B" << endl;
			break;
		case POUR_AB:
			cout << "pour A B" << endl;
			break;
		case POUR_BA:
			cout << "pour B A" << endl;
			break;
		}
	cout << "success" << endl;
}

vector<OPERATOR> BFS(const State &start, int target)
{
	queue<State> states;
	states.push(start);

	while(!states.empty())
	{
		State state = states.front(); states.pop();

		for(int i = 0; i < NUMBER_OF_OPERATORS; ++i)
			if (is_applicable(state, OPERATORS[i]))
			{
				State new_state = apply(state, OPERATORS[i]);
				if (new_state.b == target)
					return new_state.operators;
				if (!visited(new_state))
					states.push(new_state);
			}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int target;

	while(cin >> capacity_a >> capacity_b >> target)
	{
		_visited.clear();
		State state1;
		state1.a = capacity_a;
		state1.b = 0;
		state1.operators.push_back(FILL_A);
		vector<OPERATOR> ans1 = BFS(state1, target);

		_visited.clear();
		State state2;
		state2.a = 0;
		state2.b = capacity_b;
		state2.operators.push_back(FILL_B);
		vector<OPERATOR> ans2 = BFS(state2, target);

		print_solution(ans1.size() < ans2.size() ? ans1 : ans2);
	}
}