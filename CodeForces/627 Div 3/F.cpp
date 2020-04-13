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

vector<int> colors;
vector<int> best;
vector<vector<int>> graph;
vector<bool> visited;

void dfsUp(int node, int parent)
{
  visited[node] = true;

  if (node != parent)
  {
    if (best[parent] > best[node])
    {
      if (best[node] < 0)
      {
        best[node] = best[parent] - 1;
      }
      else
      {
        best[node] = best[parent];
      }
    }
  }

  for (auto v : graph[node])
  {
    if (!visited[v])
    {
      visited[v] = true;
      dfsUp(v, node);
    }
  }
}
void dfsDown(int node)
{
  visited[node] = true;
  int b;
  if (colors[node] == 1)
    b = 1;
  else
    b = -1;
  for (auto v : graph[node])
  {
    if (!visited[v])
    {
      visited[v] = true;
      dfsDown(v);
    }
    if (best[v] > 0)
      b += best[v];
  }
  best[node] = b;
}

int main()
{
  IO;
  int n;
  cin >> n;
  vector<int> colorsAux(n), bestAux(n, -1), parentAux(n);
  vector<vector<int>> graphAux(n);
  colors = colorsAux;
  best = bestAux;
  graph = graphAux;

  FOR(i, 0, n)
  {
    cin >> colors[i];
  }
  FOR(i, 0, n - 1)
  {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    graph[from].pb(to);
    graph[to].pb(from);
  }
  visited = vector<bool>(n, false);
  for (int i(0); i < n; i++)
  {
    if (graph[i].size() == 1)
    {
      dfsDown(i);
      visited = vector<bool>(n, false);
      dfsUp(i, i);
      break;
    }
  }

  FOR(i, 0, n)
  {
    cout << best[i] << " ";
  }
  return 0;
}