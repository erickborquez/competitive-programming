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

lli MOD = 1e9 + 7;

int n, l;
vector<vector<int>> v;
vector<bool> vis(2001, false);
vector<int> dp(2001, -1);

lli solve(int u)
{
  // deb(u);
  vis[u] = true;
  if (dp[u] != -1)
    return dp[u];
  if (u > l)
  {
    dp[u] = 1;
    return dp[u];
  }
  lli ans = 0;
  for (auto e : v[u])
  {
    ans = (ans + solve(e)) % MOD;
  }
  dp[u] = ans;
  return ans;
}

int main()
{
  IO;
  cin >> n >> l;
  v = vector<vector<int>>(l + 1);
  FOR(i, 1, l + 1)
  {
    int m, u;
    cin >> m;
    while (m--)
    {
      cin >> u;
      v[i].pb(u);
    }
  }
  lli ans = solve(1);
  lli visited = 0;
  FOR(i, l + 1, n + 1)
  {
    // deb(i);
    if (vis[i])
      visited++;
  }
  cout << ans << " " << visited << ENDL;

  return 0;
}