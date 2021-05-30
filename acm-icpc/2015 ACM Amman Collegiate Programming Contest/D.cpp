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
#define FORN(i, a, n) for (int i = (a - 1); i >= (n); --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;
#define INF 1000;

int n, k;
string s;
vector<int> v;
vector<int> dp;

int solve(int cut)
{
  if (dp[cut] != 0)
    return dp[cut];
  int ans = 0;
  if (cut == n - 1)
    ans = 0;
  else if (cut + v[cut] >= n - 1 && v[cut] <= k)
    ans = 0;
  else if (v[cut] == 0)
  {
    ans = solve(cut + 1) + 1;
    // cout << "PASS" << ENDL;
  }
  else
  {
    ans = INF;
    FOR(i, 1, min(k, v[cut] + 1))
    {
      ans = min(ans, solve(cut + i) + 1);
    }
  }
  // debp(cut, ans);
  dp[cut] = ans;
  return ans;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k >> s;
    v = vector<int>(n, 0);
    dp = vector<int>(2000, 0);
    FORN(i, n - 1, 0)
    {
      if (s[i] == s[i + 1])
        v[i] = v[i + 1] + 1;
    }

    // cout << ENDL;
    // FOR(i, 0, n)
    // cout << v[i] << " ";
    // cout << ENDL;

    int best = INF;
    if (k == 1)
      best = n - 1;
    if (k >= n && v[0] > 0)
      best = 0;
    else
      FOR(i, 0, min(k, v[0] + 1))
      {
        // debp(i, solve(i));
        best = min(best, solve(i));
      }
    cout << best << ENDL;
  }
  return 0;
}

/*
  4
  6 3
  111000
  5 2
  11010
  3 3
  110
  3 3
  101
  */