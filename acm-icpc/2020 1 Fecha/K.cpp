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
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

const int N = 110;
vector<vector<int>> g;
bool vis[N];
vector<int> parent(N, -1);
bool road[N][N];
int n, m, k;

vector<int> ans(N, 0);

void bfs(int u, bool force = false)
{
  vis[u] = true;
  if (!force)
    for (auto v : g[u])
    {
      if (!vis[v])
      {
        vis[v] = true;
        road[u][v] = true;
        road[v][u] = true;
        ans[u]++;
        ans[v]++;
        k--;
        parent[v] = parent[u];
      }
    }
  else
  {
    for (auto v : g[u])
    {
      if (k <= 0)
        break;
      if (!road[u][v])
      {
        parent[u] = min(parent[u], parent[v]);
        parent[v] = parent[u];
        road[u][v] = true;
        road[v][u] = true;
        ans[u]++;
        ans[v]++;
        k--;
      }
    }
  }
}

int main()
{
  IO;
  cin >> n >> m >> k;
  g = vector<vector<int>>(n + 1);
  FOR(i, 0, m)
  {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  if (k > m)
  {
    cout << "Impossible" << ENDL;
    return 0;
  }
  FOR(i, 1, n + 1)
  sort(ALL(g[i]));

  FOR(i, 1, n + 1)
  {
    if (!vis[i])
    {
      parent[i] = i;
      bfs(i);
    }
  }
  bool connected = false;
  FOR(i, 1, n + 1)
  {
    if (parent[i] != 1)
    {
      cout << "Impossible" << ENDL;
      return 0;
    }
  }

  for (int i = 1; i <= n && k > 0; i++)
    bfs(i, true);
  FOR(i, 1, n + 1)
  cout << ans[i] << " ";

  return 0;
}