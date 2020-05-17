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
#define INF 300000

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    vector<vector<int>> dp(s.size(), vector<int>(3, -1));
    FOR(i, 0, s.size())
    {
      if (i != 0)
        dp[i] = dp[i - 1];
      dp[i][s[i] - '1'] = i;
    }
    int best = INF;
    FOR(i, 0, s.size())
    {
      sort(ALL(dp[i]));
      if (dp[i][0] == -1)
        continue;
      best = min(best, dp[i][2] - dp[i][0]);
    }
    if (best == INF)
      cout << 0 << ENDL;
    else
      cout << best + 1 << ENDL;
  }
  return 0;
}