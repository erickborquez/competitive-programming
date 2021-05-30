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

int dp[100000];
int m, k;
vector<int> v(k);

void calculate()
{
  FOR(i, 0, m + 1)
  {
    FOR(ptr, 0, k)
    {
      if (v[ptr] > i)
        break;
      if (dp[i - v[ptr]] > 0)
      {
        int res = dp[i - v[ptr]];
        dp[i] = (dp[i] + res) % MOD;
      }
    }
    // debp(i, dp[i]);
  }
}

int main()
{
  IO;
  cin >> m >> k;
  v = vector<int>(k);
  FOR(i, 0, k)
  cin >> v[i];
  sort(ALL(v));
  lli total = 0;
  dp[0] = 1;
  calculate();
  FOR(i, 0, m + 1)
  {
    total = (total + dp[i]) % MOD;
  }
  cout << total << ENDL;
  return 0;
}