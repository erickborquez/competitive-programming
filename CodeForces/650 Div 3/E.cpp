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

int n, k;
vector<int> dp;
vector<int> v;

int solve(int u)
{
  // deb(u);
  int ans = 0;
  if (dp[u] != -1)
    return dp[u];
  FOR(i, 1, v[0] + 1)
  {
    // deb(i);
    int rest = u;
    for (auto e : v)
    {
      rest -= e / i;
      // deb(rest);
    }
    if (rest > 0)
      break;
    ans = u * i;
  }
  dp[u] = ans;
  return ans;
}

int main()
{
  IO;
  int tc;
  cin >> tc;
  while (tc--)
  {
    string s;
    cin >> n >> k >> s;
    dp = vector<int>(k + 1, -1);
    v = vector<int>(26, 0);
    FOR(i, 0, n)
    {
      v[s[i] - 'a']++;
    }
    sort(v.rbegin(), v.rend());
    // for (auto e : v)
    // {
    //   cout << e << " ";
    // }
    // cout << ENDL;
    int ans = -1;
    FOR(i, 1, k + 1)
    {
      if (k % i == 0)
      {
        ans = max(ans, solve(i));
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}