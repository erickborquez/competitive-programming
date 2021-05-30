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

vector<vector<int>> tree;

pii node = {-1, -1};
void dfs(int from, int dist, int parent)
{
  if (dist > node.F)
    node = make_pair(dist, from);
  for (auto n : tree[from])
  {
    if (parent == n)
      continue;
    dfs(n, dist + 1, from);
  }
}

int main()
{
  IO;
  int n;
  cin >> n;
  tree = vector<vector<int>>(n);
  FOR(i, 0, n - 1)
  {
    int from, to;
    cin >> from >> to;
    tree[from].pb(to);
    tree[to].pb(from);
  }
  dfs(0, 0, -1);
  // deb(node.S);
  dfs(node.S, 0, -1);
  // deb(node.S);
  cout << node.F << ENDL;

  return 0;
}