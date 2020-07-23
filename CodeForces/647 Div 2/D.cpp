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

int main()
{
  IO;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<int> nodes(n + 1);
  vector<pii> v(n + 1, {0, 0});
  FOR(i, 0, m)
  {
    int from, to;
    cin >> from >> to;
    g[from].pb(to);
    g[to].pb(from);
  }
  FOR(i, 1, n + 1)
  {
    int aux;
    cin >> aux;
    v[i] = {aux, i};
  }

  bool ok = true;

  FOR(i, 1, n + 1)
  {
    // deb(i);
    int val = v[i].F;
    vector<bool> vb(val, false);
    for (auto u : g[i])
    {
      if (v[u].F > val)
        continue;
      if (v[u].F == val)
      {
        ok = false;
        break;
      }
      vb[v[u].F] = true;
    }
    bool flag = true;
    FOR(j, 1, val)
    {
      if (!vb[j])
      {
        flag = false;
        break;
      }
    }
    if (!flag)
    {
      ok = false;
      break;
    }
  }

  sort(ALL(v));

  if (ok)
  {
    FOR(i, 1, n + 1)
    {
      cout << v[i].S << " ";
    }
  }
  else
  {
    cout << "-1" << ENDL;
  }

  return 0;
}