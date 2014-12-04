#include <bits/stdc++.h>
using namespace std;

vector<char> variables;
set<char> chosen;
vector<char> toposort;
vector<pair<char, char>> constraints;

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
        for(size_t i = 0; i < toposort.size(); ++i)
            cout << toposort[i];
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

    string line;
    bool first = true;
    while(getline(cin, line))
    {
        istringstream sin(line);
        char ch, ch2;
        while(sin >> ch)
            variables.push_back(ch);
        sort(variables.begin(), variables.end());

        getline(cin, line);
        istringstream sin2(line);
        while(sin2 >> ch >> ch2)
            constraints.push_back(make_pair(ch, ch2));

        if (first) first = false;
        else cout << endl;
        solve(0);

        variables.clear();
        constraints.clear();
    }
}
