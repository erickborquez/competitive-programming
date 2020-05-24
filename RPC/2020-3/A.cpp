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

int main()
{
  IO;
  long double n, m;
  cin >> n >> m;
  vector<vector<vector<long double>>> dp(n + 1, vector<vector<long double>>(n + 1, vector<long double>(n + 1, 1.0)));
  vector<long double> ans(n + 1, 1.0);
  FOR(i, 0, m)
  {
    int a, b;
    long double p;
    cin >> a >> b >> p;
    vector<vector<long double>> damage = dp[b];
    long double prob = 1.0;
    FOR(i, 1, n + 1)
    {
      prob *= damage[i][a];
    }
    ans[b] -= ans[b] * prob * p;

    FOR(i, 1, n + 1)
    {
      if (i != b)
      {
        dp[i][a][b] *= 1.0 - p;
      }
    }
  }
  FOR(i, 1, n + 1)
  {
    cout << fixed << setprecision(12) << ans[i] << ENDL;
  }
  return 0;
}
/*

eso que significa jajaja
0.77-(0.77*0.99*0.01)

////
2 3
1 2 0.23
2 1 0.99
1 2 0.99

0.2377000000
0.7623770000
*/