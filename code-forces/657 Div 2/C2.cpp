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
    lli n, m;
    cin >> n >> m;
    pii best = {-1, -1};
    vector<lli> v(m);
    FOR(i, 0, m)
    {
      lli a, b;
      cin >> a >> b;
      v[i] = a;
      lli bestVal = best.F + best.S * (n - 1);
      lli val;
      if (a >= b)
      {
        lli val = b * n;
        if (val > bestVal)
          best = {b, b};
      }
      else
      {
        lli val = a + b * (n - 1);
        if (val > bestVal)
          best = {a, b};
      }
    }
    sort(v.rbegin(), v.rend());

    lli ans = 0;
    for (auto e : v)
    {
      lli val = best.F + best.S * (n - 1);
      if (e * n > val)
      {
        ans += e;
      }
      else
        break;
      n--;
    }
    if (n > 0)
      ans += best.F + best.S * (n - 1);

    cout << ans << ENDL;
  }
  return 0;
}