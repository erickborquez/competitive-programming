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

lli MOD = 1000000007;
const lli MX = 1e6;
lli fac[MX];

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
    return binPow(n, MOD - 2LL);
}

lli choose(lli n, lli r)
{

    if (n < r)
        return 0;
    return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
}

int main()
{
    IO;
    fac[0] = 1;
    for (lli i = 1; i < MX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    int tc;
    cin >> tc;
    while (tc--)
    {
        lli a, b, c, k, C;
        cin >> a >> b >> c >> k >> C;
        if (k < (C + 2) || k > (a + b + C))
        {
            cout << 0 << ENDL;
            continue;
        }
        lli take = k - C;
        lli from = a + b;
        lli cs = choose(c, C);
        lli inv = modInverse(fac[take]);
        lli ans = fac[from] * inv % MOD * modInverse(fac[from - take]) % MOD;

        if (a >= take)
            ans = (ans - (fac[a] * inv % MOD * modInverse(fac[a - take]) % MOD) + MOD) % MOD;
        if (b >= take)
            ans = (ans - (fac[b] * inv % MOD * modInverse(fac[b - take]) % MOD) + MOD) % MOD;

        ans = ans * cs % MOD;
        cout << ans << ENDL;
    }

    return 0;
}