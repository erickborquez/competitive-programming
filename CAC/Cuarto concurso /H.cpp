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
const lli MX = 1e4 + 5;

lli fac[MX];
lli inverses[MX];
lli dp[MX][MX];
bool vis[MX];

lli binPow(lli x, lli y)
{
    lli res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

lli modInverse(lli n)
{
    return binPow(n, MOD - 2);
}

lli choose(lli n, lli r)
{
    if (n < r)
        return 0;
    return (fac[n] * inverses[r] % MOD * inverses[n - r] % MOD) % MOD;
}

void calc(int n)
{
    if (vis[n])
        return;
    vis[n] = true;
    FOR(u, 0, MX)
    {
        if (u == 0)
        {
            dp[n][u] = 0;
            continue;
        }
        dp[n][u] = (choose(n, u) + dp[n][u - 1]) % MOD;
    }
}

int main()
{
    IO;
    int tc;
    cin >> tc;
    fac[0] = 1;
    for (lli i = 0; i < MX; i++)
    {
        if (i > 0)
            fac[i] = (fac[i - 1] * i) % MOD;
        inverses[i] = modInverse(fac[i]);
        vis[i] = false;
    }

    while (tc--)
    {
        lli n, a, b;
        cin >> n >> a >> b;
        if (a > n)
        {
            cout << 0 << ENDL;
            continue;
        }
        lli from = min(a, n), to = min(b, n);
        calc(n);
        // deb(dp[n][from - 1]);
        // deb(dp[n][to]);
        lli ans = (dp[n][to] - dp[n][from - 1] + MOD) % MOD;
        cout << ans << ENDL;
    }

    return 0;
}