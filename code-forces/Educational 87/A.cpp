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
    lli a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b)
    {
      lli after = c - d;
      if (after <= 0)
      {
        cout << -1 << ENDL;
      }
      else
      {
        lli res = a - b;
        lli times = res / after;
        // deb(res);
        // deb(times);
        if (res % after != 0)
          times++;
        lli total = b + c * times;
        cout << total << ENDL;
      }
    }
    else
    {
      cout << b << ENDL;
    }
  }
  return 0;
}