#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;

#define lli long long
using namespace std;

bool visited[60];
vector<vector<lli>> g(60);

void dfs(lli u)
{
  if (visited[u])
    return;
  visited[u] = true;
  for (lli v : g[u])
  {
    dfs(v);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lli n, m, from, to;
  cin >> n >> m;
  while (m--)
  {
    cin >> from >> to;
    g[from].pb(to);
    g[to].pb(from);
  }
  lli islands = 0;
  for (lli i(1); i <= n; i++)
  {
    if (visited[i])
      continue;
    dfs(i);
    islands++;
  }
  lli total = 1;
  cout << (total << (n - islands)) << ENDL;

  return 0;
}