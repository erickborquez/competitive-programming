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
  int t;
  cin >> t;
  while (t--)
  {
    lli n, x;
    cin >> n >> x;
    lli total = 0, money = 0;
    vector<lli> a(n);
    vector<lli> p;
    FOR(i, 0, n)
    {
      cin >> a[i];
      if (a[i] >= x)
      {
        total++;
        money += a[i] - x;
      }
      else
      {
        p.pb(a[i]);
      }
    }
    sort(p.rbegin(), p.rend());
    for (auto d : p)
    {
      if (x - d > money)
        break;
      money -= x - d;
      total++;
    }
    cout << total << ENDL;
  }

  return 0;
}
