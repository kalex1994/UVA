#include <bits/stdc++.h>
using namespace std;

vector<char> variables;
set<char> chosen;
vector<char> toposort;
vector<pair<char, char>> constraints;
bool found_solution;

void read_input()
{
    string line;

    getline(cin, line);
    for(size_t i = 0; i < line.length(); i += 2)
        variables.push_back(line[i]);
    sort(variables.begin(), variables.end());

    getline(cin, line);
    for(size_t i = 0; i < line.length(); i += 4)
        constraints.push_back(make_pair(line[i], line[i + 2]));

    getline(cin, line);
}

bool violates_rule(char previous, char ch)
{
    auto p = make_pair(ch, previous);
    if (find(constraints.begin(), constraints.end(), p) != constraints.end())
        return true;
    return false;
}

void solve(size_t cnt)
{
    if (cnt == variables.size())
    {
        found_solution = true;
        cout << toposort[0];
        for(size_t i = 1; i < toposort.size(); ++i)
            cout << ' ' << toposort[i];
        cout << endl;
        return;
    }

    for(char ch : variables)
        if (chosen.count(ch) == 0)
        {
            bool ok = true;
            for(auto prev : toposort)
                if (violates_rule(prev, ch))
                {
                    ok = false;
                    break;
                }

            if (ok)
            {
                chosen.insert(ch);
                toposort.push_back(ch);
                solve(cnt + 1);
                toposort.pop_back();
                chosen.erase(ch);
            }
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    int tests;

    cin >> tests >> ws;
    while(tests--)
    {
        read_input();

        found_solution = false;
        solve(0);

        if (!found_solution)
            cout << "NO" << endl;
        if (tests)
            cout << endl;

        variables.clear();
        constraints.clear();
    }
}
