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
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        map<int, vector<int>> gangs;
        FOR(i, 0, n)
        {
            int g;
            cin >> g;
            gangs[g].pb(i + 1);
        }
        if (gangs.size() == 1)
        {
            cout << "NO" << ENDL;
        }
        else
        {
            vector<pair<int, vector<int>>> g;
            for (auto p : gangs)
            {
                g.pb(p);
            }
            cout << "YES" << ENDL;
            FOR(i, 0, g.size())
            {
                int u, v;
                if (i == g.size() - 1)
                {
                    u = 0;
                    v = 1;
                }
                else
                {
                    u = i + 1;
                    v = 0;
                }
                for (; v < g[i].S.size(); v++)
                {
                    cout << g[i].S[v] << " " << g[u].S[0] << ENDL;
                }
            }
        }
    }
    return 0;
}