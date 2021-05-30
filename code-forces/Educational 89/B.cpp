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
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, x, m;
    cin >> n >> x >> m;
    vector<pii> v(m);
    FOR(i, 0, m)
    {
      cin >> v[i].F >> v[i].S;
    }
    pii ans = {x, x};
    for (auto e : v)
    {
      if (e.S >= ans.S && e.F <= ans.S)
      {
        ans.F = min(ans.F, e.F);
        ans.S = max(ans.S, e.S);
      }
      else if (e.F <= ans.F && e.S >= ans.F)
      {
        ans.F = min(ans.F, e.F);
        ans.S = max(ans.S, e.S);
      }
    }
    // debp(ans.F, ans.S);
    cout << ans.S - ans.F + 1 << ENDL;
  }
  return 0;
}