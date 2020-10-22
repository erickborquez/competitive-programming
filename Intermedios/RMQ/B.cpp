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

lli MAX = 1e6 + 10;

int main()
{
    IO;
    int n, q;
    cin >> n >> q;
    int log[MAX];
    log[1] = 0;
    for (int i = 2; i <= MAX; i++)
    {
        log[i] = log[i / 2] + 1;
    }
    int logn = log[n] + 1;

    vector<vector<pii>> dpMN(n, vector<pii>(logn + 1));
    vector<vector<pii>> dpMX(n, vector<pii>(logn + 1));

    FOR(i, 0, n)
    {
        int v;
        cin >> v;
        dpMN[i][0] = {v, i};
        dpMX[i][0] = {v, i};
    }
    FOR(j, 1, logn)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            dpMN[i][j] = min(dpMN[i][j - 1], dpMN[i + (1 << (j - 1))][j - 1]);
            dpMX[i][j] = max(dpMX[i][j - 1], dpMX[i + (1 << (j - 1))][j - 1]);
        }
    }

    auto queryMN = [&](int l, int r) {
        int j = log[r - l + 1];
        return min(dpMN[l][j], dpMN[r - (1 << j) + 1][j]);
    };

    auto queryMX = [&](int l, int r) {
        int j = log[r - l + 1];
        return max(dpMX[l][j], dpMX[r - (1 << j) + 1][j]);
    };

    // deb(queryMN(4, 5).F);
    // deb(queryMX(1, 5).F);

    FOR(i, 0, q)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;

        pii mn = queryMN(l, r);
        pii mx = queryMX(l, r);
        if (mn.F == x && mx.F == x)
        {
            cout << -1 << ENDL;
        }
        else
        {
            if (mx.F != x)
            {
                cout << mx.S + 1 << ENDL;
            }
            else
            {
                cout << mn.S + 1 << ENDL;
            }
        }
        // cout << l << " " << r << ENDL;
        // debp(mn.F, mn.S);
        // debp(mx.F, mx.S);
    }

    return 0;
}