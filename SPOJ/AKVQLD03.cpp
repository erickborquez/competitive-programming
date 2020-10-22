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
    cin >> n >> q;
    vector<int> fenwick(n + 1, 0);

    auto update = [&](int i, int val) {
        for (; i < n; i += (i & -i))
        {
            fenwick[i] += val;
        }
    };

    auto query = [&](int i) {
        int val = 0;
        for (; i > 0; i -= (i & -i))
            val += fenwick[i];
        return val;
    };

    auto rangeQuery = [&](int l, int r) {
        if (l == 0)
            return query(r);
        return query(r) - query(l - 1);
    };

    while (q--)
    {
        string action;
        int l, r;
        cin >> action >> l >> r;
        if (action == "find")
            cout << rangeQuery(l, r) << ENDL;
        else
            update(l, r);
    }

    return 0;
}