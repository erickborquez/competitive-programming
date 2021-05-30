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
    lli d, m;
    cin >> d >> m;
    lli ans = 1;
    lli p = 1;
    while (p <= d)
    {
      lli aum = min(p, d - p + 1) + 1;
      // deb(aum);
      // deb(aum);
      ans = (ans * aum) % m;
      if (p == 0)
        p++;
      else
        p *= 2LL;
    }
    if (ans == 0)
    {
      cout << m - 1 << ENDL;
    }
    else
      cout << ans - 1 << ENDL;
  }
  return 0;
}