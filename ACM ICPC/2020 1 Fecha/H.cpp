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

int n;
vector<lli> dp(50, -1);
vector<lli> v(50, -1);

lli calc(int u)
{
    if (u >= n)
        return 0;
    if (dp[u] != -1)
        return dp[u];
    dp[u] = v[u] + max(calc(u + 2), calc(u + 3));
    return dp[u];
}

int main()
{
    IO;
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        FOR(i, 0, n)
        {
            cin >> v[i];
            dp[i] = -1;
        }
        cout << max(calc(0), calc(1)) << ENDL;
    }

    return 0;
}