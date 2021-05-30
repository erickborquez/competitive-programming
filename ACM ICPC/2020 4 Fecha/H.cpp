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
const lli MAX = 5 * 1e5;

lli fact[MAX];

lli binPow(long long b, long long ex)
{
    if (b == 1)
        return 1;
    long long r = 1;
    while (ex)
    {
        if (ex & 1)
            r = (r * b) % MOD;
        ex = ex >> 1;
        b = (b * b) % MOD;
    }
    return r;
}

lli inverse(lli u)
{
    return binPow(u, MOD - 2);
}

int main()
{
    IO;
    fact[0] = 1;
    for (lli i = 1; i < MAX; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    lli t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        lli top = fact[2 * n - 1];
        lli bot = fact[n] * fact[n - 1] % MOD;
        lli ans = top * inverse(bot) % MOD;
        cout << ans << ENDL;
    }

    return 0;
}