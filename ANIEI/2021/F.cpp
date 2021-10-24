#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
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

int n, h;
vector<int> graph;

int getAncestor(int u)
{
  if (graph[u] == -1)
    graph[u] = u;

  if (graph[u] == u)
    return u;

  graph[u] = getAncestor(graph[u]);

  return graph[u];
}

void join(int u, int v)
{
  if (u == v)
    return;

  int to = getAncestor(v);
  int from = getAncestor(u);
  if (from != u)
  {
    join(from, to);
  }
  graph[u] = to;
}

int main()
{
  IO;
  cin >> n >> h;
  graph = vector<int>(n + 1, -1);
  while (h--)
  {
    int u, v;
    cin >> u >> v;
    join(u, v);
  }

  set<int> uniques;
  int alone = 0;
  FOR(i, 1, n + 1)
  {
    if (graph[i] == -1)
      alone++;
    else
    {
      int frat = getAncestor(graph[i]);
      // debp(i, frat);
      // deb(graph[i]);
      uniques.insert(frat);
    }
  }
  cout << uniques.size() << " " << alone << ENDL;

  return 0;
}