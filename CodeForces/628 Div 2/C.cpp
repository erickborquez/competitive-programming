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
  int n;
  cin >> n;
  vector<vector<int>> t(n + 1);
  vector<pii> ed;
  FOR(i, 0, n - 1)
  {
    int from, to;
    cin >> from >> to;
    ed.pb({from, to});
    t[from].pb(to);
    t[to].pb(from);
  }
  vector<pii> leafs;
  FOR(i, 1, n + 1)
  {
    if (t[i].size() == 1)
    {
      // debp(i, t[i][0]);
      leafs.pb({i, t[i][0]});
    }
    if (leafs.size() == 3)
      break;
  }
  if (leafs.size() != 3)
    FOR(i, 0, n - 1)
    {
      cout << i << ENDL;
    }
  else
  {
    int count = 3;
    int leaftCount = 0;
    for (auto e : ed)
    {
      bool isLeaf = false;
      // debp(e.F, e.S);
      for (auto l : leafs)
      {
        if (l == e || (l.S == e.F && l.F == e.S))
        {
          isLeaf = true;
          break;
        }
      }
      if (isLeaf)
        cout << leaftCount++ << ENDL;
      else
        cout << count++ << ENDL;
    }
  }

  return 0;
}