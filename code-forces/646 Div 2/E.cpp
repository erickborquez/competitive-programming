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

vector<vector<lli>> t;
vector<pair<bool, bool>> c;
vector<lli> p;
lli total = 0;

pii dfs(lli u, lli parent)
{
  pii ans = {c[u].F && !c[u].S, !c[u].F && c[u].S};
  for (auto v : t[u])
  {
    if (v == parent)
      continue;
    pii ansV = dfs(v, u);
    ans.F += ansV.F;
    ans.S += ansV.S;
  }
  lli toShift = min(ans.F, ans.S);
  total += p[u] * 2 * toShift;
  ans.F -= toShift;
  ans.S -= toShift;
  return ans;
}

void getBestPrice(lli u, lli parent)
{
  // deb(u);
  for (auto v : t[u])
  {
    if (v != parent)
    {
      p[v] = min(p[v], p[u]);
      getBestPrice(v, u);
    }
  }
}

int main()
{
  IO;
  lli n;
  cin >> n;
  t = vector<vector<lli>>(n + 1);
  c = vector<pair<bool, bool>>(n + 1);
  p = vector<lli>(n + 1);

  FOR(i, 1, n + 1)
  {
    cin >> p[i] >> c[i].F >> c[i].S;
  }
  FOR(i, 0, n - 1)
  {
    lli from, to;
    cin >> from >> to;
    t[from].pb(to);
    t[to].pb(from);
  }

  getBestPrice(1, 1);
  pii ans = dfs(1, 1);
  if (ans.F > 0 || ans.S > 0)
    cout << -1 << ENDL;
  else
    cout << total << ENDL;
  return 0;
}