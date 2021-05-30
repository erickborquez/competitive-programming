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

lli sum(lli n)
{
    lli ans;
    if (n % 2LL)
    {
        ans = (n + 1LL) / 2LL;
        ans = (ans * n) % MOD;
    }
    else
    {
        ans = n / 2LL;
        ans = (ans * (n + 1LL)) % MOD;
    }
    return ans;
}

int main()
{
    IO;
    int tc;
    cin >> tc;
    while (tc--)
    {
        lli n, k;
        cin >> n >> k;
        lli ans = (sum(n + 1LL) * (k + 1LL)) % MOD;
        cout << ans << ENDL;
    }

    return 0;
}