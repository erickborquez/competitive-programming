#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
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
#define INF 1000000

int n, m;
vector<vector<pii>> g;

bool ok(int dist)
{
  // deb(dist);
  vector<bool> visited(n + 1, false);
  queue<int> bfs;
  bfs.emplace(1);
  while (!bfs.empty())
  {
    int u = bfs.front();
    bfs.pop();
    for (auto v : g[u])
    {
      if (!visited[v.F] && dist >= v.S)
      {
        visited[v.F] = true;
        bfs.emplace(v.F);
      }
    }
  }
  FOR(i, 1, n + 1)
  if (!visited[i])
    return false;
  // deb(dist);
  return true;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    g = vector<vector<pii>>(n + 1);
    FOR(i, 0, m)
    {
      int u, v, dist;
      cin >> u >> v >> dist;
      g[u].pb(make_pair(v, dist));
      g[v].pb(make_pair(u, dist));
    }
    int ans = 0;
    for (int i = INF; i > 0; i /= 2)
    {
      while (!ok(ans + i))
        ans += i;
    }
    cout << ans + 1 << ENDL;
  }
  return 0;
}

/*
2
6 7
1 2 3
2 3 3
3 1 5
3 4 4
4 5 4
4 6 3
6 5 5
3 3
1 2 1
2 3 2
3 1 3
*/