#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3;
const int MAXNN = MAXN * MAXN;

int n, nn;
int row[MAXNN][MAXNN + 1];
int col[MAXNN][MAXNN + 1];
int tile[MAXN][MAXN][MAXNN + 1];
int sudoku[MAXNN][MAXNN];
bool solution_found;

void print_solution()
{
    for(int i = 0; i < nn; ++i)
    {
        for(int j = 0; j < nn; ++j)
        {
            if (j > 0) putchar(' ');
            printf("%d", sudoku[i][j]);
        }
        putchar('\n');
    }
}

void solve(int pos)
{
    if (solution_found)
        return;

    if (pos == nn * nn)
    {
        solution_found = true;
        print_solution();
        return;
    }

    int r = pos / nn;
    int c = pos % nn;

    if (sudoku[r][c] != 0)
        solve(pos + 1);
    else
    {
        for(int i = 1; i <= nn; ++i)
            if (row[r][i] == 0 && col[c][i] == 0 && tile[r / n][c / n][i] == 0)
            {
                row[r][i] = col[c][i] = tile[r / n][c / n][i] = 1;
                sudoku[r][c] = i;
                solve(pos + 1);
                sudoku[r][c] = 0;
                row[r][i] = col[c][i] = tile[r / n][c / n][i] = 0;
            }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
    freopen("E:\\OUT.txt", "w", stdout);
#endif

    bool first = true;
    while(scanf("%d", &n) == 1)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(tile, 0, sizeof(tile));
        solution_found = false;

        if (first) first = false;
        else putchar('\n');

        nn = n * n;
        for(int i = 0; i < nn; ++i)
            for(int j = 0; j < nn; ++j)
            {
                scanf("%d", &sudoku[i][j]);
                int elem = sudoku[i][j];
                row[i][elem] = col[j][elem] = tile[i / n][j / n][elem] = 1;
            }
        solve(0);
        if (!solution_found)
            puts("NO SOLUTION");
    }
}
