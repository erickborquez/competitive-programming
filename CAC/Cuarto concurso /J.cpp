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
const lli MOD = 1e9 + 7;
const lli N = 1e4 + 10;
lli n, m, k;

lli dp[N][15][15];

lli calc(lli u, lli acc, lli same)
{
    // cout << u << " " << acc << " " << same << ENDL;
    if (acc == n)
        return 1;
    if (dp[acc][u][same] != -1)
        return dp[acc][u][same];

    lli ans = 0;
    FOR(i, 0, k)
    {
        lli next = 0;
        if (i == u)
        {
            if (same < m)
                next = calc(u, acc + 1, same + 1);
        }
        else
        {
            next = calc(i, acc + 1, 1);
        }
        ans = (ans + next) % MOD;
    }
    dp[acc][u][same] = ans;
    // deb(ans);
    return ans;
}

int main()
{
    IO;
    lli ans = 0;
    cin >> n >> k >> m;
    FOR(i, 0, N)
    {
        FOR(ii, 0, 15)
        {
            FOR(jj, 0, 15)
            {
                dp[i][ii][jj] = -1;
            }
        }
    }
    ans = (k * calc(0LL, 1LL, 1LL)) % MOD;

    cout << ans << ENDL;
    return 0;
}