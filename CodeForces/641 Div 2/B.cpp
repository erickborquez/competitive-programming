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

#define MAX 100000

int n;
vector<int> dp;
vector<int> s;

void calculate(int index)
{
  int val = dp[index];
  FOR(i, 2, n + 1)
  {
    if (index * i > n)
      break;
    if (dp[index * i] < (val + 1) && s[index] < s[index * i])
      dp[index * i] = val + 1;
  }
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    dp = vector<int>(n + 1, 1);
    s = vector<int>(n + 1);
    FOR(i, 1, n + 1)
    cin >> s[i];
    FOR(i, 1, n + 1)
    calculate(i);
    int mx = -1;
    FOR(i, 1, n + 1)
    mx = max(mx, dp[i]);
    cout << mx << ENDL;
  }
  return 0;
}