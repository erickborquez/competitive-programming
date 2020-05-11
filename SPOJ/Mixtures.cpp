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

#define INF 1000000000000000
#define MOD 100
using namespace std;

vector<vector<lli>> dp, sum;
vector<lli> m;

lli mcm(lli l, lli r)
{
  lli ans = dp[l][r];
  if (ans != -1)
    return ans;
  if (l == r)
  {
    ans = 0;
    sum[l][r] = m[l];
  }
  else if ((l + 1) == r)
  {
    ans = m[l] * m[r];
    sum[l][r] = (m[l] + m[r]) % MOD;
  }
  else
  {
    ans = INF;
    FOR(k, l, r)
    {
      lli newAns = mcm(l, k) + mcm(k + 1, r) + sum[l][k] * sum[k + 1][r];
      if (newAns < ans)
      {
        ans = newAns;
        sum[l][r] = (sum[l][k] + sum[k + 1][r]) % MOD;
      }
    }
  }
  dp[l][r] = ans;
  return ans;
}

int main()
{
  // IO;
  lli n;
  while (cin >> n)
  {

    m = vector<lli>(200);
    dp = vector<vector<lli>>(200, vector<lli>(200, -1));
    sum = vector<vector<lli>>(200, vector<lli>(200, -1));
    FOR(i, 0, n)
    cin >> m[i];
    if (n == 1)
    {
      cout << 0 << ENDL;
      continue;
    }
    cout << mcm(0, n - 1) << ENDL;
  }
  return 0;
}
