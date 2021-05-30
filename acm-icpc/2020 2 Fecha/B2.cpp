#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
bool grid[11][11];

bool isValid(int d, int l, int r, int c)
{
    if (d == 0)
    {
        for (int i = 0; i < l; i++)
        {
            if (c + i > 10)
            {
                return false;
            }
            if (grid[r][c + i])
            {
                return false;
            }
            else
            {
                grid[r][c + i] = true;
            }
        }
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            if (r + i > 10)
            {
                return false;
            }
            if (grid[r + i][c])
            {
                return false;
            }
            else
            {
                grid[r + i][c] = true;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, l, r, c;
    cin >> n;
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            grid[i][j] = false;
        }
    }
    bool si = true;
    while (n--)
    {
        cin >> d >> l >> r >> c;
        if (si)
        {
            si &= isValid(d, l, r, c);
        }
    }
    cout << (si ? "Y" : "N") << ENDL;
    return 0;
}