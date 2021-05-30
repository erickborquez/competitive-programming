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

lli dp[1000000];
vector<lli> ps;

lli solve(lli u)
{
  if (u >= ps.size())
    return 0;
  if (dp[u] != -1)
    return dp[u];
  lli ans = ps[u];
  FOR(i, u + 1, ps.size())
  {
    ans = (ans + (ps[u] * solve(i)) % MOD) % MOD;
  }
  dp[u] = ans;
  return ans;
}

int main()
{
  IO;
  lli n;
  cin >> n;
  map<lli, lli> p;
  while (n--)
  {
    lli aux;
    cin >> aux;
    p[aux]++;
  }
  FOR(i, 0, p.size())
  {
    dp[i] = -1;
  }
  for (auto e : p)
  {
    ps.push_back(e.S);
  }
  lli ans = 0;
  FOR(i, 0, ps.size())
  ans = (ans + solve(i)) % MOD;
  cout << ans << ENDL;
  return 0;
}