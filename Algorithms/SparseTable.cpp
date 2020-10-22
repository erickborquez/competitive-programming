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

int main()
{
    IO;
    int n, q;
    cin >> n;
    int logn = __lg(n) + 1;
    vector<vector<int>> dp(logn, vector<int>(n));

    FOR(i, 0, n)
    {
        cin >> dp[0][i];
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

    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << ENDL;
    }

    return 0;
}