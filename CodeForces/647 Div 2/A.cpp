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
  int t;
  cin >> t;
  while (t--)
  {
    lli a, b;
    cin >> a >> b;
    int steps = 0;
    bool ok = false;
    if (a == b)
    {
      ok = true;
    }
    else if (a > b)
    {
      while (a > b)
      {
        steps++;
        b = b << 1;
      }
      if (a == b)
        ok = true;
    }
    else
    {
      while (b > a)
      {
        if (b % 2 == 1)
          break;
        b = b >> 1;
        steps++;
      }
      if (a == b)
        ok = true;
    }
    if (ok)
    {
      lli ans = steps / 3;
      steps %= 3;
      ans += steps / 2 + steps % 2;
      cout << ans << ENDL;
    }
    else
      cout << -1 << ENDL;
  }
  return 0;
}