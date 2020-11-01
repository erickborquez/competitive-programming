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
    while (true)
    {
        int k, n, f;
        cin >> k >> n;
        if (k == 0 && n == 0)
            break;
        vector<bool> v(k + 1, false);
        FOR(i, 0, n)
        {
            int val;
            cin >> val;
            for (int j = 1; j * val <= k; j++)
            {
                v[j * val] = true;
            }
        }

        int ans = 0;
        FOR(i, 1, k + 1)
        {
            if (v[i])
            {
                ans++;
            }
        }
        cout << ans << ENDL;
    }

    return 0;
}