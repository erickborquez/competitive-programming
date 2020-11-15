#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

bool mt[100][100];

bool isValid(bool vrt, int l, int r, int c)
{
    if (vrt && (r + l) > 10)
        return false;
    if (!vrt && (c + l) > 10)
        return false;
    FOR(i, 0, l)
    {
        if (vrt)
        {
            if (mt[r + i][c])
                return false;
            else
                mt[r + i][c] = true;
        }
        else
        {
            if (mt[r][c + i])
                return false;
            else
                mt[r][c + i] = true;
        }
    }
    return true;
}

int main()
{
    IO;

    int n, d, l, r, c;
    cin >> n;

    FOR(i, 0, 20)
    {
        FOR(j, 0, 20)
        {
            mt[i][j] = false;
        }
    }

    bool ok = true;
    FOR(i, 0, n)
    {
        cin >> d >> l >> r >> c;
        if (!isValid(d, l, r, c))
        {
            ok = false;
        }
    }
    if (ok)
        cout << "Y" << ENDL;
    else
        cout << "N" << ENDL;
    return 0;
}