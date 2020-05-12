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

#define MOD 1000000007

int n;
vector<vector<int>> dp;
lli dfs(int pos, int mask)
{
  if (pos == n)
    return 1;
  lli ans = dp[pos][mask];
  if (ans != -1)
    return ans;
  ans = 0;
  if (pos == 0)
  {
    FOR(i, 2, 10)
    {
      lli nmask = 0;
      FOR(k, 2, 10)
      {
        if (k % i == 0)
        {
          nmask = nmask | (1 << k);
        }
      }
      ans = (ans + dfs(pos + 1, nmask)) % MOD;
    }
  }
  else
  {
    ans = dfs(pos + 1, mask);
    FOR(i, 2, 10)
    {
      if (mask & (1 << i))
      {
        lli nmask = mask;
        FOR(k, 2, 10)
        {
          if (k % i == 0)
          {
            nmask = nmask | (1 << k);
          }
        }
        ans = (ans + dfs(pos + 1, nmask)) % MOD;
      }
    }
  }
  dp[pos][mask] = ans;
  return ans;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    dp = vector<vector<int>>(n, vector<int>(1 << 10, -1));
    lli ans = 0;
    if (n == 1)
    {
      cout << 9 << ENDL;
      continue;
    }
    cout << dfs(0, 0) + 1 << ENDL;
  }
  return 0;
}