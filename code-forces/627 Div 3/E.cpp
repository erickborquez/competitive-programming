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
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> hours(n, 0);
  vector<vector<int>> good(n + 1, vector<int>(h, 0));
  FOR(i, 0, n)
  {
    cin >> hours[i];
  }
  FORN(i, n, 0)
  {
    FOR(j, 0, h)
    {
      int left = (j + hours[i] - 1) % h;
      int right = (j + hours[i]) % h;
      int goodLeft = good[i + 1][left];
      int goodRight = good[i + 1][right];
      if (left >= l && left <= r)
        goodLeft++;
      if (right >= l && right <= r)
        goodRight++;
      good[i][j] = max(goodLeft, goodRight);
    }
  }
  // FOR(i, 0, n)
  // {
  //   FOR(j, 0, h)
  //   {
  //     cout << j << ":" << good[i][j] << " ";
  //   }
  //   cout << ENDL;
  // }
  cout << good[0][0] << ENDL;

  return 0;
}