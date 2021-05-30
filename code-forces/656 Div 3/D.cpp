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

int dp[20][20][20];
string s;

int solve(int left, int right, int k)
{
  if (dp[left][right][k] != -1)
    return dp[left][right][k];
  int ans = -1;
  if (left == right)
  {
    if (k != s[left])
      ans = 1;
    else
      ans = 0;
  }
  int mid = (left + right) / 2;
  ans = min(solve(left, mid, k + 1), solve(mid + 1, right, k + 1));
  dp[left][right][k] = ans;
  return ans;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n >> s;
    FOR(i, 0, 20)
    FOR(j, 0, 20)
    FOR(k, 0, 20)
    dp[i][j][k] = -1;
  }
  return 0;
}