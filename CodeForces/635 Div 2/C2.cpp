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
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> hap;
vector<priority_queue<pii>> pqv;
vector<int> childs;

int n, k;
int total = 0;

void dfs(int u)
{
  visited[u] = true;
  childs[u] = graph[u].size() - 1;
  for (auto v : graph[u])
  {
    if (!visited[v])
    {
      dfs(v);
      childs[u] += childs[v];
      hap[u] += hap[v];
      pqv[u].emplace(make_pair(hap[v], v));
    }
  }
  hap[u] += childs[u];
  // cout << u << " children " << childs[u] << ENDL;
  // debp(u, hap[u]);
}

void getBest(int u)
{
  if (!pqv[u].empty())
  {
    pii top = pqv[u].top();
    pqv[u].pop();
    int v = top.S;
    getBest(v);
    if (top.F > 0)
    {
    }
  }
}

int main()
{
  IO;
  cin >> n >> k;
  graph.resize(n + 1);
  hap = vector<int>(n + 1, 0);
  visited = vector<bool>(n + 1, false);
  pqv.resize(n + 1);
  childs = vector<int>(n + 1, 0);

  FOR(i, 1, n)
  {
    int from, to;
    cin >> from >> to;
    graph[from].pb(to);
    graph[to].pb(from);
  }
  graph[1].pb(1);
  dfs(1);
  getBest(1);

  return 0;
}