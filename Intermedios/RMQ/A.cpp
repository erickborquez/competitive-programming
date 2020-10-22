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

lli INF = 1e10;

int main()
{
    IO;
    int n, k;
    cin >> n >> k;
    int logn = __lg(n) + 1;
    vector<vector<lli>> dp(logn, vector<lli>(n));

    lli mx = -INF;
    lli mn = INF;
    FOR(i, 0, n)
    {
        cin >> dp[0][i];
        mx = max(mx, dp[0][i]);
        mn = min(mn, dp[0][i]);
    }
    FOR(k, 1, logn + 1)
    {
        for (int l = 0; l + (1 << k) <= n; ++l)
        {
            int r = l + (1 << (k - 1));
            dp[k][l] = min(dp[k - 1][l], dp[k - 1][r]);
        }
    }

    auto query = [&](int l, int r) {
        int k = __lg(r - l + 1);
        return min(dp[k][l], dp[k][r - (1 << k) + 1]);
    };

    if (k == 1)
    {
        cout << mn << ENDL;
    }
    else if (k >= 3)
    {
        cout << mx << ENDL;
    }
    else
    {
        lli best = -INF;
        FOR(i, 0, n)
        {
            // deb(query(1, i));
            best = max(best, query(0, i));
        }
        FORN(i, n, 0)
        {
            // debp(i, n);
            // deb(query(i, n - 1));
            best = max(best, query(i, n - 1));
        }
        cout << best << ENDL;
    }

    return 0;
}