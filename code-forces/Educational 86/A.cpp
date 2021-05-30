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
  int tc;
  cin >> tc;
  while (tc--)
  {
    lli x, y, a, b;
    cin >> x >> y >> a >> b;
    if (b > a * 2LL)
      b = a * 2LL;
    lli ans = 0;
    if (x > 0 && y > 0 || x < 0 && y < 0)
    {
      x = abs(x), y = abs(y);
      ans = b * (min(x, y)) + a * abs(x - y);
    }
    else
    {
      x = abs(x), y = abs(y);
      ans = a * (x + y);
    }
    cout << ans << ENDL;
  }
  return 0;
}