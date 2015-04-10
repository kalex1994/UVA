#include<bits/stdc++.h>
using namespace std;

map<string, bool> dp;

bool solve(const string& s)
{
    if (dp.find(s) != dp.end())
        return dp[s];
    if (s.empty())
        return dp[s] = true;

    size_t i = 0;
    bool answer = false;
    while (i < s.length())
    {
        size_t j = i + 1;
        while (j < s.length() && s[j] == s[i])
            ++j;
        if (j - i > 1)
            answer |= solve(s.substr(0, i) + s.substr(j));
        i = j;
    }
    return dp[s] = answer;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E:\\IN.txt", "r", stdin);
    //freopen("E:\\OUT.txt", "w", stdout);
#endif

    int tests;
    string s;

    cin >> tests;
    while(tests--)
    {
        cin >> s;
        cout << solve(s) << endl;
        dp.clear();
    }
}
