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

const lli N = 1e6;

int main()
{
    IO;
    string s;
    cin >> s;
    int n = s.size();
    lli dp[N];
    dp[0] = 0;
    FOR(i, 1, n)
    {
        dp[i] = dp[i - 1];
        if (s[i] == 'v' && s[i - 1] == 'v')
            dp[i]++;
    }
    lli ans = 0;
    FOR(i, 0, n)
    {
        if (s[i] == 'o')
        {
            lli left = dp[i];
            lli right = dp[n - 1] - left;
            ans += left * right;
        }
    }
    cout << ans << ENDL;

    return 0;
}