#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
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

const lli MAX = 3LL * 1e6 + 100;
lli a, t;
lli dp[MAX];
vector<vector<pll> > act;

void initialize()
{
  // initialize dp
  FOR(i, 0, MAX)
  dp[i] = -1;

  act = vector<vector<pll> >(MAX, vector<pll>());
}

lli solve()
{
  dp[0] = 0;
  lli best = 0;
  FOR(i, 0, t + 1)
  {
    if (i > 0)
      dp[i] = max(dp[i - 1], dp[i]);

    for (pll u : act[i])
    {
      lli endTime = u.S + i;
      dp[endTime] = max(dp[endTime], dp[i] + u.F);
      best = max(best, dp[endTime]);
    }
  }
  cout << best << ENDL;
}

int main()
{
  IO;
  cin >> a >> t;
  initialize();
  FOR(i, 0, a)
  {
    lli hap, duration, times;
    cin >> hap >> duration >> times;
    FOR(j, 0, times)
    {
      lli u;
      cin >> u;
      act[u].pb(make_pair(hap, duration));
    }
  }
  solve();
  return 0;
}