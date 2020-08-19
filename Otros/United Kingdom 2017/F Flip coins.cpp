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

#define pld pair<long double, long double>

pld dp[401][401];
lli n, k;
lli acc = 0, times = 0;

pld solve(lli u, int s)
{
  if (dp[u][s].F != -1)
  {
    return dp[u][s];
  }
  pld ans;
  if (s == k)
    ans = {1, u};
  else if (u == n)
  {
    pld left = solve(u - 1, s + 1), right = solve(u, s + 1);
    ans = {left.F + right.F, left.S + right.S};
  }
  else
  {
    pld left = solve(u, s + 1), right = solve(u + 1, s + 1);
    ans = {left.F + right.F, left.S + right.S};
  }

  dp[u][s] = ans;
  return ans;
}

int main()
{
  IO;
  cin >> n >> k;
  FOR(i, 0, 401)
  FOR(j, 0, 401)
  dp[i][j] = {-1, -1};
  pld ans = solve(0, 0);
  cout << setprecision(10) << fixed << ans.S / ans.F << ENDL;

  return 0;
}