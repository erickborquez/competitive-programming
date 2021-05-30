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

const int N = 200, M = 10010;
int n, m;

ld g[N][N];
ld dp[M][N];

void solve(int k)
{
    if (k > m)
        return;

    FOR(u, 0, n)
    {
        if (dp[k - 1][u] == 0)
            continue;

        FOR(v, 0, n)
        {
            ld prob = dp[k - 1][u] * g[u][v];
            dp[k][v] += prob;
        }
    }

    solve(k + 1);
}

int main()
{
    IO;
    cin >> n >> m;

    FOR(i, 0, n)
    {
        FOR(j, 0, n)
        {
            cin >> g[i][j];
        }
    }
    dp[0][0] = 1;
    solve(1);
    FOR(i, 0, n)
    {
        cout << fixed << setprecision(10) << dp[m][i] << ENDL;
    }
    return 0;
}