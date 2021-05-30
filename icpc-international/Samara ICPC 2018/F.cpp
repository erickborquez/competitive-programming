#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
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

int main()
{
  IO;
  int n;
  cin >> n;
  vector<vector<int>> parents(n);
  vector<pii> sz(n);
  vector<vector<int>> ans(n);
  FOR(i, 0, n)
  {
    int s;
    cin >> s;
    sz[i] = {s, i};
    while (s--)
    {
      int u;
      cin >> u;
      parents[i].pb(u - 1);
    }
  }
  sort(ALL(sz));
  if (sz[0].F != 0)
  {
    cout << "NO" << ENDL;
    return 0;
  }

  FOR(u, 0, n)
  {
    if (parents[u].size() == 0)
      continue;
    int h = parents[u].size();
    vector<int> prtH(h, -1);
    for (auto p : parents[u])
    {
      // debp(u, p);
      int ph = parents[p].size();
      // debp(ph, prtH[ph]);
      if (ph >= h || prtH[ph] != -1)
      {
        cout << "NO" << ENDL;
        return false;
      }
      prtH[ph] = p;
    }
    ans[prtH[prtH.size() - 1]].pb(u);
  }
  cout << "YES" << ENDL;
  FOR(u, 0, n)
  {
    for (auto v : ans[u])
    {
      cout << u + 1 << " " << v + 1 << ENDL;
    }
  }

  return 0;
}