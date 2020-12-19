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

int t, p;
int en[10], dif[110], points[110];
int dp[10][110][110];

int solve(int u, int e, int k)
{
    if (u >= t || k >= p || e < 0)
        return 0;
    if (dp[u][e][k] != -1)
        return dp[u][e][k];

    int ans = 0;
    FOR(i, k, p)
    if (e >= dif[i])
    {
        ans = max(ans, points[i] + solve(u, e - dif[i], i + 1));
    }
    dp[u][e][k] = ans;
    return ans;
}

int main()
{
    IO;
    cin >> t >> p;
    FOR(i, 0, t)
    cin >> en[i];

    FOR(i, 0, p)
    cin >> dif[i];
    FOR(i, 0, p)
    cin >> points[i];

    FOR(i, 0, 10)
    {
        FOR(j, 0, 110)
        {
            FOR(k, 0, 110)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = 0;
    FOR(i, 0, t)
    ans = max(ans, solve(i, en[i], 0));
    cout << ans << ENDL;

    return 0;
}