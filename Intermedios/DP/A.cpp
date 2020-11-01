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

const lli N = 1e5 + 10;
lli dp[2][N];
lli h[2][N];

int n;
void calc(int u, int v)
{
    // debp(u, v);
    int k = (u + 1) % 2;
    FOR(i, v + 1, n)
    {
        if (dp[u][v] + h[k][i] > dp[k][i])
        {
            dp[k][i] = dp[u][v] + h[k][i];
        }
        else
            break;
    }
}

int main()
{
    IO;
    cin >> n;
    vector<lli> top(n), bot(n);
    FOR(i, 0, n)
    {
        cin >> top[i];
    }
    FOR(i, 0, n)
    {
        cin >> bot[i];
    }
    lli t = 0, b = 0;
    FOR(i, 0, n)
    {
        lli newT = max(t, b + top[i]);
        lli newB = max(b, t + bot[i]);
        t = newT;
        b = newB;
        // debp(b, t);
    }
    cout << max(t, b) << ENDL;

    return 0;
}