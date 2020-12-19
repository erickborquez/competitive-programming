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
    lli n, g, p, total = 0, mn;
    cin >> n >> g;
    vector<lli> v(n);
    FOR(i, 0, n)
    {
        cin >> v[i];
        total += v[i];
    }
    mn = total * g / 100LL;
    lli amount = n;
    vector<pll> ans;
    FOR(i, 0, (1 << (n)))
    {
        lli pc = __builtin_popcountll(i);
        if (pc > amount)
            continue;
        lli acc = 0;
        FOR(k, 0, n)
        {
            if (i & (1 << k))
                acc += v[k];
        }
        if (acc >= mn)
        {
            if (amount > pc)
            {
                amount = pc;
                ans.erase(ans.begin(), ans.end());
            }
            ans.pb({acc, i});
        }
    }
    cout << amount << " " << ans.size() << ENDL;
    for (auto e : ans)
    {
        cout << e.F * 100LL / total << " ";
        vector<lli> nums;
        FOR(k, 0, n)
        {
            if (e.S & (1 << k))
                nums.pb(k + 1);
        }
        FOR(i, 0, nums.size() - 1)
        cout << nums[i] << " ";
        cout << nums[nums.size() - 1] << ENDL;
    }
    return 0;
}