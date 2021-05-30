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
vector<int> childs;
priority_queue<int> pq;

int n, k;
int total = 0;

void dfs(int u, int h)
{
  visited[u] = true;
  childs[u] = graph[u].size() - 1;
  for (auto v : graph[u])
  {
    if (!visited[v])
    {
      dfs(v, h + 1);
      childs[u] += childs[v];
    }
  }
  pq.emplace(h - childs[u]);
}

int main()
{
  IO;
  cin >> n >> k;
  graph.resize(n + 1);
  visited = vector<bool>(n + 1, false);
  childs = vector<int>(n + 1, 0);

  FOR(i, 1, n)
  {
    int from, to;
    cin >> from >> to;
    graph[from].pb(to);
    graph[to].pb(from);
  }
  graph[1].pb(1);
  dfs(1, 0);
  lli total = 0;
  FOR(i, 0, k)
  {
    total += pq.top();
    pq.pop();
  }
  cout << total << ENDL;

  return 0;
}