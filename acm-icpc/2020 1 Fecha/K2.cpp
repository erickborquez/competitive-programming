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

const int N = 110;
vector<vector<int>> g(N);
vector<int> ans(N, 0);
bool vis[N];
bool road[N][N];

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    for (auto v : g[u])
    {
        dfs(v);
    }
}

int main()
{
    IO;
    struct Edge
    {
        int u, v;
        bool operator<(Edge const &other)
        {
            if (u == other.u)
                return v < other.v;
            return u < other.u;
        }
    };

    vector<Edge> edges;
    int n, m, k;
    cin >> n >> m >> k;
    FOR(i, 0, k)
    {
        Edge edge;
        cin >> edge.u >> edge.v;
        edges.pb(edge);
        g[edge.u].pb(edge.v);
        g[edge.v].pb(edge.u);
    }
    if (k > m)
    {
        cout << "Impossible" << ENDL;
        return 0;
    }
    dfs(1);
    FOR(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cout << "Impossible" << ENDL;
            return 0;
        }
    }

    vector<int> tree_id(n);
    vector<Edge> result;
    for (int i = 0; i < n; i++)
        tree_id[i] = i + 1;

    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (tree_id[e.u] != tree_id[e.v])
        {
            // deb("???");
            ans[e.u]++;
            ans[e.v]++;
            road[e.v][e.u] = true;
            road[e.u][e.v] = true;
            result.push_back(e);
            k--;
            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++)
            {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
    for (int u = 1; u <= n && k > 0; u++)
    {
        for (auto v : g[u])
        {
            if (!road[u][v])
            {
                k--;
                road[u][v] = true;
                road[v][u] = true;
                ans[v]++;
                ans[u]++;
            }
        }
    }
    FOR(i, 1, n + 1)
    {
        cout << ans[i] << " ";
    }

    return 0;
}