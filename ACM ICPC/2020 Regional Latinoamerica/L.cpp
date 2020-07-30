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
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  vector<vector<int>> v(n, vector<int>(m, 1));
  FOR(i, 0, n)
  {
    cin >> mp[i];
    FOR(j, 0, m)
    {
      if (j > 0 && mp[i][j] == mp[i][j - 1])
      {
        v[i][j] = v[i][j - 1] + 1;
      }
      // cout << v[i][j] << " ";
    }
    // cout << ENDL;
  }
  int ans = 1;

  FOR(i, 0, n)
  {
    FOR(j, 0, m)
    {
      int down = min(v[i][j], n - i);
      // debp(i, j);
      // deb(down);
      if (down > ans)
      {
        // debp(i, j);
        // deb(down);
        FOR(k, i + 1, min(n, i + down))
        {
          down = min(down, v[k][j]);
        }
        ans = max(ans, down);
        // deb(ans);
      }
    }
  }
  cout << ans * ans << ENDL;
  return 0;
}