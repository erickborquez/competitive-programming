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

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, aux;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<bool> prince(n + 1, false), king(n + 1, false);
    FOR(i, 1, n + 1)
    {
      cin >> m;
      while (m--)
      {
        cin >> aux;
        g[i].pb(aux);
      }
    }
    FOR(i, 1, n + 1)
    {
      for (auto node : g[i])
      {
        if (prince[i])
          break;
        if (!king[node])
        {
          prince[i] = true;
          king[node] = true;
          // debp(i, node);
        }
      }
    }
    bool ok = true;
    FOR(i, 1, n + 1)
    {
      if (!prince[i])
      {
        ok = false;
        FOR(j, 1, n + 1)
        {
          if (!king[j])
          {
            cout << "IMPROVE" << ENDL;
            cout << i << " " << j << ENDL;
            break;
          }
        }
        break;
      }
    }
    if (ok)
    {
      cout << "OPTIMAL" << ENDL;
    }
  }
  return 0;
}