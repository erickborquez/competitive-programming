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

#define N 94

lli INF = 1e18 + 10;

lli dp[N][N];
bool vis[N][N];
lli g[N][N];

void fw()
{
    FOR(i, 0, N)
    {
        FOR(j, 0, N)
        {
            if (g[i][j] != -1)
                dp[i][j] = g[i][j];
            else if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }
    FOR(k, 0, N)
    {
        FOR(i, 0, N)
        {
            FOR(j, 0, N)
            {
                if (dp[i][k] != INF && dp[k][j] != INF)
                {
                    vis[i][j] = true;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
    FOR(k, 0, N)
    {
        FOR(i, 0, N)
        {
            FOR(j, 0, N)
            {
                if (dp[i][k] != INF && dp[k][j] != INF)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
}

int main()
{
    IO;
    string s, t;
    lli m;
    cin >> s >> t >> m;
    FOR(i, 0, N)
    {
        FOR(j, 0, N)
        {
            dp[i][j] = -1;
            g[i][j] = -1;
            vis[i][j] = false;
        }
    }
    FOR(i, 0, m)
    {
        char a, b;
        lli c, ascA, ascB;
        cin >> a >> b >> c;
        // debp(a - 33, b - 33);
        ascA = a - 33;
        ascB = b - 33;
        g[ascA][ascB] = g[ascA][ascB] == -1 ? c : min(c, g[ascA][ascB]);
    }
    fw();
    lli total = 0;
    bool ok = true;
    FOR(i, 0, s.size())
    {
        lli ascA = s[i] - 33;
        lli ascB = t[i] - 33;
        lli inc = dp[ascA][ascB];
        if (!vis[ascA][ascB])
        {
            ok = false;
            break;
        }
        total += inc;
    }
    if (ok)
        cout << total << ENDL;
    else
        cout << -1 << ENDL;
    return 0;
}