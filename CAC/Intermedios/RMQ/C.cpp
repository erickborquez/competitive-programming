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
    string s;
    int n, q;
    cin >> s >> q;
    n = s.size();

    vector<vector<int>> fenwick(n + 1, vector<int>(50, 0));

    auto update = [&](int i, char val, bool ini = false) {
        char org = s[i - 1] - 'a';
        for (int j = i; j <= n; j += (j & -j))
        {
            (!ini && fenwick[j][org]--);
            fenwick[j][val - 'a']++;
        }
        s[i - 1] = val;
    };

    auto query = [&](int i) {
        vector<int> ans(30, 0);
        for (; i > 0; i -= (i & -i))
        {
            FOR(j, 0, 30)
            {
                ans[j] += fenwick[i][j];
            }
        }
        return ans;
    };

    auto rangeQuery = [&](int l, int r) {
        auto right = query(r);
        int ans = 0;
        if (l == 1)
            FOR(i, 0, 30)
            {
                if (right[i] > 0)
                    ans++;
            }
        else
        {
            auto left = query(l - 1);
            FOR(i, 0, 30)
            {
                if (right[i] > left[i])
                    ans++;
            }
        }
        return ans;
    };
    FOR(i, 0, n)
    {
        update(i + 1, s[i], true);
    }

    FOR(i, 0, q)
    {
        char c;
        int k, l, r;
        cin >> k;
        if (k == 2)
        {
            cin >> l >> r;
            cout << rangeQuery(l, r) << ENDL;
        }
        else
        {
            cin >> l >> c;
            update(l, c);
        }
    }

    return 0;
}