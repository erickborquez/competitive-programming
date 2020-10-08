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

lli INF = 1e18;
lli n, r, s, d;

vector<vector<pll>> g;

void dijkstra(lli s, vector<lli> &dis)
{
    dis.assign(n, INF);
    dis[s] = 0;
    priority_queue<pll> q;
    q.push({0, s});
    while (!q.empty())
    {
        auto u = q.top();
        q.pop();
        if (-u.F != dis[u.S])
            continue;
        for (auto v : g[u.S])
        {
            if (dis[v.F] > -u.F + v.S)
            {
                dis[v.F] = -u.F + v.S;
                q.push({-dis[v.F], v.F});
            }
        }
    }
}

int main()
{
    IO;
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> r >> s >> d;
        s--;
        d--;
        g = vector<vector<pll>>(n);
        FOR(i, 0, r)
        {
            lli from, to, t;
            cin >> from >> to >> t;
            from--;
            to--;
            g[from].pb({to, t + 15LL});
            g[to].pb({from, t + 15LL});
        }
        vector<lli> dis(n);
        dijkstra(s, dis);
        cout << dis[d] << ENDL;
    }
    return 0;
}