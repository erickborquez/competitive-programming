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
vector<int> coins;
int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    FOR(i, 0, n)
    cin >> v[i];
    sort(v.rbegin(), v.rend());
    vector<int> dp(2000, 0);
    FOR(i, 0, n)
    {
      int coin = v[i];
      for (int j = k - 1; j >= 0; j--)
      {
        if (dp[j] != 0)
          dp[j + coin] = max(dp[j + coin], dp[j] + 1);
      }
      dp[coin] = max(dp[coin], 1);
    }

    int mx = 0;
    FOR(i, k, k + v[0])
    {
      // deb(dp[i]);
      mx = max(mx, dp[i]);
    }
    cout << mx << ENDL;
  }
  return 0;
}

/*
2
5 9
4 1 3 5 4
7 37
7 5 8 8 5 10 4
*/