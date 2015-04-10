#include<bits/stdc++.h>
using namespace std;

char key[5][5];
char row[128], col[128];

void make_key(const string& s)
{
    bool used[128] = { false };

    string k;
    for(char ch : s)
    {
        ch = toupper(ch);
        if(!used[ch] && isalpha(ch))
        {
            used[ch] = true;
            k += ch;
        }
    }

    for(char ch = 'A'; ch <= 'Z'; ++ch)
        if (!used[ch] && ch != 'Q')
            k += ch;

    int ind = 0;
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
        {
            key[i][j] = k[ind++];
            row[key[i][j]] = i;
            col[key[i][j]] = j;
        }
}

string prepare(const string& s)
{
    string result;
    for(char ch : s)
        if (isalpha(ch))
        {
            ch = toupper(ch);
            if (result.length() % 2 == 1 && ch == result.back())
                result += 'X';
            result += ch;
        }
    if (result.length() % 2 != 0)
        result += 'X';
    return result;
}

string encrypt(const string& keyphrase, const string& s)
{
    make_key(keyphrase);
    string text = prepare(s), encrypted;

    for(int i = 0; i < text.length(); i += 2)
    {
        char a = text[i], b = text[i + 1];
        if (row[a] == row[b])
        {
            encrypted += key[row[a]][(col[a] + 1) % 5];
            encrypted += key[row[b]][(col[b] + 1) % 5];
        }
        else if (col[a] == col[b])
        {
            encrypted += key[(row[a] + 1) % 5][col[a]];
            encrypted += key[(row[b] + 1) % 5][col[b]];
        }
        else
        {
            encrypted += key[row[a]][col[b]];
            encrypted += key[row[b]][col[a]];
        }
    }
    return encrypted;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    int tests;
    string keyphrase, text;

    cin >> tests;
    cin.ignore(100, '\n');
    while(tests--)
    {
        getline(cin, keyphrase);
        getline(cin, text);
        cout << encrypt(keyphrase, text) << endl;
    }
}
