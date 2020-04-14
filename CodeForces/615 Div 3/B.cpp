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
    int n;
    cin >> n;
    vector<pii> box(n);
    FOR(i, 0, n)
    {
      cin >> box[i].F >> box[i].S;
    }
    sort(ALL(box));
    string s = "";
    bool ok = true;
    int x = 0, y = 0;
    for (auto b : box)
    {
      if (b.S < y)
      {
        ok = false;
        break;
      }

      FOR(i, x, b.F)
      s += 'R';
      FOR(i, y, b.S)
      s += 'U';
      x = b.F;
      y = b.S;
    }
    if (ok)
    {
      cout << "YES" << ENDL;
      cout << s << ENDL;
    }
    else
    {
      cout << "NO" << ENDL;
    }
  }
  return 0;
}